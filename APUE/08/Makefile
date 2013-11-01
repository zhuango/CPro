test_exit:test_exit.o
	gcc test_exit.o -o test_exit
test_exit.o:test_exit.c
	gcc -c test_exit.c -o test_exit.o

getlogin:getlogin.o
	gcc getlogin.o -o getlogin
getlogin.o:getlogin.c
	gcc -c getlogin.c -o getlogin.o

.PHONY:clean
clean:
	rm test_exit getlogin *.o
