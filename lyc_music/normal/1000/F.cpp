//QwQcOrZ yyds!!!
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
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
//#define int ll
#define N 500005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,a[N],lenth,From[N],cnt[N],l,r,Ans[N],ans,CNt,Id[N],Nowans[N],top,Sum[N];
map<int,int>Mp;
struct node
{
	int opt,l,r,x,id;
	inline void doread()
	{
		l=read(),r=read();
	}
}q[N];
inline bool Cmp(node x,node y)
{
	return (From[x.l]^From[y.l])?From[x.l]<From[y.l]:((From[x.l]&1)?x.r<y.r:x.r>y.r);
}
inline int hah(int k)
{
	return (k%500005);
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	lenth=ceil(sqrt(n));
	for (int i=1;i<=n/lenth+((n%lenth)>1);i++)
		for (int j=lenth*(i-1)+1;j<=min(lenth*i,n);j++)
			From[j]=i;
	m=read();
	for (int i=1;i<=m;i++)
	{
		q[i].doread();q[i].id=i;
	}
	sort(q+1,q+m+1,Cmp);
	lenth=ceil(sqrt(N));
	for (int i=1;i<=N/lenth+((N%lenth)>1);i++)
		for (int j=lenth*(i-1)+1;j<=min(lenth*i,N);j++)
//		{
			From[j]=i;
//			if (i>=605)cout<<j<<" "<<i<<endl;}
	l=1,r=0;
//	cout<<From[1]<<endl;
	for (int i=1;i<=m;i++)
	{
		while (l<q[i].l) 
		{
			if (cnt[a[l]]==1)
			{
				Sum[From[a[l]]]--;
//				cout<<From[a[l]]<<"!"<<endl;
			}
			--cnt[a[l]];
			if (cnt[a[l]]==1) 
			{
				Sum[From[a[l]]]++;
//				cout<<From[a[l]]<<"!"<<endl;
			}
			l++;
		}
		while (l>q[i].l)
		{
			l--;
			if (cnt[a[l]]==1)
			{
				Sum[From[a[l]]]--;
//				cout<<From[a[l]]<<"!"<<endl;
			}
			++cnt[a[l]];
			if (cnt[a[l]]==1) 
			{
				Sum[From[a[l]]]++;
//				cout<<From[a[l]]<<"!"<<endl;
			}
		}
		while (r<q[i].r)
		{
			r++;
			if (cnt[a[r]]==1)
			{
				Sum[From[a[r]]]--;
//				cout<<From[a[r]]<<"!"<<endl;
			}
			++cnt[a[r]];
			if (cnt[a[r]]==1) 
			{
				Sum[From[a[r]]]++;
//				cout<<From[a[r]]<<"!"<<endl;
			}
		}
		while (r>q[i].r)
		{
			if (cnt[a[r]]==1)
			{
				Sum[From[a[r]]]--;
//				cout<<From[a[r]]<<"!"<<endl;
			}
			--cnt[a[r]];
			if (cnt[a[r]]==1) 
			{
				Sum[From[a[r]]]++;
//				cout<<From[a[r]]<<"!"<<endl;
			}
			r--;
		}
		for (int j=From[500000];j>=1;j--)
			if (Sum[j])
			{
//				cout<<Sum[j]<<endl;
				for (int p=lenth*(j-1)+1;p<=lenth*j;p++)
					if (cnt[p]==1)
					{
						Ans[q[i].id]=p;
//						cout<<p<<" "<<q[i].id<<endl;
						break;
					}
				break;
			}
//		cout<<q[i].l<<" "<<q[i].r<<" "<<
	}
	for (int i=1;i<=m;i++) 
	{
		writeln(Ans[i]);
	}
		
			
}
/*

*/