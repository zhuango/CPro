detach:pthread_detach.c
	gcc -pthread pthread_detach.c -o detach

pthread_recur: pthread_recur.o makepthread.o
	gcc -pthread pthread_recur.o makepthread.o -o pthread_recur

pthread_recur_die:pthread_recur_die.o makepthread.o
	gcc -pthread pthread_recur_die.o makepthread.o -o pthread_recur_die
pthread_recur_die.o:pthread_recur_die.c
	gcc -c -pthread pthread_recur_die.c -o pthread_recur_die.o
pthread_recur.o:pthread_recur.c
	gcc -pthread -c pthread_recur.c -o pthread_recur.o
makepthread.o:makepthread.c
	gcc -pthread -c makepthread.c -o makepthread.o

.PHONY:clean
clean:
	rm detach pthread_recur pthread_recur_die *.o  
