#include<stdio.h>
#include<curses.h>
#include<signal.h>
#include<string.h>
#include<sys/time.h>

#define MESSAGE "hello"
#define BLANK 	"     "

int row;
int col;
int dir;

int main(void)
{
	int delay;
	int ndelay;

	int c;
	void move_msg(int);

	initscr();
	crmode();		/*I don't known either*/
	noecho();		/*you input, but you can't see them*/
	clear();

	row = 10;		/*start here*/
	col = 0;
	dir = 1;		/*add 1 to row number*/
	delay = 200;		/*200ms = 0.2 seconds*/

	move(row,col);		/*get into position*/
	addstr(MESSAGE);	/*draw the "Hello" to the screen*/
	signal(SIGALRM, move_msg);
	set_ticker(delay);	/*set the time*/

	while(1)
	{
		ndelay = 0;
		c = getch();
		if(c == 'Q')break;
		if(c == ' ')dir = -dir;
		if(c == 'f' && delay > 2) ndelay = delay/2;
		if(c == 's')ndelay = delay * 2;
		if(ndelay > 0)
			set_ticker(delay = ndelay);
	}

	endwin();
	return 0;
}
void move_msg(int signum)
{
	signal(SIGALRM, move_msg);
	move(row, col);
	addstr(BLANK);
	col += dir;
	move(row, col);
	addstr(MESSAGE);
	refresh();

	if(dir == -1 && col <= 0)
		dir = 1;
	else if(dir == 1 && col + strlen(MESSAGE) >= COLS)
		dir = -1;
}


int set_ticker(int n_msecs)
{
	struct itimerval new_timeset;
	long n_sec, n_usecs;

	n_sec = n_msecs/1000;			//the second
	n_usecs = (n_msecs % 1000) * 1000L;	//the usecond

	/*set the loop time*/
	new_timeset.it_interval.tv_sec = n_sec;
	new_timeset.it_interval.tv_usec = n_usecs;

	/*set the begin time*/
	new_timeset.it_value.tv_sec = n_sec;
	new_timeset.it_value.tv_usec = n_usecs;

	return setitimer(ITIMER_REAL, &new_timeset, NULL);
}
