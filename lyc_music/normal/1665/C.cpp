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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n;
int ans;
void BellaKira()
{
	n=read();
	vector<int>a(n+5,0);
	ans=0;
	for (int i=2;i<=n;i++)
	{
		int x=read();
		a[x]++;
	}
	a.push_back(1);
	sort(a.rbegin(),a.rend());
	while (a.back()==0) a.pop_back();
	int lim=a.size();
	priority_queue<int>q;
	for (int i=0;i<a.size();i++)
		{
			q.push(a[i]+i);
		}
	while (q.top()>lim)
	{
		q.push(q.top()-1);
		q.pop();
		lim++;
	}
	writeln(lim);
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