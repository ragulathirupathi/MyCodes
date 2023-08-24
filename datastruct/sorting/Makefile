OBJFILES = bubblesort.o insertion.o selection.o main.o

all : clean sorting

sorting: $(OBJFILES)
	gcc  -o $@ $(OBJFILES)

%.o: %.c
	gcc -c $< -o $@

clean:
	rm -rf *.o
	-@rm sorting
