#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

#define MAXLINE 1024
#define SEQFILE "seqno"

int Open(const char *filename, int flag, mode_t mode)
{
	int fd;
	if((fd = open(filename, flag, mode)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}
	return fd;
}

off_t  Lseek(int fd, off_t offset, int whence)
{
	off_t pos;
	if((pos = lseek(fd, offset, whence)) < 0){
		perror("lseek");
		exit(EXIT_FAILURE);
	}
}

ssize_t Read(int fd, void *buf, size_t nbytes)
{
	ssize_t n;
	if((n = read(fd, buf, nbytes)) < 0){
		perror("read");
		exit(EXIT_FAILURE);
	}

	return n;
}

ssize_t Write(int fd, const char *buf, size_t nbytes)
{
	ssize_t n;
	if((n = write(fd, buf, nbytes)) < 0){
		perror("write");
		exit(EXIT_FAILURE);
	}

	return n;
}

void my_lock(int), my_unlock(int);

int main(int argc, char **argv)
{
	int		fd;
	long	i, seqno;
	pid_t	pid;
	ssize_t	n;
	char	line[MAXLINE + 1];

	pid = getpid();
	fd = Open(SEQFILE, O_RDWR | O_CREAT, 0644);

	for(i = 0; i < 20; i++){
		my_lock(fd);

		Lseek(fd, 0L, SEEK_SET);
		n = Read(fd, line, MAXLINE);
		line[n] = '\0';

		n = sscanf(line, "%ld\n", &seqno);
		printf("%s: pid = %ld, seq# = %ld\n", argv[0], (long)pid, seqno);
		
		seqno++;

		snprintf(line, sizeof(line), "%ld\n", seqno);
		Lseek(fd, 0L, SEEK_SET);
		Write(fd, line, strlen(line));

		my_unlock(fd);
	}

	exit(EXIT_FAILURE);
}
