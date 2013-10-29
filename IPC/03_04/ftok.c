#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/ipc.h>

key_t Ftok(const char *pathname, int id)
{
	key_t	tmp;
	if((tmp = ftok(pathname, id)) < 0){
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	return (tmp);
}
void Stat(const char *pathname, struct stat *statbuf)
{
	if(stat(pathname, statbuf) < 0){
		perror("stat");
		exit(EXIT_FAILURE);
	}
}
int main(int argc, char *argv[])
{
	struct stat statbuf;
	if(argc != 2){
		printf("Usage: ftok <pathname>\n");
		exit(EXIT_FAILURE);
	}
	Stat(argv[1], &statbuf);
	printf("st_dev: %lx, st_ino: %lx, id: 0x57, key: %x\n", 
			(u_long)statbuf.st_dev, (u_long)statbuf.st_ino, Ftok(argv[1], 0x575));

	exit(EXIT_FAILURE);
}
