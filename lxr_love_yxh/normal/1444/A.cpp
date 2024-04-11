/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
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
int t;
int vp,q;
map<int,int>cnt;
signed main(){
	cin>>t;
	while(t--){
		cnt.clear();
		cin>>vp>>q;
		if(vp%q!=0){
			cout<<vp<<endl;
			continue;
		}
		for(int i=2;i*i<=q;i++){
			if(q%i==0){
				while(q%i==0){
					q/=i;
					cnt[i]++;
				}
			}
		}
		if(q!=1)cnt[q]++;
		int ans=0;
		for(auto p:cnt){
			int v=vp;
			while(v%p.first==0)v/=p.first;
			for(int i=0;i<p.second-1;i++){
				v*=p.first;
			}
			ans=max(ans,v);
		}
		cout<<ans<<endl;
	}
	return 0;
}