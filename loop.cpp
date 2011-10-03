#include <pthread.h>
#include <unistd.h>
#include "SinGen.h"
#include "tone.h"
#include "tones.h"
#include "loop.h"
#include "loopPlayer.h"
loop::loop(int ID, char *toneString, loopPlayer *lp){

    this->id = ID;

    float amp = (float) rand()/RAND_MAX;
    this->numTones = 7;
    this->tones = new tone*[7]; 
    this->tones[0] = new tone(1000000,Fsharp5,amp);
    this->tones[1] = new tone(1000000,Csharp5,amp);
    this->tones[2] = new tone(1000000,D5,amp);
    this->tones[3] = new tone(1000000,B4,amp);
    this->tones[4] = new tone(1000000,B4,amp);
    this->tones[5] = new tone(1000000,Csharp5,amp);
    this->tones[6] = new tone(1000000,Fsharp4,amp);

    this->lp = lp;
    this->currentTone = 0;


  }
 
  pthread_t loop::run(){   

    for(int i = 0; i < 7; i++){
      this->tones[i]->duration += 200000;
    }
    pthread_create(&(this->myThread), NULL, loop::play, (void*)this);
    return this->myThread;

  }


  void *loop::play(void *t){

    /*this function should be used to create a thread to play the tone, and should be called with self*/
    loop *self = (loop *)t;

    /*This thread gets a pointer to the loopPlayer's event buffer, and when it should change its
      emitter's pitch or amp, it sends the loopPlayer an event*/
    self->lp->activate(self->id);
    int i;
    for(i = 0; i < self->numTones; i++){
 
      tone *thisT = self->tones[i];
      self->lp->setFreq(self->id,thisT->frequency); 
      self->lp->setAmp(self->id,thisT->amplitude); 
      usleep( thisT->duration ); 

    }
    self->lp->deactivate(self->id);
    
  }
