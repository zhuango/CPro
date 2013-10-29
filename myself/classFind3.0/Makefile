main:class.o main.o
	gcc main.o class.o -o main
main.o:main.c
	gcc -c main.c -o main.o
class.o:class.c
	gcc -c class.c -o class.o

.PHONY:clean
clean:
	rm main *.o
