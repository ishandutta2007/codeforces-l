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
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int a[N],b[N];
void BellaKira()
{
	int n,m;
	string st;
	cin>>n>>m>>st;
	for (int i=0;i<n;i++) a[i]=st[i]-'0';
	int x=0;
	for (int i=0;i<n;i++)
	{
		a[i]^=x;
		// cout<<i<<","<<a[i]<<endl;
		if (!m) continue;
		if (i==n-1)
		{
			b[i]+=m;
			continue;
		}
		if (m%2==0&&a[i]==1||m%2==1&&a[i]==0||i==n-1)
		{
			a[i]=1;
			continue;
		}
		if (m%2==1&&a[i]==1)
		{
			m-=1;
			x^=1;
			b[i]+=1;
		} else
		if (m%2==0&&a[i]==0)
		{
			m-=1;
			x^=1;
			b[i]+=1;
			a[i]^=1;
		}
	}
	for (int i=0;i<n;i++) cout<<a[i];
	cout<<endl;
	for (int i=0;i<n;i++) cout<<b[i]<<" ",b[i]=0;
	cout<<endl;
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/