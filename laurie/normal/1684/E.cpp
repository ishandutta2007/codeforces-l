//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x) {
		if(x==0) {
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
int a[100002],b[100002],cnt,n,k;
bool vis[100002];
inline bool check(int v) {
	int qwq=0;
	F(j,0,v-1)if(!vis[j])++qwq;
	return qwq<=k;
}
int main() {
	F(dsaf,1,read()) {
		n=read();k=read();
		F(i,1,n)read(a[i]);
		F(i,0,n+1)vis[i]=false;
		sort(a+1,a+n+1);
		int res=0,mex=0;
		a[0]=-1;
		F(i,1,n)if(a[i]!=a[i-1])++res;F(i,1,n)if(a[i]<=n)vis[a[i]]=true;
		a[n+1]=1e9;
		F(i,1,n+1)if(a[i]-a[i-1]>=2) {
			mex=a[i-1]+1;
			break;
		}
		int l=mex,r=n;
		while(l<r) {
			int mid=(l+r+1)>>1;
			if(check(mid))l=mid;
			else r=mid-1;
		}
		cnt=0;
		F(i,1,n) {
			if(a[i]!=a[i-1]) {
				if(a[i]>=l)b[++cnt]=1;
			} else ++b[cnt];
		}
		sort(b+1,b+cnt+1);
		int ans=res-l;F(j,0,l-1)if(!vis[j])++ans;
		F(i,1,cnt) {
			if(b[i]<=k)--ans,k-=b[i];
			else break;
		}
		write(ans,'\n');
	}
	return 0;
}