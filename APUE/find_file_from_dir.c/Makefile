OBJ1 = find_from_dir.c
OBJ2 = find_fomr_dir.o

find_from_dir: $(OBJ2)
	gcc $(OBJ2) -o find_from_dir
$(OBJ2):$(OBJ1)
	gcc -c $(OBJ1) -o $(OBJ2)

.PHONY:clean
clean:
	rm $(OBJ2) *.o
