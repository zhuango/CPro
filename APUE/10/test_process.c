#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<fcntl.h>


static volatile sig_atomic_t sigflag;
static sigset_t newmask, oldmask, zeromask;

static void sig_usr(int signo)
{
	sigflag = 1;
}

void TELL_WAIT(void)
{
	if(signal(SIGUSR1, sig_usr) == SIG_ERR){
		perror("signal");
		exit(EXIT_FAILURE);
	}
	if(signal(SIGUSR2, sig_usr) == SIG_ERR){
		perror("signal");
		exit(EXIT_FAILURE);
	}
	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGUSR1);
	sigaddset(&newmask, SIGUSR2);

	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
}

void TELL_PARENT(pid_t pid)
{
	kill(pid, SIGUSR2);
}

void WAIT_PARENT(void)
{
	while(sigflag == 0)
		sigsuspend(&zeromask);

	sigflag = 0;

	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
}

void TELL_CHILD(pid_t pid)
{
	kill(pid, SIGUSR1);
}

void WAIT_CHILD(void)
{
	while(sigflag == 0)
		sigsuspend(&zeromask);

	sigflag = 0;

	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0){
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	pid_t pid;
	int fd;
	int r_count;
	char buf[]="0";
	if((fd = open("foo", O_CREAT | O_RDWR, 0777)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}
	if(write(fd,buf,1) < 0){
		perror("write");
		exit(EXIT_FAILURE);
	}
	if(read(fd, buf, 1) < 0){
		perror("read");
		exit(EXIT_FAILURE);
	}

	printf("+++++++%c+++++++++\n\n",buf[0]);
	TELL_WAIT();
	if((pid = fork()) < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		while(1){
			if(lseek(fd, 0, SEEK_SET) < 0){
				perror("lseek");
				exit(EXIT_FAILURE);
			}
			if(read(fd, buf, 1) < 0){
				perror("read");
				exit(EXIT_FAILURE);
			}
			buf[0]++;
			if(lseek(fd, 0, SEEK_SET) < 0){
				perror("lseek");
				exit(EXIT_FAILURE);
			}
			if(write(fd, buf, 1) < 0){
				perror("write");
				exit(EXIT_FAILURE);
			}
			printf("child write %c\n",buf[0]);
			printf("child wait...\n\n");
			sleep(2);
			TELL_PARENT(getppid());
			WAIT_PARENT();
		}
	}else{
		WAIT_CHILD();
		while(1){
			if(lseek(fd, 0, SEEK_SET) < 0){
				perror("lseek");
				exit(EXIT_FAILURE);
			}
			if(read(fd, buf, 1) < 0){
				perror("read");
				exit(EXIT_FAILURE);
			}
			buf[0]++;
			if(lseek(fd, 0, SEEK_SET) < 0){
				perror("lseek");
				exit(EXIT_FAILURE);
			}
			if(write(fd, buf, 1) < 0){
				perror("write");
				exit(EXIT_FAILURE);
			}
			printf("parent write %c\n",buf[0]);
			printf("parent wait...\n\n");
			sleep(2);
			TELL_CHILD(pid);
			WAIT_CHILD();
		}
	}

	exit(EXIT_SUCCESS);
}

