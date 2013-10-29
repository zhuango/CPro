#include<stdio.h>
#include<curses.h>

int main(void)
{
	initscr();		/*turn on curses*/

	clear();		/*clear screen*/
	move(20,20);		/*row10, col20*/
	addstr("Hello, world");	/*add a string*/
	move(LINES - 1, 0);	/*move to Zui Xia*/
	refresh();		/*update the screen*/
	getch();
	endwin();
}
