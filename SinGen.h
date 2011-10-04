#ifndef _SIN_GEN_H_
#define _SIN_GEN_H_
/*
 *  SinGen.h
 *  Sin
 *
 *  Created by blucia0a on 8/25/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

//#include <Cocoa/Cocoa.h>
#include <CoreAudio/AudioHardware.h>
#include "Wave.h"
#include "SampleMixer.h"
#include "tones.h"

#define NUM_WAVES 100
//static float tones[] = {C3, D3, Dsharp3, F3, Fsharp3, Gsharp3, Asharp3, C4, D4}; //whole tones
static float tones[] = {C4}; //whole tones

class SinGen {

public:	
	
	Boolean		initialized;	// successful init?
	Boolean		soundPlaying;	// playing now?
	AudioDeviceID	device;		// the default device
	UInt32	deviceBufferSize;	// bufferSize returned by kAudioDevicePropertyBufferSize
	AudioStreamBasicDescription	deviceFormat;	// info about the default device
    double pan, panz;
	SampleMixer *mix;
	
	SinGen();
	void setup();
	bool sstart();
	bool sstop();
	void setAmplitudes(float *vals);
	
	Wave *waves[NUM_WAVES];
        Wave *getWave(int w);
	
	
};

#endif
