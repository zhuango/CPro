/*
ID: og192li1
LANG: C
PROG: clocks
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
 
#define INF 60000	/* bigger than longest possible path */
 
char *movestr[] = { "abde", "abc", "bcef", "adg", "bdefh", "cfi", "degh",
                    "ghi", "efhi" };
 
int movedist[9][9];
int clock[9];
 
int bestmove[9];
int nbestmove;
 
/* translate move strings into array "movedist" of which clocks change on each move */
void
mkmove(void)
{
    int i;
    char *p;
 
    for(i=0; i<9; i++)
	for(p=movestr[i]; *p; p++)
	    movedist[i][*p-'a'] = 3;
}
 
/* apply some number of each move from k to 9 */
/* move contains the number of times each move is applied */
void
solve(int *move, int k)
{
    int i, j, n, rep;
 
    if(k == 9) {
	for(j=0; j<9; j++)
	    if(clock[j]%12 != 0)
		return;
 
	/* we have a successful sequence of moves */
	n = 0;
	for(j=0; j<9; j++)
	    n += move[j];
 
	if(nbestmove == 0 || n < nbestmove) {
	    nbestmove = n;
	    for(j=0; j<9; j++)
		bestmove[j] = move[j];
	}
	return;
    }
 
    /*
     * the for loop counts down so we
     * generate smaller numbers first by
     * trying more of small numbered
     * moves before we try less of them.
     */
    for(rep=3; rep>=0; rep--) {
	/* apply move k rep times */
	for(i=0; i<rep; i++)
	    for(j=0; j<9; j++)
		clock[j] += movedist[k][j];
	move[k] = rep;
 
	solve(move, k+1);
 
	/* undo move */
	for(i=0; i<rep; i++)
	    for(j=0; j<9; j++)
		clock[j] -= movedist[k][j];
    }
}
 
void
main(void)
{
    FILE *fin, *fout;
    int i, j, move[9];
    char *sep;
 
    fin = fopen("clocks.in", "r");
    fout = fopen("clocks.out", "w");
    assert(fin != NULL && fout != NULL);
 
    mkmove();
 
    for(i=0; i<9; i++)
	fscanf(fin, "%d", &clock[i]);
 
    solve(move, 0);
 
    sep = "";
    for(i=0; i<9; i++) {
	for(j=0; j<bestmove[i]; j++) {
	    fprintf(fout, "%s%d", sep, i+1);
	    sep = " ";
	}
    }
    fprintf(fout, "\n");
 
    exit(0);
}
