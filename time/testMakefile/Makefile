objects = main.o print.o
helloworld : $(objects)
	g++ -o helloworld $(objects)
mian.o : mian.cpp print.hpp
	g++ -c main.cpp
print.o : print.cpp print.hpp
	g++ -c print.cpp
clean :
	rm helloworld $(objects)
