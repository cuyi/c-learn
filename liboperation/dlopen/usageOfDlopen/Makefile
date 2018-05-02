# Try to complete this Makefile https://blog.csdn.net/shaoxiaohu1/article/details/46943417
all:testdlopen libcalculate.so

testdlopen: testdlopen.cpp
	g++ -rdynamic -o testdlopen testdlopen.cpp -ldl

libcalculate.so: calculated.cpp
	g++ -fPIC -shared calculate.cpp -o libcalculate.so

#.PHONY: clean
#clean:
#    @rm -rf testdlopen