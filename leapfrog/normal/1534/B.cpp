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
int n,a[400005];
inline void solve()
{
	read(n),a[n+1]=0;for(int i=1;i<=n;i++) read(a[i]);
	ll rs=0;for(int i=1;i<=n;i++) if(a[i]>a[i-1]&&a[i]>a[i+1])
		rs+=a[i]-max(a[i-1],a[i+1]),a[i]=max(a[i-1],a[i+1]);
	for(int i=1;i<=n+1;i++) rs+=abs(a[i]-a[i-1]);
	printf("%lld\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}