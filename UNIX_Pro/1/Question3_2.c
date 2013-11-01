#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
    // excise 3.2 by fred yu  
    // implementation your own dup2 function without using fcntl.  
    int my_dup2(int fd, int fd2)  
    {  
        int tmpfd = -1, i, lastfd;  
        int * fds;  
      
        if (fd2 < 0  
    #ifdef OPEN_MAX  
                || fd2 > OPEN_MAX  
    #endif  
           ) {  
            errno = EBADF;  
            printf("my_dup2, %d] fd2 is not a valid number.\n", __LINE__);  
            return -1;  
        }  
      
        tmpfd = dup(fd2);  
        if (tmpfd == -1) {  
            switch (errno) {  
                case EBADF:  
                    // fd2 is not opened.  
                    break;  
                case EMFILE:  
                    if (close(fd2) == -1) {  
                        printf("my_dup2, %d] close fd2 failed.\n", __LINE__);  
                        return -1;  
                    }  
                    break;  
                default:  
                    printf("my_dup2, %d] dup fd2 failed.\n", __LINE__);  
                    return -1;  
            }  
        } else {  
            if (close(tmpfd) == -1) {  
                printf("my_dup2, %d] close tmpfd failed.\n", __LINE__);  
                return -1;  
            }  
            if (close(fd2) == -1) {  
                printf("my_dup2, %d] close fd2 failed.\n", __LINE__);  
                return -1;  
            }  
        }  
      
        fds = (int *)malloc(fd2 * sizeof(int));  
        if (!fds) {  
            printf("my_dup2, %d] malloc fds failed.\n", __LINE__);  
            errno = ENOMEM;  
            return -1;  
        }  
      
        for (i = 0; i < fd2; ++i) {  
            fds[i] = -1;  
        }  
      
        lastfd = -1;  
        while (tmpfd = dup(fd)) {  
        printf("the new : %d\n",tmpfd);
	    	if (tmpfd == -1) {  
                printf("my_dup2, %d] dup fd failed, fd=%d, lastfd=%d, err=%d.\n", __LINE__, fd, lastfd, errno);  
                goto FAIL_EXIT;  
            } else if (tmpfd == fd2) {  
                break;  
            } else {  
                fds[tmpfd] = tmpfd;  
                lastfd = tmpfd;  
            }  
        }  
          
        for (i = 0; i < fd2; ++i) {  
            if (fds[i] != -1) close(fds[i]);  
        }  
      
        free(fds);  
        return fd2;  
      
    FAIL_EXIT:  
        for (i = 0; i < fd2; ++i) {  
            if (fds[i] != -1) close(fds[i]);  
        }  
        free(fds);  
        return -1;  
    }  
      
    int test_my_dup2(int argc, char * argv[])  
    {  
        int fd;  
       int fd2;
	if((fd2 = open("test",O_RDWR | O_CREAT,0755)) < 0){
	 	perror("open error");
		exit(EXIT_FAILURE);
	}

        if (argc < 3) {  
            printf("usage: excise oldfd newfd\n");  
            return 0;  
        }  
      
        fd = my_dup2(fd2, atoi(argv[2]));  
        if (fd == -1) {  
            printf("dup2 fd failed\n");  
            return -1;  
        }  
        printf("return fd by my_dup2 is %d", fd);  
	if(write(fd,"Hello",6) < 0){
		perror("write error");
		exit(EXIT_FAILURE);
	}

	close(fd2);
        return 0;  
    }  
      
    int main(int argc, char * argv[])  
    { 
        test_my_dup2(argc, argv);  
        exit(0);  
    }  
