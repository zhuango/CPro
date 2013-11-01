OBJ = fdread.o

fdread: $(OBJ)
	gcc $(OBJ) -o fdread

fdread.o: fdread.c
	gcc -c fdread.c -o $(OBJ)

.PHONY:clean

clean:
	rm fdread *.o
