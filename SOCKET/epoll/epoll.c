#include<stdio.h>
#include<stdlib.h>
#include<sys/epoll.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<errno.h>
<<<<<<< HEAD

=======
#include <arpa/inet.h>
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
#define SERV_PORT 9877
#define MAXLINE 512
#define LISTENQ 5
typedef struct sockaddr SA;

int main(void)    
{	
    int listenfd, connfd, sockfd, epfd;  
    int i, maxi, nfds;  
    ssize_t n;    
    char buf[MAXLINE];    
    socklen_t clilen;    
    struct sockaddr_in cliaddr;    
    struct sockaddr_in servaddr;   

    //声明epoll_event结构体的变量,ev用于注册事件,数组用于回传要处理的事件    
    struct epoll_event ev, events[256];    
  
    //创建一个epoll的句柄，size用来告诉内核这个监听的数目一共有多大    
    epfd = epoll_create(256);   
  
    //创建用于TCP协议的套接字      
    listenfd = socket(AF_INET, SOCK_STREAM, 0);    
    memset(&servaddr, 0, sizeof(servaddr));    
    servaddr.sin_family = AF_INET;    
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);    
    servaddr.sin_port = htons(SERV_PORT);    
  
    //把socket和socket地址结构联系起来     
    bind(listenfd, (SA*)&servaddr, sizeof(servaddr));   
    //开始监听LISTENQ端口     
    listen(listenfd, LISTENQ);  
  
    //设置与要处理的事件相关的文件描述符和事件  
    ev.data.fd = listenfd;    
<<<<<<< HEAD
    ev.events = EPOLLIN|EPOLLET;    
=======
    ev.events = EPOLLIN|EPOLLET;//epoll in && epoll et modole 
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
  
    //注册epoll事件    
    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd,&ev);    
    maxi = 0;  
  
    while(1)  
    {    
        //等待epoll事件的发生    
        //返回需要处理的事件数目nfds，如返回0表示已超时。    
        nfds = epoll_wait(epfd, events, 20, 500);    
<<<<<<< HEAD
  
=======
 printf("NmafearLIuZHuang\n");

>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
        //处理所发生的所有事件    
        for(i=0; i < nfds; ++i)    
        {    
            //如果新监测到一个SOCKET用户连接到了绑定的SOCKET端口，建立新的连接。    
            if(events[i].data.fd == listenfd)    
            {    
                connfd = accept(listenfd,(SA*)&cliaddr, &clilen);     
                printf("connection from %s, port %d.\n",        
                    inet_ntop(AF_INET, (void*)&cliaddr.sin_addr, buf, sizeof(buf)),
		    ntohs(cliaddr.sin_port)); 
  
                //设置用于读操作的文件描述符和事件  
                ev.data.fd = connfd;    
                ev.events = EPOLLIN|EPOLLET;    
  
                //注册事件  
                epoll_ctl(epfd,EPOLL_CTL_ADD,connfd,&ev);   
            }    
  
            //如果是已经连接的用户，并且收到数据，那么进行读入。    
            else if(events[i].events & EPOLLIN)    
            {    
                sockfd = events[i].data.fd;  
                if ( sockfd < 0 )    
                    continue;    
                n = read(sockfd, buf, MAXLINE);  
                if ( n < 0)     
                {      
                    // Connection Reset:你连接的那一端已经断开了，  
                    //而你却还试着在对方已断开的socketfd上读写数据！    
                    if (errno == ECONNRESET)    
                    {    
                        close(sockfd);    
                        events[i].data.fd = -1;    
                    }     
                    else    
                        perror("read error");  
                }     
                //如果读入的数据为空    
                else if ( n == 0 )   
                {    
                    close(sockfd);    
                    events[i].data.fd = -1;    
                }    
                else  
                {  
                    //设置用于写操作的文件描述符和事件  
                    ev.data.fd = sockfd;  
                    ev.events = EPOLLOUT|EPOLLET;  
                    //注册事件  
                    epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&ev);  
                }  
            }  
  
            //如果有数据发送  
            else if(events[i].events & EPOLLOUT)   
            {  
                sockfd = events[i].data.fd;  
                writen(sockfd, buf, n);    
  
                //设置用于读操作的文件描述符和事件  
                ev.data.fd = sockfd;  
                ev.events = EPOLLIN|EPOLLET;  
  
                //注册事件  
                epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev);  
            }  
        }  
    }  
    return 0;    
}   
