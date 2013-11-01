#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10005];
int main()
{
	  int N,i,t,j;
	    while(scanf("%d",&N)!=EOF)
		      {
			          i=N;
				      while(i--) scanf("%d",&a[i]);
				          sort(a,a+N);t=0;
				          for(i=0,j=N-1;i<=j;i++,j--)
						      {
							            if(t==0)t=1;
								          else printf(" ");
									        if(i==j)printf("%d",a[i]);
										      else printf("%d %d",a[j],a[i]);
										          }
					      printf("\n");
					        
					        }
	      return 0;
}
