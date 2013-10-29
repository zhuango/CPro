#include<stdio.h>
#include<stdlib.h>

#define BITPERWORD	32
#define SHIFT		5
#define MASK		0x1F

#define N 10000000
int a[1 + N/BITPERWORD];

void set(int i){		a[i >> SHIFT] |=  (1 << (i & MASK)); }
void clr(int i){		a[i >> SHIFT] &= ~(1 << (i & MASK)); }
int test(int i){ return a[i >> SHIFT] &   (1 << (i & MASK)); }
