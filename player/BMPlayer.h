#ifndef __BMPlayer_h__
#define __BMPlayer_h__

#include <vector>
#include <string>

#include "MIDIPlayer.h"

#include "../3rdparty/BASS/bassmidi.h"

class BMPlayer : public MIDIPlayer
{
public:
	// zero variables
	BMPlayer();

	// close, unload
	virtual ~BMPlayer();

private:
	virtual void send_event(uint32_t b);
    virtual void send_sysex(const uint8_t *e, size_t length);
    virtual void render(float * out, unsigned long count);

    virtual void set_soundfont( const char * in );

    virtual void shutdown();
	virtual bool startup();
    
    void compound_presets( std::vector<BASS_MIDI_FONTEX> & out, std::vector<BASS_MIDI_FONTEX> & in, std::vector<long> & channels );

	void reset_parameters();

    std::vector<HSOUNDFONT> _soundFonts;
    std::string        sSoundFontName;
    std::string        sFileSoundFontName;
    
	HSTREAM            _stream;

	bool               bSincInterpolation;

    bool               bank_lsb_overridden;
    uint8_t            bank_lsb_override[16];
};

#endif
