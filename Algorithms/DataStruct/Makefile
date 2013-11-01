PRO:=Algorithms.o

Algorithms: ${PRO}
	gcc ${PRO} -o Algorithms
${PRO}: Algorithms.c
	gcc -c Algorithms.c -o ${PRO}

insertion_sort:insertion_sort.o
	gcc insertion_sort.o -o insertion_sort
insertion_sort.o:insertion_sort.c
	gcc -c insertion_sort.c -o insertion_sort.o

add_2: add_2.o
	gcc add_2.o -o add_2
add_2.o:add_2.c
	gcc -c add_2.c -o add_2.o

chose_sort:chose_sort.o
	gcc chose_sort.o -o chose_sort
chose_sort.o:chose_sort.c
	gcc -c chose_sort.c -o chose_sort.o

merge_sort:merge_sort.o
	gcc merge_sort.o -o merge_sort
merge_sort.o:merge_sort.c
	gcc -c merge_sort.c -o merge_sort.o

bubble_sort:bubble_sort.o
	gcc bubble_sort.o -o bubble_sort
bubble_sort.o:bubble_sort.c
	gcc -c bubble_sort.c -o bubble_sort.o

heap_sort:heap_sort.o
	gcc heap_sort.o -o heap_sort
heap_sort.o:heap_sort.c
	gcc -c heap_sort.c -o heap_sort.o


.PHONY: clean
clean:
	rm Algorithms insertion_sort add_2 chose_sort merge_sort bubble_sort heap_sort *.o
