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
ll n;
inline void solve()
{
	read(n);
	if(n<=6) printf("%d\n",15);else printf("%lld\n",(n+1)/2*5);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}