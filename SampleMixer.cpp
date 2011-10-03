/*
 *  SampleMixer.cpp
 *  Sin
 *
 *  Created by blucia0a on 8/6/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "SampleMixer.h"
#include <stdio.h>
void SampleMixer::Mix(int numSources, SampleSource **srcs, float *out){
	
	out[0] = 0.0; //left
	out[1] = 0.0; //right
        int num = 0;
	for(int i = 0; i < numSources; i++){

            if(srcs[i]->active()){
              num++;
	      float o[2];
	      srcs[i]->getNextSample(o);
              out[0] = out[0] + o[0];// > 1.0 ? 0.9 : out[0] + o[0];
	      out[1] = out[1] + o[1];// > 1.0 ? 0.9 : out[1] + o[1];
            }

	}

        //fprintf(stderr,"%f\n",(float)num);
	out[0] /= (float)num;
	out[1] /= (float)num;

	
}
