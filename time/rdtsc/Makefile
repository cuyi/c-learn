objects = rdtscExample.o rdtsc.o

rdtscExmaple : $(objects)
	g++ -std=c++11 -o rdtscExample $(objects)
rdtscExample.o : rdtscExample.c rdtsc.h
	g++ -std=c++11 -c rdtscExample.c
rdtsc.o : rdtsc.c rdtsc.h
	g++ -std=c++11 -c rdtsc.c
clean :
	rm rdtscExample $(objects)
