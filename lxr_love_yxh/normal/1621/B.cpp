/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-9;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int T,n;
int l[200005],r[200005],c[200005];
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>l[i]>>r[i]>>c[i];
		}
		int pl=1,pr=1,pall=1;
		cout<<c[1]<<'\n';
		for(int i=2;i<=n;i++){
			if(l[i]<l[pl]||(l[i]==l[pl]&&c[i]<c[pl]))pl=i;
			if(r[i]>r[pr]||(r[i]==r[pr]&&c[i]<c[pr]))pr=i;
			if(l[i]<l[pall]||(l[i]==l[pall]&&r[i]>r[pall])||(l[i]==l[pall]&&r[i]==r[pall]&&c[i]<c[pall]))pall=i;
			int ans=c[pl]+c[pr];
			if(l[pall]==l[pl]&&r[pall]==r[pr])ans=min(ans,c[pall]);
			cout<<ans<<'\n';
		}
	}
	return 0;
}