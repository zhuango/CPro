#include<stdio.h>
#include<stdlib.h>

typedef struct Rec {
	int x;
	int y;
}rec;

typedef struct Res {
	int x;
	int y;
	int area;
}res;

int max(int a, int b)
{
	if(a > b) return a;
	else return b;
}
int min(int a, int b)
{
	if(a > b) return b;
	else return a;
}
int result(Res *res, int a, int b, int count)
{
	int new = a * b;
	if(area > new) {
		count = 0;
		res[count].x = min(a, b);
		rec[count++].y= max(a, b);
	}if(area == new)else {
		res[count].x = min(a, b);
		res[count++].y = max(a, b);
	}
	return count;
}
int main()
{
	Rec rec[4];
	Res res[4];
	int a = 0;
	int b = 0;
	int area;
	int count = 0;
	
	FILE *fin = fopen("packrec.in", "r");
	FILE *fout = fopen("packrec.out", "w");

	for(i = 0; i < 4; i++)
		fscanf(fin, "%d %d", &rec[i].x, &rec[i].y);
	//case 1
	for(i = 0; i < n; i++) {
		a += rec[i].x;
		b = max(b, rec[i].y);
	}
	count = result(res, a, b, area, count);
	a = b = 0;

	//case 2
	for(i = 0; i < 3; i++) {
	       a += rec[i].x;
	       b = max(rec[i].y, b);
	}
	a = max(a, rec[3].x);
	b += rec[3].x;
	count = result(res, a, b, area, count);
	a = b = 0;

	//case 3
	a = max(rec[3].x + rec[2].x,
			rec[3].x + rec[1].x + rec[0].x);
	b = max(rec[3].y, max(rec[0].y, rec[1].y) + rec[2].x);
	count = result(res, a, b, area, count);
	a = b = 0;

	//case 4 & 5
	a = max(rec[0].x, rec[1].x) + 
		rec[2].x + rec[3].x;
	b = max(max(rec[0].y + rec[1].y, rec[2].y), rec[3].y);
	count = result(res, a, b, ares, count);
	a = b = 0;

	//case 6
	a = rec[2].x + rec[3].x;
	if(rec[1].y + 
	b = max(rec[0].y + rec[2].y, rec[1].x + rec[3].y);
