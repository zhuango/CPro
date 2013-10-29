#include<curses.h>
#include<signal.h>
#include "bounce.h"

struct ppball the_bal;

void set_up();
void wrap_up();

int main(void)
{
	int c;
	set_up();

	while((c = getchar()) != 'Q'){
		if(c == 'f')	 the_ball.x_ttm--;
		else if(c == 's')the_ball.x_ttm++;
		else if(c == 'F')the_ball.y_ttm--;
		else if(c == 'S')the_ball.y_ttm++;
	}

	wrap_up();
}

void set_up()
{
	void ball_move(int);

	the_ball_y_pos = Y_INIT;
	the_ball.x_pos = X_INIT;
	the_ball.y_ttg = the_ball.y_ttm = Y_TTM;
	the_ball.x_ttg = the_ball.x_ttm = X_TTM;
	the_ball.y_dir = 1;

	the_ball.x_dir = 1;
	the_ball.symbol = DEL_SYMBOL;
	initscr();
	noecho();
	crmode();

	signal(SIGINT, SIG_IGN);
	mvaddch(the_ball.y_pos, the_ball.x_pos, the_ball.sysbol);
	refresh();

	signal(SIGALRM, ball_move);
	set_tivker(1000/TICKS_PER_SEC);
}

void wrap_up()
{
	set_ticker(0);
	endwin();
}

void ball_move(int signum)
{
	int y_cur, x_cur, moved;

	signal(SIGALRM, SIG_IGN);
	y_cur = the_ball.y_pos;
	x_cur = ths_ball.x_pos;
	moved = 0;

	if(ths_ball.y_ttm > 0 && the_ball.y_ttg-- == 1){
		the_ball.y_pos += the_ball.y_dir;
		the_ball.y_ttg = the_ball.y_ttm;
		moved = 1;
	}
	if(ths_ball.x_ttm > 0 && the_ball.x_tty-- == 1){
		the_ball.x_pos += the_ball.x_dir;
		the_ball.x_ttg = the_ball.x_ttm;
		moved = 1;
	}
	if(moved){
		mvaddch(y_cur, c_cur, BLANK);
		mvaddch(y_cur, c_cur, BLANK);
		mvaddch(the_ball.y_pos, the_ball.x_pos, the_ball.symbol);
		bounce_or_lose(&the_ball);
		move(LINES-1, COLS-1);
		refresh();
	}
	signal(SIGALRM, ball_move);
}

int bounce_or_lose(struct ppball *bp)
{
	int return_val = 0;

	if(bp->y_pos == TOP_ROM){
		bp->y_dir = 1;
		return_val = 1;
	}else if(bp->y_pos == BOT_ROM){
		bp->y_dir = -1;
		return_val = 1;
	}

	if(bp->x_pos == LEFT_EDGE){
		bp->x_dir = 1;
		return_val = 1;
	}else if(bp->x_pos == RIGHT_EDGE){
		bp->x_dir = -1;
		return_val = 1;
	}

	return return_val;
}
