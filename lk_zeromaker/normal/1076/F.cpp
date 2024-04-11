/*
Author: CNYALI_LK
LANG: C++
PROG: 1076F.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<ll,ll> pii;
template<class T,class T2>ll chkmin(T &a,T2 b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>ll dcmp(T a,T b){return a>b;}
template<ll *a>ll cmp_a(ll x,ll y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
namespace io {
    const ll SIZE = (1 << 21) + 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; ll f, qr;
    // getchar
    #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
    // prll the remaining part
    inline void flush () {
        fwrite (obuf, 1, oS - obuf, stdout);
        oS = obuf;
    }
    // putchar
    inline void putc (char x) {
        *oS ++ = x;
        if (oS == oT) flush ();
    }
    // input a signed lleger
    inline void read (ll &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
    }
    inline void read (char &x) {
        x=gc();
    }
    inline void read(char *x){
        while((*x=gc())=='\n' || *x==' '||*x=='\r');
        while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
    }
    template<typename A,typename ...B>
    inline void read(A &x,B &...y){
        read(x);read(y...);
    }
    // prll a signed lleger
    inline void write (ll x) {
        if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
        while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
        while (qr) putc (qu[qr --]);
    }
    inline void write (char x) {
        putc(x);
    }
    inline void write(const char *x){
        while(*x){putc(*x);++x;}
    }
    inline void write(char *x){
        while(*x){putc(*x);++x;}
    }
    template<typename A,typename ...B>
    inline void write(A x,B ...y){
        write(x);write(y...);
    }
    //no need to call flush at the end manually!
    struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
ll ls0,ls1,n,k,x[1000005],y[1000005];
void Orz(ll s0,ll s1){
	ll las0=ls0,las1=ls1;
	ls0=ls1=k+1;
	if(las0<=k){
		if(s0+las0<=s1*k){
			if(s1==1)chkmin(ls1,1);
			else{ 
				if((s1-1)/k+1<=s0)chkmin(ls1,1);
				else if((s1-1)/k+1<=s0+1)chkmin(ls1,(s1-1)%k+1);
			}
		}
		if(s1<=s0*k){
			if(s0==1)chkmin(ls0,1);
			else{
				if((s0+las0-1)/k+1<=s1)chkmin(ls0,1);
				else if((s0+las0-1)/k+1<=s1+1)chkmin(ls0,(s0+las0-1)%k+1);
			}
		}
	}

	if(las1<=k){
		if(s1+las1<=s0*k){
			if(s0==1)chkmin(ls0,1);
			else{ 
				if((s0-1)/k+1<=s1)chkmin(ls0,1);
				else if((s0-1)/k+1<=s1+1)chkmin(ls0,(s0-1)%k+1);
			}
		}
		if(s0<=s1*k){
			if(s1==1)chkmin(ls1,1);
			else{
				if((s1+las1-1)/k+1<=s0)chkmin(ls1,1);
				else if((s1+las1-1)/k+1<=s0+1)chkmin(ls1,(s1+las1-1)%k+1);
			}
		}
	}
}
int main(){
#ifdef cnyali_lk
	freopen("1076F.in","r",stdin);
	freopen("1076F.out","w",stdout);
#endif
	read(n,k);
	for(ll i=1;i<=n;++i)read(x[i]);
	for(ll i=1;i<=n;++i){
		read(y[i]);
		Orz(x[i],y[i]);
	}
	if(ls0<=k || ls1<=k)write("YES\n");else write("NO\n");
	return 0;
}