#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int i = 0;
	for(i = 0; i < 100; i++){
		if(execl("./client", "client", "127.0.0.1",NULL) < 0){
			perror("execl");
			exit(EXIT_FAILURE);
		}

		write(STDIN_FILENO, "sdf", 3);
	}
	exit(EXIT_SUCCESS);
}
