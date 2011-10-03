#ifndef _TONE_H_
#define _TONE_H_
class tone{

public:
  unsigned long duration; //us
  float frequency;//tones.h
  float amplitude;//tones.h

  tone(unsigned long d,float f,float a);

};
#endif
