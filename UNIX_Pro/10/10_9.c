#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<errno.h>

#define BUFFER 10
struct signals{
	int signo;
	char sig_name[BUFFER];
};
struct signals Signals[33] = {
	{SIGABRT, "SIGABRT"},
	{SIGALRM, "SIGALRM"},
	{SIGBUS, "SIGBUS"},
	{SIGCHLD, "SIGCHLD"},
	{SIGCONT, "SIGCONT"},
	{SIGFPE, "SIGFPE"},
	{SIGHUP, "SIGHUP"},
	{SIGILL, "SIGILL"},
	{SIGINT, "SIGINT"},
	{SIGIO, "SIGIO"},
	{SIGIOT, "SIGIOT"},
	{SIGKILL, "SIGKILL"},
	{SIGPIPE, "SIGPIPE"},
	{SIGPOLL, "SIGPOLL"},
	{SIGPROF, "SOGPROF"},
	{SIGPWR, "SIGPWR"},
	{SIGQUIT, "SIGQUIT"},
	{SIGSEGV, "SIGSEGV"},
	{SIGSTKFLT, "SIGSTKFLT"},
	{SIGSTOP, "SIGSTOP"},
	{SIGSYS, "SIGSYS"},
	{SIGTERM, "SIGTERM",},
	{SIGTRAP, "SIGTRAP"},
	{SIGTSTP, "SIGTSTP"},
	{SIGTTIN, "SIGTTIN"},
	{SIGTTOU, "SIGTTOU"},
	{SIGURG, "SIGURG"},
	{SIGUSR1, "SIGUSR1"},
	{SIGUSR2, "SIGUSR2"},
	{SIGVTALRM, "SIGVTALRM"},
	{SIGWINCH, "SIGWINCH"},
	{SIGXCPU, "SIGXCPU"},
	{SIGXFSZ, "SIGXFSZ"}
};

void pr_mask(char *info);

int main(void)
{
	sigset_t sigset;
	if(sigemptyset(&sigset) < 0){
		perror("sigempty");
		exit(EXIT_FAILURE);
	}

	if(sigaddset(&sigset, SIGUSR1) < 0){
		perror("sigaddset");
		exit(EXIT_FAILURE);
	}

	if(sigaddset(&sigset, SIGUSR2) < 0){
		perror("sigaddset");
		exit(EXIT_FAILURE);
	}

	if(sigaddset(&sigset, SIGQUIT) < 0){
		perror("sigaddset");
		exit(EXIT_FAILURE);
	}

	if(sigprocmask(SIG_SETMASK, &sigset, NULL) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}

	pr_mask("in main the signal mask is : ");

	exit(EXIT_SUCCESS);
}

void pr_mask(char *info)
{
	int struct_count = 0;
	int errno_save;
	sigset_t 	sigset;
	errno_save = errno;
	if(sigprocmask(0, NULL, &sigset) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}

	printf("%s", info);

	for(struct_count = 0; struct_count < 33; struct_count++)
	{
		if(sigismember(&sigset, Signals[struct_count].signo)){
			printf("%s ", Signals[struct_count].sig_name);
		}
	}

	printf("\n");
	errno = errno_save;
	exit(EXIT_FAILURE);
}
