//Coded by leapfrog on 2021.10.29 {{{
//
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
const int N=2000005;
int n,a[N];
int main()
{
	read(n);for(int i=1;i<=n+n;i++) read(a[i]);
	char fg=0;for(int i=2;i<=n+n;i++) if(a[i]!=a[i-1]) fg=1;
	if(!fg) return puts("-1"),0;
	sort(a+1,a+n+n+1);for(int i=1;i<=n+n;i++) printf("%d%c",a[i],i==n+n?'\n':' ');
	return 0;
}