#include <assert.h>

#include "MIDIPlayer.h"

MIDIPlayer::MIDIPlayer()
{
	uSampleRate = 1000;
}

void MIDIPlayer::setSampleRate(unsigned long rate)
{
	uSampleRate = rate;

	shutdown();
}

void MIDIPlayer::setSoundFont(const char *path)
{
    set_soundfont(path);
}

void MIDIPlayer::setPreset(uint32_t p)
{
    set_preset(p);
}

unsigned long MIDIPlayer::Play(float * out, unsigned long count)
{
	if ( !startup() ) return 0;

    render( out, count );
    
    return count;
}

void MIDIPlayer::send_short(uint32_t e)
{
    send_event(e);
}

void MIDIPlayer::send_long(const uint8_t * e, size_t length)
{
    send_sysex(e, length);
}