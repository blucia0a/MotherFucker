#ifndef _LOOP_H_
#define _LOOP_H_
class loopPlayer;
class loop{
  
public:
  int id;/*wave to play*/

  tone **tones;

  int numTones;

  int currentTone; //index into tones[]

  loopPlayer *lp;
  
  pthread_t myThread;

  int age;

  loop(int ID, char *toneString, loopPlayer *lp);
  pthread_t run();
  static void *play(void *t);

};
#endif
