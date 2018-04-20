all:out
out: testStub.c malloc.o
	gcc -I . -o testStub testStub.c malloc.o
malloc.o: malloc.c
	gcc -DCOMPILELINK -c malloc.c

.PHONY: clean
clean:
	@rm -rf testStub *.o