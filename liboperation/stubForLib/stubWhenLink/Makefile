all:out
out: testStub.c malloc.o
	gcc -Wl,--wrap,malloc -Wl,--wrap,free -o testStub testStub.c malloc.o
malloc.o: malloc.c
	gcc -DLINKTIME -c malloc.c

.PHONY: clean
clean:
	@rm -rf testStub *.o