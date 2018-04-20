all:testStub
testStub: testStub.c malloc.o
	gcc -o testStub testStub.c

malloc.o: malloc.c
	gcc -DRUNTIME --shared -fPIC -o malloc.so malloc.c -ldl

.PHONY: clean run
run:
	export LD_PRELOAD="./malloc.so"; ./testStub; unset LD_PRELOAD
clean:
	@rm -rf testStub *.o