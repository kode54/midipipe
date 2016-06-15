#ifndef __AUPlayer_h__
#define __AUPlayer_h__

#include "MIDIPlayer.h"

#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreAudio/CoreAudioTypes.h>

class AUPluginUI;

class AUPlayer : public MIDIPlayer
{
public:
	// zero variables
	AUPlayer();

	// close, unload
	virtual ~AUPlayer();

	// configuration
    /*void setFileSoundFont( const char * in );*/
    //void showDialog();
    
    typedef void (*callback)(OSType uSubType, OSType uManufacturer, const char * name);
    static void enumComponents(callback cbEnum);
    
    void setComponent(OSType uSubType, OSType uManufacturer);

protected:
	virtual void send_event(uint32_t b);
    virtual void send_sysex(const uint8_t * e, size_t length);
	virtual void render(float * out, unsigned long count);
    
    virtual void set_soundfont(const char * path);

	virtual void shutdown();
	virtual bool startup();
    
private:
    void loadSoundFont(const char * name);
    
    char *               sSoundFontName;
    /*std::string        sFileSoundFontName;*/

    AudioTimeStamp mTimeStamp;

    AudioUnit samplerUnit;
    
    bool samplerUIinitialized;
    AUPluginUI * samplerUI;
    
    AudioBufferList *bufferList;
    
    float *audioBuffer;
    
    OSType componentSubType, componentManufacturer;
};

#endif
