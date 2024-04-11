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
//#define int ll
#define N 400005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int head[2*N],to[2*N],nxt[2*N],ans[N],n,size[N],cnt,mx[N][2],cut[N],root,u,v;
void ad(int u,int v)
{
    cnt++;
    to[cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
int dfs1(int u,int fa)
{
    bool flag=true;
    int size=0,siz;
    for(int p=head[u];p;p=nxt[p])
    {
        int v=to[p];
        if(v==fa) continue;
        siz=dfs1(v,u);
        size+=siz;
        flag=flag&(siz<=n/2);
    }
    flag=flag&(n-size-1<=n/2);
    if(flag) root=u; 
    return size+1;
}
void dfs2(int u,int fa)
{
    size[u]=1;
    for(int p=head[u];p;p=nxt[p])
    {
        int v=to[p];
        if(v==fa) continue;
        dfs2(v,u);
        size[u]+=size[v];
        if(size[v]>n/2) continue;
        if(size[v]>mx[u][0]) mx[u][1]=mx[u][0],mx[u][0]=size[v];
        else if(size[v]>mx[u][1]) mx[u][1]=size[v];
    }
}
void dfs3(int u,int maxx,int fa)
{
    cut[u]=maxx;
    for(int p=head[u];p;p=nxt[p])
    {
        int v=to[p];
        if(v==fa) continue;
        if(n-size[u]<=n/2) maxx=max(maxx,n-size[u]);
        if(size[v]==mx[u][0]) dfs3(v,max(maxx,mx[u][1]),u);
        else dfs3(v,max(maxx,mx[u][0]),u);
    }
    if(n-size[u]-cut[u]<=n/2) ans[u]=true;
}
signed main()
{
	n=read();
    for(int i=1;i<=n-1;i++)
    {
        u=read(),v=read();
        ad(u,v),ad(v,u);
    }
    dfs1(1,0);
    dfs2(root,0);
    dfs3(root,0,0);
    for(int i=1;i<=n;i++)
    	writesp(ans[i]);
}
/*

*/