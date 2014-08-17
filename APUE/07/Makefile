jmp:jmp.o
	gcc jmp.o -o jmp
jmp.o:jmp.c
	gcc -c jmp.c -o jmp.o

jmp_O:jmp.c
	gcc -O jmp.c -o jmp_O

fork:fork.o
	gcc fork.o -o fork
fork.o:fork.c
	gcc -c fork.c -o fork.o

fork2:fork2.o
	gcc fork2.o -o fork2
fork2.o:fork2.c
	gcc -c fork2.c -o fork2.o

exec:exec.o
	gcc exec.o -o exec
exec.o:exec.c
	gcc -c exec.c -o exec.o

system:system.o
	gcc system.o -o system
system.o:system.c
	gcc -c system.c -o system.o

sys_setUserId:sys_setUserId.o
	gcc sys_setUserId.o -o sys_setUserId
sys_setUserId.o:sys_setUserId.c
	gcc -c sys_setUserId.c -o sys_setUserId.o

sys_time:sys_time.o
	gcc sys_time.o -o sys_time
sys_time.o:sys_time.c
	gcc -c sys_time.c -o sys_time.o

signal:signal.o
	gcc signal.o -o signal
signal.o:signal.c
	gcc -c signal.c -o signal.o

.PHONY:clean

clean:
	rm jmp jmp_O fork fork2 exec system sys_setUserId sys_time signal *.o
