//The Hunting Party - Keys To The Kingdom
//~
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
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
int x,y;
int bl;
void What_will_Diana_eat_today()
{
	x=read(),y=read();
	swap(x,y);
	if (x==0)
	{
		writeln(y);
		return;
	}
	if (y%2==0) y-=1,bl=-1;
	else y+=1,bl=1;
	if (x==1)
	{
		writeln(y);
		return;
	}
	x--;
	y+=(x/4)*4*bl;
	for (int j=(x/4)*4+1;j<=x;j++)
	{
		if (j%4<=2) y-=(j+1)*bl;
		else y+=(j+1)*bl;
	}
	writeln(y);
}
signed main()
{
	int T=read();
	while (T--)
	{
	 	  What_will_Diana_eat_today();
	}
}
/*

*/