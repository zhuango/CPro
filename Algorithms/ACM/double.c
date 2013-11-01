#include<stdio.h>
#include<math.h>

int main(void)
{
	double a = atan(1.0);
	printf("%.100lf\n", 4.0 * a);
	a = -0xfffffffffffffff;
	printf("%.100lf\n", a);

	return 0;
}
