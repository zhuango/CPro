#include<stdio.h>
#include<stdlib.h>
#include<sys/select.h>

int main(void)
{
	long i = 0;
	struct timeval t;
	t.tv_sec = 0;
	t.tv_usec = 42000;
	for(;;){
		for(i =0; i < 10000000; i++){}
		select(5, NULL, NULL, NULL, &t);
		t.tv_sec = 0;
		t.tv_usec = 42000;
	}

}
