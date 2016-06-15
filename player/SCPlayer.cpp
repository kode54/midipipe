#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <vector>
#include <unistd.h>

#include "SCPlayer.h"

// YAY! OS X doesn't unload dylibs on dlclose, so we cache up to two sets of instances here

static pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;
static const unsigned int g_max_instances = 2;
static std::vector<unsigned int> g_instances_open;

static class SamplerContainer
{
    bool safe;
    SCCore * _sampler;
    
public:
    SamplerContainer()
    {
        _sampler = new SCCore[g_max_instances];
        safe = true;
    }
    
    ~SamplerContainer()
    {
        safe = false;
        delete [] _sampler;
    }
    
    int is_safe() const { return (int)safe; }
    
    SCCore& operator[] (int x) { return _sampler[x]; }
} g_sampler;

int SCPlayer::g_safe() { return g_sampler.is_safe(); }

SCPlayer::SCPlayer() : MIDIPlayer(), initialized(false), mode(sc_default), sccore_path(0)
{
    pthread_mutex_lock(&g_lock);
    while (g_instances_open.size() >= g_max_instances)
    {
        pthread_mutex_unlock(&g_lock);
        usleep(10000);
        pthread_mutex_lock(&g_lock);
    }
    unsigned int i;
    for (i = 0; i < g_max_instances; ++i)
    {
        if (std::find(g_instances_open.begin(), g_instances_open.end(), i) == g_instances_open.end())
            break;
    }
    g_instances_open.push_back(i);
    instance_id = i;
    sampler = &g_sampler[i];
    pthread_mutex_unlock(&g_lock);
}

SCPlayer::~SCPlayer()
{
	shutdown();
    if (sccore_path)
        free(sccore_path);
    if (sampler)
    {
        pthread_mutex_lock(&g_lock);
        auto it = std::find(g_instances_open.begin(), g_instances_open.end(), instance_id);
        it = g_instances_open.erase(it);
        pthread_mutex_unlock(&g_lock);
    }
}

static const uint8_t syx_reset_gm[] = { 0xF0, 0x7E, 0x7F, 0x09, 0x01, 0xF7 };
static const uint8_t syx_reset_gm2[] = { 0xF0, 0x7E, 0x7F, 0x09, 0x03, 0xF7 };
static const uint8_t syx_reset_gs[] = { 0xF0, 0x41, 0x10, 0x42, 0x12, 0x40, 0x00, 0x7F, 0x00, 0x41, 0xF7 };
static const uint8_t syx_reset_xg[] = { 0xF0, 0x43, 0x10, 0x4C, 0x00, 0x00, 0x7E, 0x00, 0xF7 };

static const uint8_t syx_gs_limit_bank_lsb[] = { 0xF0, 0x41, 0x10, 0x42, 0x12, 0x40, 0x41, 0x00, 0x03, 0x00, 0xF7 };

static bool syx_equal(const uint8_t * a, const uint8_t * b)
{
	while (*a != 0xF7 && *b != 0xF7 && *a == *b)
	{
		a++; b++;
	}
	
	return *a == *b;
}

static bool syx_is_reset(const uint8_t * data)
{
	return syx_equal(data, syx_reset_gm) || syx_equal(data, syx_reset_gm2) || syx_equal(data, syx_reset_gs) || syx_equal(data, syx_reset_xg);
}

void SCPlayer::send_sysex(const uint8_t * data)
{
	sampler->TG_LongMidiIn( data, 0 );
	if (syx_is_reset(data))
	{
		reset();
	}
}

void SCPlayer::send_gs(uint8_t * data)
{
	unsigned long i;
	unsigned char checksum = 0;
	for (i = 5; data[i+1] != 0xF7; ++i)
		checksum += data[i];
	checksum = (128 - checksum) & 127;
	data[i] = checksum;
	sampler->TG_LongMidiIn( data, 0 );
}

