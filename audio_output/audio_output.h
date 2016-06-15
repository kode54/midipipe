#ifndef _audio_output_h_
#define _audio_output_h_

#include <stdint.h>

#ifdef __cplusplus

#include <AudioToolbox/AudioQueue.h>

class CoreAudioStream {
public:
    typedef void (*callback)(void * context, float * samples, uint32_t count);

private:
	AudioQueueRef audioQueue;
	AudioQueueBufferRef *buffers;
	uint32_t numberOfBuffers;
	uint32_t bufferByteSize;
    
    uint32_t sampleRate;
    
    callback playerCallback;
    void * playerCallbackUserData;

	static void renderOutputBuffer(void *userData, AudioQueueRef queue, AudioQueueBufferRef buffer);

public:
    
	CoreAudioStream(callback cb, void * userData, const uint32_t sampleRate);
	~CoreAudioStream();
	bool start();
	void close();
};

extern "C" {

#endif

typedef void (*cas_callback)(void * context, float * samples, uint32_t count);
    
void * cas_create(cas_callback cb, void * userData, const uint32_t sampleRate);
void cas_delete(void * cas);

int cas_start(void * cas);
void cas_close(void * cas);

#ifdef __cplusplus
}
#endif

#endif
