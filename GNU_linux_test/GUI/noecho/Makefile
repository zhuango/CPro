noecho: noecho.c
	gcc noecho.c -o noecho

setraw:setraw.o
	gcc setraw.o -o setraw
setraw.o:setraw.c
	gcc -c setraw.c -o setraw.o

.PHONY: clean
clean:
	rm noecho setraw *.o
