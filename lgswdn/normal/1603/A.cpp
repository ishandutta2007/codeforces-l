#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef unsigned long long ull;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=1e6+9;
int T,n,a[N];

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) a[i]=read();
		bool ans=1;
		rep(i,1,n) {
			bool flag=0;
			for(int j=2;j<=i+1&&(!flag);j++) flag|=(a[i]%j!=0);
			if(!flag) {ans=0; break;}
		}
		if(!ans) puts("NO");
		else puts("YES");
	}
	return 0;
}