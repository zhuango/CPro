#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(void)
{
	pid_t pid;
	if((pid = fork()) < 0){/* create the first process */
		perror("fork1");
		exit(EXIT_FAILURE);
	}else if(pid == 0){	/* first child */
		if((pid = fork()) < 0){/* create second child process */
			perror("fork 2");
			exit(EXIT_FAILURE);
		}else if(pid > 0){	/* first process exit */
			exit(EXIT_SUCCESS);
		}


		sleep(2);/* second child sleep 2 seconds  */
		/* print parent pid now the real parent (first child process was died , so this pid is init's pid)*/
		printf("second child , parent pid == %d\n", getppid());
		exit(EXIT_SUCCESS);
	}

	if(waitpid(pid, NULL, 0) != pid){/* wait the first child process */
		perror("waitpid");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
