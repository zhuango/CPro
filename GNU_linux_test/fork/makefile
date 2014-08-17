child: child.o
	gcc child.o -o child
child.o: child.c
	gcc -c child.c -o child.o

.PHONY:clean

clean:
	rm child *.o
