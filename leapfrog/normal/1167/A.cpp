//Coded by leapfrog on 2021.10.27 {{{
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
const int N=105;int n;char ch[N];
inline void solve()
{
	read(n),scanf("%s",ch+1);int ps=0;
	for(int i=1;i<=n;i++) if(ch[i]=='8') {ps=i;break;}
	if(!ps||n-ps+1<11) return puts("NO"),void();else puts("YES");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}