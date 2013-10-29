#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<netdb.h>

int main(void)
{
	struct servent *server;
	char **names;

//	if((server = getservbyname("ftp", "tcp")) == NULL){
//		perror("getservbyname");
//		exit(EXIT_FAILURE);
//	}
	
	if((server = getservbyname("ftp", "udp")) == NULL){
		perror("getservbyname");
		exit(EXIT_FAILURE);
	}

	/* Print server name */
	printf("%s\n", server->s_name);

	/* Print server slias names */
	printf("aliases names: \n");
	for(names = server->s_aliases; *names != NULL; names ++)
		printf("%s\n", *names);

	/* Print the server port number */
	printf("Port number; ");
	printf("%d \n", ntohs(server->s_port));

	/* protocol to use */
	printf("protocol: %s\n", server->s_proto);

	exit(EXIT_SUCCESS);


}
