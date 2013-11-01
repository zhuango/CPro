#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#define BITPERWORD      32
#define SHIFT           5
#define MASK            0x1F

#define N 10000000
int a[1 + N/BITPERWORD];

void set(int i){                a[i >> SHIFT] |=  (1 << (i & MASK)); }
void clr(int i){                a[i >> SHIFT] &= ~(1 << (i & MASK)); }
int test(int i){ return a[i >> SHIFT] &   (1 << (i & MASK)); }

int main(void)
{
        int *a, i, j, data;
        char *b;
        b = malloc(1000000 * sizeof(char));
        a = malloc(1000000 * sizeof(int));
        if((data = open("/home/Og/Pro/CPro/Algorithms/Beauty_of_Programming/ID/result", O_RDONLY)) < 0){
            perror("open");
            exit(EXIT_FAILURE);
        }
        if(dup2(data, 0) < 0){
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        for(i = 0; i < 1000000; i++){
                scanf("%d", &a[i]);
                b[i] = 0;
                clr(i);
        }

        for(i = 0; i < 1000000; i++){
                set(a[i]);
                b[a[i]] ++;
        }
        for(i = 0; i < 1000000; i++)
                if(test(i))
                        for(j = 0; j < b[i]; j++){
                                //printf("%d\n", i);
                                a[i] = b[i];
                        }
        return 0;
}