void SCPlayer::reset_sc()
{
	unsigned int i;
	uint8_t message[11];
	
	memcpy(message, syx_gs_limit_bank_lsb, 11);

	message[7] = 1;

	switch (mode)
	{
		default: break;
			
		case sc_sc55:
			message[8] = 1;
			break;
			
		case sc_sc88:
			message[8] = 2;
			break;
			
		case sc_sc88pro:
			message[8] = 3;
			break;
			
		case sc_sc8850:
			message[8] = 4;
			break;
	}
	
	for (i = 0x41; i <= 0x49; ++i)
	{
		message[6] = i;
		send_gs(message);
	}
	message[6] = 0x40;
	send_gs(message);
	for (i = 0x4A; i <= 0x4F; ++i)
	{
		message[6] = i;
		send_gs(message);
	}
}

void SCPlayer::reset()
{
	if (initialized)
	{
		switch (mode)
		{
			case sc_gm:
				sampler->TG_LongMidiIn( syx_reset_gm, 0 );
				break;
				
			case sc_gm2:
				sampler->TG_LongMidiIn( syx_reset_gm2, 0 );
				break;
				
			case sc_sc55:
			case sc_sc88:
			case sc_sc88pro:
			case sc_sc8850:
                sampler->TG_LongMidiIn( syx_reset_gs, 0 );
				reset_sc();
				break;
				
			case sc_xg:
				sampler->TG_LongMidiIn( syx_reset_xg, 0 );
                sampler->TG_ShortMidiIn( 0x7F00B9, 0 ); // fix drum channel
				break;
		}
	}
}

void SCPlayer::set_mode(sc_mode m)
{
	mode = m;
	reset();
}

void SCPlayer::set_sccore_path(const char *path)
{
    size_t len;
    if (sccore_path) free(sccore_path);
    len = strlen(path);
    sccore_path = (char *) malloc(len + 1);
    if (sccore_path)
        memcpy(sccore_path, path, len + 1);
}

void SCPlayer::send_event(uint32_t b)
{
    if (!initialized) return;
    sampler->TG_ShortMidiIn(b, 0);
}

void SCPlayer::send_sysex(const uint8_t *data, size_t length)
{
    (void)length;
    if (!initialized) return;
    send_sysex(data);
}

void SCPlayer::render(float * out, unsigned long count)
{
	memset(out, 0, count * sizeof(float) * 2);
    if (!initialized) return;
	while (count)
	{
		float buffer[2][4096];
		unsigned long todo = count > 4096 ? 4096 : count;
        memset(buffer[0], 0, todo * sizeof(float));
        memset(buffer[1], 0, todo * sizeof(float));
		
        sampler->TG_setInterruptThreadIdAtThisTime();
        sampler->TG_Process(buffer[0], buffer[1], (unsigned int) todo);

        for (unsigned long j = 0; j < todo; ++j)
        {
            out[j * 2 + 0] = buffer[0][j];
            out[j * 2 + 1] = buffer[1][j];
        }
		out += todo * 2;
		count -= todo;
	}
}

void SCPlayer::shutdown()
{
    if (initialized)
    {
        sampler->TG_flushMidi();
        sampler->TG_deactivate();
        initialized = false;
    }
}

bool SCPlayer::startup()
{
    if (initialized) return true;
    
    if (!sccore_path) return false;

    if (!sampler->TG_initialize)
    {
        if (!sampler->Load(sccore_path, true))
            return false;
		
        if (sampler->TG_initialize(0) < 0)
            return false;

        sampler->TG_activate(44100.0, 1024);
		sampler->TG_setMaxBlockSize(256);
		sampler->TG_setSampleRate((float)uSampleRate);
		sampler->TG_setSampleRate((float)uSampleRate);
		sampler->TG_setMaxBlockSize(4096);
	}
	
	initialized = true;
    
    reset();
    sampler->TG_flushMidi();
    
	return true;
}

unsigned int SCPlayer::get_playing_note_count()
{
	unsigned int total = 0;
	unsigned int i;

	if (!initialized)
		return 0;

	for (i = 0; i < 3; i++)
		total += sampler[i].TG_XPgetCurTotalRunningVoices();

	return total;
}
