//System Headers
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>

#include "SinGen.h"

#include "tones.h"
#include "tone.h"
#include "loopPlayer.h"
#include "loop.h"

int main( int argc, char* args[] ){

  loopPlayer *lp = new loopPlayer();

  pthread_t thds[NUM_WAVES];
  loop *loops[NUM_WAVES];
  memset(loops,0,NUM_WAVES * sizeof(loop *));

  int curNumWaves = 2;
  loops[0] = new loop(0,NULL,lp);
  loops[1] = new loop(1,NULL,lp);
  fprintf(stderr,"starting loop 0\n");
  thds[1] = loops[1]->run();

  while(1){

    for(int i = curNumWaves-1; i >= 0; i--){

      fprintf(stderr,"joining loop %d\n",i);

      pthread_join(thds[i],NULL);

      usleep(rand() % 1000000);

      thds[i] = loops[i]->run();

      fprintf(stderr,"done joining loop %d\n",i);


    }
  

    if(curNumWaves < 100){
      if(loops[curNumWaves] == NULL){
        loops[curNumWaves] = new loop(curNumWaves,NULL,lp);
      }
      thds[curNumWaves] = loops[curNumWaves]->run();
      curNumWaves++;
      fprintf(stderr,"curnumwaves = %d\n",curNumWaves);
    }

  }

  return 0;
}


