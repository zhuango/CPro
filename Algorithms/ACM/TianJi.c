#include<stdio.h>
#include<stdlib.h>

void insert_sort(int array[], int num);

int main(void)
{
	int *TianJi;
	int *QiWang;
	int Tfast, Tslow;
	int Qfast, Qslow;
	int n;
	int j;
	int Rank = 0;
	
	for(;;) {
		scanf("%d", &n);
		if(n == 0) break;
		TianJi = malloc(sizeof(int) * n);
		QiWang = malloc(sizeof(int) * n);

		for(j = 0; j < n; j++){
			scanf("%d", &TianJi[j]);
		}

		for(j = 0; j < n; j++) {
			scanf("%d", &QiWang[j]);
		}
		
		insert_sort(TianJi, n);
		insert_sort(QiWang, n);

		Tfast = Qfast = n - 1;
		Tslow = Qslow = 0;
		Rank = 0;
	
		while(Tfast >= Tslow) {
			if( TianJi[Tfast] > QiWang[Qfast]) {
				Rank += 200;
				Tfast --;
				Qfast --;
			}else if(TianJi[Tslow] > QiWang[Qslow]) {

				Rank += 200;
				Tslow ++;
				Qslow ++;
			}else{
				if(TianJi[Tslow] < QiWang[Qfast])
					Rank -= 200;
				Tslow ++;
				Qfast --;
			}
		
		}
		free(TianJi);
		free(QiWang);
		printf("%d\n", Rank);
	}

	exit(EXIT_SUCCESS);
}

void insert_sort(int array[], int num)
{
	int cur;
	int tmp;
	int pos, i;

	for(i = 1; i < num; i++) {
		cur = array[i];
		pos = i - 1;

		while(pos >= 0 && array[pos] > cur){
			array[pos + 1] = array[pos];
			pos = pos - 1;
		}

		array[pos + 1] = cur;

	}

}
