//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
//#define N 
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int a[1000005];
void BellaKira()
{
	int n=read();int m=read();
	map<int,int>Mp;
	int ans=0;
	for (int i=1;i<=n;i++) 
		a[i]=read(),Mp[a[i]]++;
	sort(a+1,a+n+1);
	while (Mp.size())
	{
		int u=(*Mp.begin()).fi;
		if (Mp[u*m]==0) ans++;
		else Mp[u*m]--;
		Mp[u]--;
		while (Mp.size()&&(*Mp.begin()).se==0) Mp.erase(Mp.begin());
	}
	writeln(ans);
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/