#ifndef _LOOP_PLAYER_H_
#define _LOOP_PLAYER_H_
class loopPlayer{

public:
  SinGen *s;
  loopPlayer();
  void setFreq(int id,float newFreq);
  void setAmp(int id,float newAmp);
  void activate(int id);
  void deactivate(int id);

};
#endif
