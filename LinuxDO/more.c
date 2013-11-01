#include<stdio.h>
#include<stdlib.h>
#define PAGELEN 24
#define LINELEN 512

void do_more(FILE *);

int see_more();

int main(int argc,char *argv[])
{
	FILE *fp;

	/*are there  filenames?*/
	if(argc == 1)
		do_more(stdin);

	/*yes! there is */
	else
		/*OK! let's read them!,one by one*/
		while(--argc)
			/*open file to read*/
			if((fp = fopen(*++argv,"r")) != NULL){
				do_more(fp);			//read
				fclose(fp);			//close
			}else
				exit(EXIT_FAILURE);
	return 0;
}

/*display the file to the stdout*/
void do_more(FILE *fp)
{
	char line[LINELEN];	//line
	int num_of_lines = 0;	//how many lines
	int see_more(),reply;	//the screen is not enough! then go to the see_more() function, return reply for status

	/*get the lines from file*/
	while(fgets(line, LINELEN, fp)){	//get a line
		if(num_of_lines == PAGELEN){	//full of screen?
			reply = see_more();	//read more?
			if(reply == 0)		//0 for exit
				break;
			num_of_lines -= reply;	//reset the line counter
		}

		if(fputs(line,stdout) == EOF)	//print a line
			exit(EXIT_FAILURE);
		num_of_lines++;			//line counter
	}
}

int see_more()
{
	int c;
	printf("more?");
	while((c = getchar()) != EOF)	//get a char from the terminal
	{
		if(c == 'q')		//quit
			return 0;
		if(c == ' ')		//print other pag
			return PAGELEN;
		if(c == '\n')		//print one more line
			return 1;
	}

	return 0;
}
