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
//#include <random>
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
		if(x==0){
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
int n,l[200002],r[200002],dp[200002],sta[200002],cnt,q[200002],ql,qr,trans[200002],a[200002];
int main() {
	cin>>n;
	F(i,1,n)read(a[i]),l[a[i]]=(l[a[i]]?l[a[i]]:i),r[a[i]]=i;
	F(i,1,n){
		if(i==r[a[i]]){
			while(l[a[i]]<l[sta[cnt]]){
				--cnt;
			}
			sta[++cnt]=a[i];
		}
	}
	F(i,1,cnt)trans[r[sta[i]]]=l[sta[i]];
	ql=qr=1;
	#define l ql
	#define r qr
	F(i,1,n){
		if(trans[i]){
			while(l<=r&&q[l]<trans[i])++l;
			if(l<=r)dp[i]=max(dp[i-1],dp[q[l]]+i-q[l]-1);
			else dp[i]=dp[i-1];
			dp[i]=max(dp[i],dp[trans[i]-1]+i-trans[i]-1);
		}else dp[i]=dp[i-1];
		while(l<=r&&dp[i]-i>=dp[q[r]]-q[r])--r;
		q[++r]=i;
	}
	cout<<dp[n];
	return 0;
}
/*
13
1 2 3 2 1 3 3 4 5 5 5 4 7
*/