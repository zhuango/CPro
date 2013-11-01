#include<stdio.h>
#include<utmp.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

#define SHOWHOST
void show_info(struct utmp *);

int main(void)
{
	struct utmp 	current_record;
	int 		utmpfp;
	int 		reclen = sizeof(current_record);

	if((utmpfp = open(UTMP_FILE,O_RDONLY)) == -1){
		perror(UTMP_FILE);
		exit(EXIT_FAILURE);
	}

	while(read(utmpfp, &current_record, reclen) == reclen)
		show_info(&current_record);

	close(utmpfp);
	return 0;
}

void show_info(struct utmp *utmp_record)
{
	char *cp;
	int i = 0;
	cp = ctime(&(utmp_record->ut_tv.tv_sec))+4;
	*(cp + 16) = '\0';
	if(utmp_record->ut_type != USER_PROCESS){
		return ;
	}
	printf("%s\t%s\t\t%s(%s)\n",
			utmp_record->ut_user,
			utmp_record->ut_line,
			cp,
			utmp_record->ut_host);

}
