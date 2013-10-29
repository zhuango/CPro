#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#define MAXLINE 1024
static int read_cnt;
static char *read_ptr;
static char read_buf[MAXLINE];

/* Open */
int Open(const char *filename, int type, mode_t mode)
{
	int fd;
	if((fd = open(filename, type, 0)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
/* write */
int Write(int writefd, char *buff, int len)
{
	int n;
	if((n = write(writefd, buff, len)) < 0){ 
		perror("write");
		exit(EXIT_FAILURE);
	}   

	return (n);
}
/* read */
int Read(int readfd, char *buff, int maxline)
{
	int n;
	if((n = read(readfd, buff, maxline)) < 0){ 
		perror("read");
		exit(EXIT_FAILURE);
	}   

	return (n);
}
/* close */
void Close(int fd)
{
	if(close(fd) < 0){
		perror("close");
		exit(EXIT_FAILURE);
	}
}
static ssize_t my_read(int fd, char *ptr)
{
	if(read_cnt <= 0){
again:
		if((read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0){
			if(errno == EINTR)
				goto again;
			return(-1);
		}else if(read_cnt == 0)
			return(0);
		read_ptr = read_buf;
	}

	read_cnt --;
	*ptr = *read_ptr++;
	return (1);
}

ssize_t Readline(int fd, char *buff, size_t maxline)
{
	ssize_t 	n,rc;
	char 	c,*ptr;
	ptr = buff;
	for(n = 1; n < maxline; n++){
		if((rc = my_read(fd, &c)) == 1){
			*ptr++ = c;
			if(c == '\n')
				break;
		}else if(rc == 0){
			*ptr = 0;
			return(n - 1);
		}else
			return (-1);
	}
	*ptr = 0;
	return(n);
}

ssize_t readlinebuf(void **vptrptr)
{
	if(read_cnt)
		*vptrptr = read_ptr;
	return(read_cnt);
}
