//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,m,a[100005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),a[i]+=a[i-1];
	for(read(m);m--;) {int l,r;read(l),read(r),printf("%d\n",(a[r]-a[l-1])/10);}
	return 0;
}