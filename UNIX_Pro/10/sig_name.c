#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int main(void)
{
	char *sig_name = "sig_name";
	printf("%s\n",sys_siglist[SIGINT]);
	printf("%s\n",sys_siglist[SIGQUIT]);
	printf("%s\n",sys_siglist[SIGCHLD]);
	printf("%s\n",sys_siglist[SIGALRM]);
	printf("%s\n",sys_siglist[SIGCONT]);
	printf("%s\n",sys_siglist[SIGUSR1]);
	printf("%s\n",sys_siglist[SIGUSR2]);

	psignal(SIGUSR1, sig_name);
	psignal(SIGUSR2, sig_name);

	printf("sig_name: %s\n", strsignal(SIGUSR1));
	printf("sig_name: %s\n", strsignal(SIGUSR2));
	return 0;
}
