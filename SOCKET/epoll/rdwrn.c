#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>

ssize_t readn(int fd, char *vptr, size_t n)
{
	size_t nleft;
	ssize_t nread;
	char *ptr;

	ptr = vptr;/* string save the words from read */
	nleft = n;/* length of string */

	while(nleft > 0){
		if((nread = read(fd, ptr, nleft)) < 0){
			if(errno == EINTR)/* error and go again*/
				nread = 0;
			else
				return (-1);
		}else if(nread == 0)/* EOF */
			break;

		nleft -= nread;/* nread datas have been read */
		ptr += nread;/* save next bytes */
	}

	return (n - nleft);
}

ssize_t writen(int fd, char *vptr, size_t n)
{
	size_t nleft;
	ssize_t nwritten;
	const char *ptr;

	ptr = vptr;/* string want to write */
	nleft = n;/* length of string */
	while(nleft > 0){
		if((nwritten = write(fd, ptr, nleft)) <= 0){
			if(nwritten < 0 && errno == EINTR)/* write nothing */
				nwritten = 0;
			else/* error */
				return (-1);
		}

		nleft -= nwritten;/* have written n */
		ptr += nwritten; /* rest bytes */
	}

	return (n);
}
