//QwQcOrZ yyds!!!
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
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
#define N 505
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
string st[N];
int n,a[N],f[N][N],ans;
void ad(int &x,int y)
{
	x=(x+y)%mod;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		char ch=gc();
		while (ch!='+'&&ch!='-') ch=gc();
		st[i]+=ch;
		if (st[i]=="+") a[i]=read();
	}
	for (int now=1;now<=n;now++)
		if (a[now])
		{
			memset(f,0,sizeof(f));
			f[0][0]=1;
			for (int i=1;i<=n;i++)
			{
				if (i==now)
				{
					for (int j=0;j<=n;j++) f[i][j]=f[i-1][j];
				} else
				{
				if (st[i]=="+")
				{
					if (a[i]<a[now]||a[i]==a[now]&&now<i)
					{
						for (int j=1;j<=n;j++)
							ad(f[i][j],f[i-1][j-1]);
					}
					else
					{
						for (int j=0;j<=n;j++)
							ad(f[i][j],f[i-1][j]);
					}
				}
				else
					if (i<now)
					{
						for (int j=0;j<=n;j++)
							ad(f[i][max(0ll,j-1)],f[i-1][j]);
					}
					else
					{
						for (int j=1;j<=n;j++)
							ad(f[i][j-1],f[i-1][j]);
					}
				for (int j=0;j<=n;j++) ad(f[i][j],f[i-1][j]);
				}
					
			}
			int sum=0;
			for (int i=0;i<=n;i++) ad(sum,f[n][i]);
			ad(ans,sum*a[now]%mod);
		}
	writeln(ans);
}
/*

*/