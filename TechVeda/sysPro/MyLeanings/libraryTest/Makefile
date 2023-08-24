all: clean testlib 

clean:
	- rm -rf *.o
	- rm -rf *.so
	- rm -rf testlib

libtest.so: one.o two.o 
	gcc -shared -o $@ $?

%.o:%.c
	gcc -fPIC -c   $<


testlib: libtest.so
	gcc -c main.c
	gcc -o  testlib main.o -L . -ltest
	gcc -o runtimetest runtime.c
