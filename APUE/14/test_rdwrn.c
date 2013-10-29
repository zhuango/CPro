#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
ssize_t readn(int fd, void *ptr, size_t n)
{
	size_t	nleft;
	ssize_t nread;

	nleft = n;
	while(nleft > 0){
		if((nread = read(fd, ptr, nleft)) < 0){
			if(nleft == n){
				return(-1);
			}else
				break;
		}else if(nleft == 0){
			break;
		}
		nleft -= nread;
		ptr += nread;
	}
	return (n - nleft);
}

ssize_t writen(int fd, void *ptr, size_t n)
{
	size_t nleft;
	ssize_t nwrite;

	nleft = n;
	while(nleft > 0){
		if((nwrite = write(fd, ptr, nleft)) < 0){
			if(nleft == n){
				return (-1);
			}else
				break;
		}else if(nleft == 0){
			break;
		}

		nleft -= nwrite;
		ptr += nwrite;
	}
	return(n - nleft);
}
int main(void){}
