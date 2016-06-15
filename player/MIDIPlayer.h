#ifndef __MIDIPlayer_h__
#define __MIDIPlayer_h__

#include <stdint.h>
#include <stdlib.h>

class MIDIPlayer
{
public:
	enum
	{
		loop_mode_enable = 1 << 0,
		loop_mode_force  = 1 << 1
	};

	// zero variables
	MIDIPlayer();

	// close, unload
	virtual ~MIDIPlayer() {};

	// setup
	void setSampleRate(unsigned long rate);
    
    void setSoundFont(const char * path);
    
    void setPreset(uint32_t p);

	unsigned long Play(float * out, unsigned long count);
    
    void send_short(uint32_t e);
    void send_long(const uint8_t * e, size_t length);

protected:
	virtual void send_event(uint32_t b) {}
    virtual void send_sysex(const uint8_t * e, size_t length) {}
	virtual void render(float * out, unsigned long count) {}
    
    virtual void set_soundfont(const char * path) {}
    virtual void set_preset(uint32_t p) {}

	virtual void shutdown() {};
	virtual bool startup() {return false;}

	unsigned long      uSampleRate;
};

#endif

