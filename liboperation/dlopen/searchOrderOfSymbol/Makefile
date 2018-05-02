default: libcaller.so
	gcc  main.c -o main.exe -L./ -lcaller -ldl
libcaller.so: caller.c libcallee.so
	gcc -shared -fPIC -o $@ $< -L./ -lcallee
libcallee.so: callee.c
	gcc -shared -fPIC -o $@ $<
clean:
	rm -f *.so *.o *.exe