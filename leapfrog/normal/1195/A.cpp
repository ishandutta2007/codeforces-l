//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,K,tn[100005];
int main()
{
	read(n),read(K);for(int i=1,x;i<=n;i++) read(x),tn[x]++;
	int tt=0;for(int i=1;i<=K;i++) tt+=tn[i]>>1;
	return printf("%d\n",(n+1)/2+tt),0;
}