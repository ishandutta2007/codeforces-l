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
int T,n;
inline void solve()
{
	read(n);
	if(n%6==0) printf("%d\n",n/6);
	else if(n%6==1) printf("%d\n",n/6);
	else printf("%d\n",n/6+1);
}
int main() {for(read(T);T--;) solve();return 0;}