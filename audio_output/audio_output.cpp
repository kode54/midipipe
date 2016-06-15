#include "audio_output.h"

static const uint32_t DEFAULT_CHUNK_MS = 40;

CoreAudioStream::CoreAudioStream(callback useCb, void * userData, const uint32_t useSampleRate) :
	playerCallback(useCb), playerCallbackUserData(userData),
    sampleRate(useSampleRate), audioQueue(NULL)
{
	const uint32_t bufferSize = 256;
    const uint32_t audioLatencyFrames = sampleRate * DEFAULT_CHUNK_MS / 1000;
	bufferByteSize = bufferSize << 3;
	// Number of buffers should be ceil(audioLatencyFrames / bufferSize)
	numberOfBuffers = (audioLatencyFrames + bufferSize - 1) / bufferSize;
	buffers = new AudioQueueBufferRef[numberOfBuffers];
}

CoreAudioStream::~CoreAudioStream() {
	close();
	delete[] buffers;
}

void CoreAudioStream::renderOutputBuffer(void *userData, AudioQueueRef queue, AudioQueueBufferRef buffer) {
	CoreAudioStream *stream = (CoreAudioStream *)userData;
	if (queue == NULL) {
		// Priming the buffers, skip timestamp handling
		queue = stream->audioQueue;
	}
    
	uint frameCount = buffer->mAudioDataByteSize >> 3;
    stream->playerCallback(stream->playerCallbackUserData, (float*)buffer->mAudioData, frameCount);

	AudioQueueEnqueueBuffer(queue, buffer, 0, NULL);
}

bool CoreAudioStream::start() {
	if (audioQueue != NULL) {
		return true;
	}

	AudioStreamBasicDescription dataFormat = {static_cast<Float64>(sampleRate), kAudioFormatLinearPCM, kAudioFormatFlagIsFloat | kAudioFormatFlagIsPacked | kAudioFormatFlagsNativeEndian, 8, 1, 8, 2, 32, 0};
	OSStatus res = AudioQueueNewOutput(&dataFormat, renderOutputBuffer, this, NULL, NULL, 0, &audioQueue);
	if (res || audioQueue == NULL) {
		return false;
	}

	for (uint i = 0; i < numberOfBuffers; i++) {
		res = AudioQueueAllocateBuffer(audioQueue, bufferByteSize, buffers + i);
		if (res || buffers[i] == NULL) {
			res = AudioQueueDispose(audioQueue, true);
			audioQueue = NULL;
			return false;
		}
		buffers[i]->mAudioDataByteSize = bufferByteSize;
		// Prime the buffer allocated
		renderOutputBuffer(this, NULL, buffers[i]);
	}

	res = AudioQueueStart(audioQueue, NULL);
	if (res) {
		res = AudioQueueDispose(audioQueue, true);
		audioQueue = NULL;
		return false;
	}

	return true;
}

void CoreAudioStream::close() {
	if (audioQueue == NULL) return;
	OSStatus res = AudioQueueDispose(audioQueue, true);
	audioQueue = NULL;
}

void * cas_create(cas_callback cb, void * userData, const uint32_t sampleRate)
{
    void * cas = new CoreAudioStream(cb, userData, sampleRate);
    return cas;
}

void cas_delete(void * cas)
{
    delete (CoreAudioStream *) cas;
}

int cas_start(void * cas)
{
    return (int)((CoreAudioStream *)cas)->start();
}

void cas_close(void * cas)
{
    ((CoreAudioStream *)cas)->close();
}
