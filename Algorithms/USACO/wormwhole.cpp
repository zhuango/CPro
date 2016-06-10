/*
ID: og192li1
PROG: wormhole
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
 
struct Node{
	int x,y,vis,l;
	bool operator <(const Node &rhs)const{
		return x<rhs.x;
	}
};
 
int n,ans=0,x[20],y[20],x3[20],y3[20],r[20],label[20],cur=0,flag;
vector<Node> g[20];
bool cmp(int ii,int jj){return y[ii]<y[jj];}
 
void isloop(int y,int x){
	int lx=x,ly=y;
	while(lx<g[ly].size()){
		if(g[ly][lx].vis) {
			flag=1;
			return;
		}
		g[ly][lx].vis=1;
		int t1=g[ly][lx].l;
		lx=x3[label[t1]],ly=y3[label[t1]];
		lx++;
 
	}
}
 
bool check(){
	for(int i=0;i<=cur;i++)
		for(int j=0;j<g[i].size();j++)
			g[i][j].vis=0;
	flag=0;
	for(int i=0;i<=cur;i++)
		for(int j=0;j<g[i].size();j++){
 
			for(int n=0;n<=cur;n++)
				for(int m=0;m<g[n].size();m++)
					g[n][m].vis=0;
 
				isloop(i,j);
 
		}
	if(flag) return true;
	else return false;
}
 
void solve(int c){
	if(c>n/2){
		if(check()) ans++;
		return;
	}
	int pos;
	for(int i=0;i<n;i++) 
		if(label[i]<0){
			pos=i;
			break;
		}
	for(int i=pos+1;i<n;i++)
		if(label[i]<0){
			label[i]=pos;
			label[pos]=i;
			solve(c+1);
			label[i]=-1;
		}
	label[pos]=-1;
}
 
int main(){
	freopen("wormhole.in","r",stdin);
	freopen("wormhole.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	for(int i=0;i<n;i++) r[i]=i;
	sort(r,r+n,cmp);
	g[0].push_back((Node){x[r[0]],y[r[0]],0,r[0]});
	for(int i=1;i<n;i++){
		int l1=r[i],l2=r[i-1];
		if(y[l1]==y[l2]) g[cur].push_back((Node){x[l1],y[l1],0,l1});
		else g[++cur].push_back((Node){x[l1],y[l1],0,l1});
	}
	for(int i=0;i<n;i++) sort(g[i].begin(),g[i].end());
	for(int i=0;i<=cur;i++)
		for(int j=0;j<g[i].size();j++){
			int t1=g[i][j].l;
			x3[t1]=j;y3[t1]=i;
		} 
	memset(label,-1,sizeof(label));
	solve(1);
	cout<<ans<<endl;
 
	return 0;
}