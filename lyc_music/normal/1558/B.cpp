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
//#define mod 998244353
#define int ll
#define N 4000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,mod,dp[N],s,f[N];
signed main()
{
	n=read(),mod=read();
	for (re int i=1;i<=n;i++)
	{
		dp[i]=(dp[i]+dp[i-1])%mod;
		f[i]=dp[i];
		if (i==1) f[i]=1;
		dp[i+1]=(dp[i+1]+f[i])%mod;
		for (re int j=2*i;j<=n;j+=i)
		{
			dp[j]=(dp[j]+f[i])%mod;
			if (j+(j/i)<=n) dp[j+(j/i)]=(dp[j+(j/i)]-f[i]+mod)%mod;
		}
	}
	writeln(dp[n]);
			
		
		
}
/*

*/