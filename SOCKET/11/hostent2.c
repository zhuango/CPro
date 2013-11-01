#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<netdb.h>
#define HOSTNAME 100
#define ADDRSIZE 100
int main(int argc, char **argv)
{
	struct hostent *hostinfo;
	char *name;
	char **alias, **ips;
	char ip[ADDRSIZE];

	while(--argc != 0){
		name = *++argv;

		/* get the hostent by Name */
		if((hostinfo = gethostbyname(name)) == NULL){
			fprintf(stderr, "error: ", hstrerror(h_errno));
			exit(EXIT_SUCCESS);
		}
		printf("name: %s\n", hostinfo->h_name);/* Print the host name */

		/* Print alias names */
		alias = hostinfo->h_aliases;
		printf("alias: ");
		for(; *alias != NULL; alias ++)
			printf("%s\n", *alias);

		printf("INET type: %d\n", hostinfo->h_addrtype);/* Print the add type */
		printf("length : %d\n", hostinfo->h_length);/* address length */

		/* Print the IP address */
		ips = hostinfo->h_addr_list;
		for(; *ips != NULL; ips++)
			printf("IPv4: %s\n", 
					inet_ntop(hostinfo->h_addrtype, *ips, ip, sizeof(ip)));
	}

	exit(EXIT_SUCCESS);
}
