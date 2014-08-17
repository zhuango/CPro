alarm_signal:alarm_signal.o
	gcc alarm_signal.o -o alarm_signal
alarm_signal.o:alarm_signal.c
	gcc -c alarm_signal.c -o alarm_signal.o
alarm:alarm.o
	gcc alarm.o -o alarm
alarm.o:alarm.c
	gcc -c alarm.c -o alarm.o

jmp_signal:jmp_signal.o
	gcc jmp_signal.o -o jmp_signal
jmp_signal.o:jmp_signal.c
	gcc -c jmp_signal.c -o jmp_signal.o

sig1:sig1.o
	gcc sig1.o -o sig1
sig1.o:sig1.c
	gcc -c sig1.c -o sig1.o

sig_again:sig_again.o
	gcc sig_again.o -o sig_again
sig_again.o:sig_again.c
	gcc -c sig_again.c -o sig_again.o

test_sigset:test_sigset.o
	gcc test_sigset.o -o test_sigset
test_sigset.o:test_sigset.c
	gcc -c test_sigset.c -o test_sigset.o

test_sigmask:test_sigmask.o
	gcc test_sigmask.o -o test_sigmask
test_sigmask.o:test_sigmask.c
	gcc -c test_sigmask.c -o test_sigmask.o

test_signalall:test_signalall.o
	gcc test_signalall.o -o test_signalall
test_signalall.o:test_signalall.c
	gcc -c test_signalall.c -o test_signalall.o

alarms_pthread:alarms_pthread.o
	gcc -pthread alarms_pthread.o -o alarms_pthread
alarms_pthread.o:alarms_pthread.c
	gcc -c -pthread alarms_pthread.c -o alarms_pthread.o

test_sigaction:test_sigaction.o
	gcc test_sigaction.o -o test_sigaction
test_sigaction.o:test_sigaction.c
	gcc -c test_sigaction.c -o test_sigaction.o

test_sigsus:test_sigsus.o
	gcc test_sigsus.o -o test_sigsus
test_sigsus.o:test_sigsus.c
	gcc -c test_sigsus.c -o test_sigsus.o

test_sigsus2:test_sigsus2.o
	gcc test_sigsus2.o -o test_sigsus2
test_sigsus2.o:test_sigsus2.c
	gcc -c test_sigsus2.c -o test_sigsus2.o

test_process:test_process.o
	gcc test_process.o -o test_process
test_process.o:test_process.c
	gcc -c test_process.c -o test_process.o

10_9:10_9.c
	gcc 10_9.c -o 10_9

.PHONY:clean
clean:
	rm alarm_signal alarm jmp_signal sig1 sig_again test_sigset test_sigmask test_signalall alarms_pthread test_sigaction test_sigsus test_sigsus2 test_process 10_9 *.o
