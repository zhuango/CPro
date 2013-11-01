more:more.o
	gcc more.o -o more
more.o:more.c
	gcc -c more.c -o more.o

more2:more2.o
	gcc more2.o -o more2
more2.o:more2.c
	gcc -c more2.c -o more2.o

utmp:utmp.o
	gcc utmp.o -o utmp
utmp.o:utmp.c
	gcc -c utmp.c -o utmp.o

hello1:hello1.c
	gcc hello1.c -l curses -o hello1

hello2:hello2.c
	gcc hello2.c -l curses -o hello2

timer:timer.c
	gcc timer.c -l curses -o timer

hello5:hello5.c
	gcc hello5.c -l curses -o hello5

ticker_demo:ticker_demo.o
	gcc ticker_demo.o -o ticker_demo
ticker_demo.o:ticker_demo.c
	gcc -c ticker_demo.c -o ticker_demo.o

signals:signals.c
	gcc signals.c -l curses -o signals

sigactdemo:sigactdemo.c
	gcc sigactdemo.c -l curses -o sigactdemo

bounceld:bounceld.c
	gcc bounceld.c -l curses -o bounceld

my_move:my_move.c
	gcc my_move.c -l curses -o my_move

ls1:ls1.o
	gcc ls1.o -o ls1
ls1.o:ls1.c
	gcc -c ls1.c -o ls1.o

ls2:ls2.o
	gcc ls2.o -o ls2
ls2.o:ls2.c
	gcc -c ls2.c -o ls2.o

my_stat:my_stat.o
	gcc my_stat.o -o my_stat
my_stat.o:my_stat.c
	gcc -c my_stat.c -o my_stat.o

lpwd:lpwd.o
	gcc lpwd.o -o lpwd
lpwd.o:lpwd.c
	gcc -c lpwd.c -o lpwd.o

write0:write0.o
	gcc write0.o -o write0
write0.o:write0.c
	gcc -c write0.c -o write0.o

psh2:psh2.o
	gcc psh2.o -o psh2
psh2.o:psh2.c
	gcc -c psh2.c -o psh2.o

.PHONY:clean
clean:
	rm more more2 utmp hello1 timer hello2 hello5 ticker_demo signals sigactdemo bounceld my_move ls1 my_stat ls2 lpwd write0 psh2 *.o
