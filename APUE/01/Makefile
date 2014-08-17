dir: dir.o
	gcc dir.o -o dir
dir.o: dir.c
	gcc -c dir.c -o dir.o

file_read:file_read.o
	gcc file_read.o -o file_read
file_read.o:file_read.c
	gcc -c file_read.c -o file_read.o

file_get:file_get.o
	gcc file_get.o -o file_get
file_get.o:file_get.c
	gcc -c file_get.c -o file_get.o

getpid:getpid.o
	gcc getpid.o -o getpid
getpid.o:getpid.c
	gcc -c getpid.c -o getpid.o

process:process.o
	gcc process.o -o process
process.o:process.c
	gcc -c process.c -o process.o

errno:errno.o
	gcc errno.o -o errno
errno.o:errno.c
	gcc -c errno.c -o errno.o

signal:signal.o
	gcc signal.o -o signal
signal.o:signal.c
	gcc -c signal.c -o signal.o

lseek:lseek.o
	gcc lseek.o -o lseek
lseek.o:lseek.c
	gcc -c lseek.c -o lseek.o

file_hole:file_hole.o
	gcc file_hole.o -o file_hole
file_hole.o:file_hole.c
	gcc -c file_hole.c -o file_hole.o

fcntl:fcntl.o
	gcc fcntl.o -o fcntl
fcntl.o:fcntl.c
	gcc -c fcntl.c -o fcntl.o

my_dup2: my_dup2.o
	gcc my_dup2.o -o my_dup2
my_mup2.o:my_dup2.c
	gcc -c my_dup2.c -o mydup2.o

file_type: file_type.o
	gcc file_type.c -o file_type
file_type.o:file_type.c 
	gcc -c file_type.c -o file_type.o

access:access.o
	gcc access.o -o access
access.o:access.c
	gcc -c access.c -o access.o

umask:umask.o
	gcc umask.o -o umask
umask.o:umask.c
	gcc -c umask.c -o umask.o

utime:utime.o
	gcc utime.o -o utime
utime.o:utime.c
	gcc -c utime.c -o utime.o

time:time.o
	gcc time.o -o time
time.o:time.c
	gcc -c time.c -o time.o

whole: whole.o
	gcc whole.o -o whole
whole.o:whole.c
	gcc -c whole.c -o whole.o

dup:dup.o
	gcc dup.o -o dup
dup.o:dup.c
	gcc -c dup.c -o dup.o

.PHONY:clean

clean:
	rm file_read dir file_get getpid process errno signal lseek file_hole fcntl my_dup2 file_type access umask utime time whole dup  *.o
