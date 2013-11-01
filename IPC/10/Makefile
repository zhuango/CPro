sem_open: sem_open.c
	gcc -pthread sem_open.c -o sem_open

sem_getvalue:sem_getvalue.c
	gcc -pthread sem_getvalue.c -o sem_getvalue

sem_post:sem_post.c
	gcc -pthread sem_post.c -o sem_post

sem_unlink:sem_unlink.c
	gcc -pthread sem_unlink.c -o sem_unlink
.PHONY:clean
clean:
	rm sem_open sem_getvalue sem_post sem_unlink
