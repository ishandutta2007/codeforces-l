//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,a[1005];map<int,char>mp;
int main()
{
	for(read(T);T--;)
	{
		read(n),mp.clear();int tag=0;
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=1;i<=n;i++) if(mp[a[i]]) tag=1;else mp[a[i]]=1;
		if(tag) puts("YES");else puts("NO");
	}
	return 0;
}