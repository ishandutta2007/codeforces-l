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
int n,x,y,qwq,qaq;
char s[100002];
ll a,b,c,ans;
vector<int>vec;
inline int calc(){
	sort(vec.begin(),vec.end());
	int cnt=0;
	for(int i:vec){
		if(i<=qaq)qaq-=i,++cnt;
		else break;
	}
	return cnt;
}
int main() {
	F(iakioi,1,read()){
		read(n);
		read(a,b,c);ans=x=y=qwq=qaq=0;vec.clear();
		scanf("%s",s+1);
		int lst=0;
		F(i,1,n){
			if(s[i]!=s[i+1]){
				if(s[i]=='0'){
					x+=i-lst;
					qwq+=i-lst-1;
					if(lst!=0&&i!=n)vec.push_back(i-lst-1);
				}else{
					y+=i-lst;
					qaq+=i-lst-1;
				}
				lst=i;
			}
		}
		if(qwq<qaq){
			ans+=(a+b)*qwq+b;
			qaq-=qwq;
			x-=qwq;
			y-=qwq;
			--y;
			qwq=0;
			--qaq;
			if(b<c)write(ans,'\n');
			else write(ans+(b-c)*min(x,y-1),'\n');
		}else{
			ans+=(a+b)*qaq;
			qwq-=qaq;
			x-=qaq;
			y-=qaq;
			if(qwq==0){
				if(b<c)write(ans,'\n');
				else write(max(ans,ans+(b-c)*min(x,y-1)),'\n');
			}else{
				if(b<c)write(ans+a,'\n');
				else{
					write(ans+a+(b-c)*calc(),'\n');
				}
			}
		}
	}
	return 0;
}
/*
1
1 100000000 200000000 100000000
0 
*/