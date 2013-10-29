#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 1005
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
int dp[N][N];
int main()
{
    int t;
    int i,j,k,am,a;
    int n,m;
    int max;
    int vol[N],val[N],nn[N];
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(i=1;i<=n;i++)
            cin>>vol[i]>>val[i]>>nn[i];
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            for(j=m;j>=0;j--)
            {
                max=-1;
                for(k=0;k<=nn[i]&&k*vol[i]<=j;k++)
                    max=Max(max,dp[i-1][j-k*vol[i]]+k*val[i]);
                dp[i][j]=max;
            }
        cout<<dp[n][m]<<endl;

    }
    return 0;
}
