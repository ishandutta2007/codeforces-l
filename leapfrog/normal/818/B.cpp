//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int n,m,vl[105],a[105];char vs[105];
inline void fz(int x,int w)
{
	if(vl[x]&&vl[x]!=w) puts("-1"),exit(0);else if(vl[x]) return;
	if(vs[w]) puts("-1"),exit(0);else vs[vl[x]=w]=1;
}
int main()
{
	read(n,m);for(int i=1;i<=m;i++) read(a[i]);
	for(int i=1;i<m;i++) fz(a[i],(a[i+1]-a[i]+n-1)%n+1);
	for(int i=1,j=1;i<=n;i++) if(!vl[i]) {while(vs[j]) j++;vl[i]=j,vs[j]=1;}
	for(int i=1;i<=n;i++) printf("%d%c",vl[i],i==n?'\n':' ');
	return 0;
}