#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>

char * sock_ntop_host(struct sockaddr *ss, socklen_t len)
{
	static char str[128];

	switch(ss->sa_family){
		case AF_INET:{
			struct sockaddr_in *sin = (struct sockaddr_in*)ss;
			if(inet_ntop(AF_INET, &sin->sin_addr, str, sizeof(str)) == 0)
				return NULL;

			return (str);
		}
	}
}
