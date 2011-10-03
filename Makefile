CSRCS=$(wildcard *.cpp)
COBJS=$(CSRCS:.cpp=.o)
OBJS=$(COBJS) $(MOBJS)

CFLAGS= -D_GNU_SOURCE=1 -D_THREAD_SAFE
LDFLAGS=-Wl,-framework,Cocoa 

%.o : %.cpp
	g++ $(CFLAGS) -Wno-deprecated -c -o $@ $<

all: $(OBJS)
	g++ $(LDFLAGS) -o MotherFucker $^ -framework CoreAudio

clean:
	-rm *.o
	-rm Chango
