all: clean stack

clean:
	rm -rf *.o
	- rm stack

stack: main.o stack.o
	gcc -o stack main.o stack.o

%.o:%c
	gcc -o $@ -c %<
	 
