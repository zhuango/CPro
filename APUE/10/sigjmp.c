#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<setjmp.h>

static void sig_usr1(int), sig_alarm(int);
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjump;

void pr_mask(char *wr)
{
	sigset_t sigset;
	if(sigprocmask(0,NULL,&sigset) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
	printf("%s %d\n", wr, sigset);
}

int main(void)
{
	if(signal(SIGUSR1, sig_usr1) == SIG_ERR){
		perror("signal");
		exit(EXIT_FAILURE);
	}
	if(signal(SIGALRM, sig_alarm) == SIG_ERR){
		perror("signal");
		exit(EXIT_FAILURE);
	}
	pr_mask("main start: ");
	if(sigsetjmp(jmpbuf, 1)){
		pr_mask("ending main:");
		exit(EXIT_FAILURE);
	}
	printf("____________________________________\n");
	canjump = 1;
	for( ; ; )
		pause();
}

static void sig_usr1(int signo)
{
	time_t starttime;
	if(canjump == 0)
		return ;

	pr_mask("starting sig_usr1: ");
	alarm(3);
	starttime = time(NULL);

	for( ; ; )
		if(time(NULL) > starttime + 5)
			break;
	pr_mask("finishing sig_usr1: ");

	canjump = 0;
	siglongjmp(jmpbuf, 1);
}

static void sig_alarm(int signo)
{
	pr_mask("in sig_alarm:");
}
