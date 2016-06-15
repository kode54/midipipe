#ifndef __SCPlayer_h__
#define __SCPlayer_h__

#include "MIDIPlayer.h"

#include "SCCore.h"

class SCPlayer : public MIDIPlayer
{
public:
    static int g_safe();
    
	// zero variables
	SCPlayer();

	// close, unload
	virtual ~SCPlayer();

	unsigned int get_playing_note_count();

	typedef enum
	{
		sc_gm = 0,
		sc_gm2,
		sc_sc55,
		sc_sc88,
		sc_sc88pro,
		sc_sc8850,
		sc_xg,
		sc_default = sc_sc55
	}
	sc_mode;
	
	void set_mode(sc_mode m);
    
    void set_sccore_path(const char * path);

protected:
	virtual void send_event(uint32_t b);
    virtual void send_sysex(const uint8_t *e, size_t length);
	virtual void render(float * out, unsigned long count);

	virtual void shutdown();
	virtual bool startup();
    
private:
    void send_sysex(const uint8_t * data);
	void send_gs(uint8_t * data);
	void reset_sc();

	void reset();

    unsigned int instance_id;
	bool initialized;
    SCCore * sampler;
	
	sc_mode mode;
    
    char * sccore_path;
};

#endif
