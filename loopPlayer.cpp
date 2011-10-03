#include <pthread.h>
#include <unistd.h>
#include "SinGen.h"
#include "tone.h"
#include "tones.h"
#include "loop.h"
#include "loopPlayer.h"
loopPlayer::loopPlayer(){
  s = new SinGen();
  s->setup();
  bool res = s->sstart();
  if(!res){  fprintf(stderr,"start failed\n"); exit(1);}
}

void loopPlayer::activate(int id){  
  this->s->getWave(id)->activate();
}

void loopPlayer::deactivate(int id){  
  this->s->getWave(id)->deactivate();
}

void loopPlayer::setFreq(int id,float newFreq){
  this->s->getWave(id)->setFreqVal(newFreq);
}
  
void loopPlayer::setAmp(int id,float newAmp){
  this->s->getWave(id)->setAmpVal(newAmp);
}
