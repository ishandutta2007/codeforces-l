//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
pa dp[N];
int n,m,l,s[N],a[N];
string st;
pa check(int x)
{
	dp[0].fi=0;
	for (int i=1;i<=n;i++)
		if (i<l)
		{
			if (dp[i-1].fi<s[i]-x) 
			{
				dp[i].fi=s[i]-x;
				dp[i].se=1;
			} else
				dp[i]=dp[i-1];
		}
		else
		{
			if (dp[i-1].fi<dp[i-l].fi+s[i]-s[i-l]-x)
			{
				dp[i].fi=dp[i-l].fi+s[i]-s[i-l]-x;
				dp[i].se=dp[i-l].se+1;
			}
			else 
			if (dp[i-1].fi>dp[i-l].fi+s[i]-s[i-l]-x)
			dp[i]=dp[i-1];
			else
			{
				dp[i]=dp[i-1];
				dp[i].se=min(dp[i-1].se,dp[i-l].se+1);
			}
		}
//	cout<<x<<endl;
//	for (int i=1;i<=n;i++) cout<<i<<" "<<dp[i].fi<<" "<<dp[i].se<<endl;
	return dp[n];
}
signed main()
{
	cin>>n>>m>>l;
	if (m*l>=n) puts("0");
	else
	{
		cin>>st;
		st=' '+st;
		for (int i=1;i<=n;i++)
		{
			if (st[i]>='a'&&st[i]<='z') a[i]=0;
			else a[i]=1;
			s[i]=s[i-1]+a[i];
//			cout<<i<<" "<<s[i]<<endl;
		}
		int L=0,R=n,Ans=n,mid;
		pa ans={0,0};
		while (L<=R)
		{
			mid=L+(R-L)/2;
			pa u=check(mid);
			if (u.se<=m)
			{
				ans=u;
				ans.se=mid;
				R=mid-1;
			} else L=mid+1;
		}
//		cout<<mid<<"!"<<ans.fi<<" "<<ans.se<<endl;
		Ans=min(Ans,s[n]-ans.fi-m*ans.se);
		for (int i=1;i<=n;i++)
		{
			a[i]^=1;
			s[i]=s[i-1]+a[i];
		}
//		cout<<ans.fi<<endl;
		L=0,R=n;
		ans={0,0};
		while (L<=R)
		{
			mid=L+(R-L)/2;
			pa u=check(mid);
			if (u.se<=m)
			{
				ans=u;
				ans.se=mid;
				R=mid-1;
			} else L=mid+1;
		}
		Ans=min(Ans,s[n]-ans.fi-m*ans.se);
		writeln(Ans);
	}
}
/*

*/