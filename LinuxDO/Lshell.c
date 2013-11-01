#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>

#define CMD_NUM 10
#define BUF	1024
#define ARG_SIZ 20

char *cmd_malloc(char *);

static void ignore(){
	printf("\n");
	write(1, "[Og@RHEL6.3]$ ", 14);						/* print the head */
}


int main(void)
{
	pid_t pid;			/* create the new task,and return this */
	int nchar;			/* get number of the chars from terminal */
	int num = 0;		/* count to use cut the string */
	int cmd_num = 0;	/* the number of arg from termial */
	char *cmd[CMD_NUM];	/* the command */
	char buf[BUF];		/* the whole command */
	char arg[ARG_SIZ];	/* one arg of the whole command */

	signal(SIGINT,ignore);
	signal(SIGQUIT,ignore);

	while(1){
		write(1, "[Og@RHEL6.3]$ ", 14);						/* print the head */
		memset(buf, 0, BUF);					/* clear the buf */
		memset(arg, 0, ARG_SIZ);				/* clear the arg */
		cmd_num = 0;							/* clear for using at next time */
		fgets(buf, BUF, stdin);		/* get the command */
		
		if(buf[0] == '\0'){
			printf("\n");
			exit(0);
		}
		
		for(nchar = 0; buf[nchar] != '\n'; nchar++);	/* count the number of the whole command */
		
		buf[nchar] = ' ';								/* set the last char as ' ' to go into the for loop */
		buf[nchar+1] = '\n';							/* stop the for loop */

		/* put the args of command to the cmd[] */
		for(nchar = 0; buf[nchar] != '\n'; nchar++){
			num ++;
			if(buf[nchar] == ' '){						/* if saw the ' ' , then put the front chars into arg[] */
				strncpy(arg,buf+nchar-num+1,num);		/* put the chars on front of ' ' into the arg[] */
				arg[num-1] = '\0';						/* set the end of the arg */
				num = 0;								/* count one arg og the whole command */
				cmd[cmd_num] = cmd_malloc(arg);			/* get the space for the cmd[] */
				cmd_num++;								/* count the cmd */
			}

		}
		cmd[cmd_num] = NULL;					/* for using the function execvp */
		
		if(cmd[0][0] == '\0'){					/* if you input only '\n' ,here will check it out */
			continue;
		}

		if(!(strncmp(cmd[0],"exit",4))){
			exit(0);
		}

		if((pid = fork()) == 0){				/* create task to do the command */
			execvp(cmd[0],cmd);
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		wait(NULL);
	}

	return 0;
}

char *cmd_malloc(char *buf)
{
	int nchar;
	char *p;
	nchar = strlen(buf)+1;
	p = malloc(nchar*sizeof(char));					/* get the space */
	strncpy(p, buf, nchar);

	return p;
}
