#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void client(int, int), server(int, int);
void Pipe(int*);
void Close(int);
void Waitpid(pid_t, int*, int);
pid_t Fork();

int main(int argc, char *argv[])
{
	int		pipe1[2], pipe2[2];
	pid_t	childpid;

	/* craete two pipes */
	Pipe(pipe1);
	Pipe(pipe2);

	if((childpid = Fork()) == 0){
		/* Server(child) use pipe1 to read, 
		 * Use pipe2 to write */
		Close(pipe1[1]);/* Close pipe1 write end */
		Close(pipe2[0]);/* Close pipe2 read end */

		server(pipe1[0], pipe2[1]);/* Read from pipe1 and write to pipe2*/
		exit(EXIT_SUCCESS);
	}

	/* Client(parent) use pipe1 to write
	 * Use pipe2 to read */
	Close(pipe1[0]);/* Close pipe1 read end */
	Close(pipe2[1]);/* Close pipe2 write end */

	client(pipe2[0], pipe1[1]);/* Read from pipe2 and write to pipe1 */

	Waitpid(childpid, NULL, 0);/* wait the child process */

	exit(EXIT_FAILURE);
}
/* fork function */
pid_t Fork()
{
	pid_t tmp;
	if((tmp = fork()) < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (tmp);
}
/* pipe functinon */
void Pipe(int *pipef)
{
	if(pipe(pipef) < 0){
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}
/* waitpid function */
void Waitpid(pid_t pid, int *statloc, int opinion)
{
	if(waitpid(pid, statloc, opinion) < 0){
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
}
