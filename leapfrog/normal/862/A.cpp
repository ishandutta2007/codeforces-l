//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=105;int n,K,a[N];
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1),n=unique(a+1,a+n+1)-a-1;
	int rs=K;for(int i=1;i<=n;i++) rs-=a[i]<K,rs+=a[i]==K;
	return printf("%d\n",rs),0;
}