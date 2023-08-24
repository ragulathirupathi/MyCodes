OBJFILES = main.o ll.o DeleteNodeEnd.o ReverseList.o

all : clean linkedlist

linkedlist: $(OBJFILES)
	gcc  -o $@ $(OBJFILES)

%.o: %.c
	gcc -c $< -o $@

clean:
	rm -rf *.o
	-@rm linkedlist
