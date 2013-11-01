#include<stdio.h>
#include<stdlib.h>
#include<sys/times.h>
#include<time.h>
#include<unistd.h>


void doit(char *, clock_t);

int main(void)
{
	clock_t start,end;
	struct tms t_start, t_end;

	/*safe the time to t_start struct ,and return clock_t to start*/
	start = times(&t_start);

	system("grep the /usr/doc/*/*/ > /dev/null 2> /dev/null");
	end = times(&t_end);

	doit("elapsed",end-start);

	puts("parent times");
	doit("\tuser CPU",t_end.tms_utime);
	doit("\tsys CPU",t_end.tms_cstime);

	puts("child times");
	doit("\tuser CPU",t_end.tms_cutime);
	doit("\tsys CPU",t_end.tms_cstime);


	exit(EXIT_SUCCESS);
}

void doit(char *str, clock_t time)
{
	long tps = sysconf(_SC_CLK_TCK);
	printf("%s: %6.2f secs\n",str,(float) time/tps);
}

