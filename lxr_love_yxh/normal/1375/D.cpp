/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
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
int T,n;
int a[1005];
bool order(){
	for(int i=1;i<n;i++)if(a[i]>a[i+1])return false;return true;
}
bool got[1005];
int mex(){
	memset(got,0,sizeof got);
	for(int i=1;i<=n;i++)got[a[i]]=1;
	for(int i=0;i<=n;i++)if(!got[i])return i;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		vector<int>opr;
		while(!order()){
			int mx=mex();
			if(mx!=n){
				a[mx+1]=mx;
				opr.push_back(mx+1);
			}else{
				for(int i=1;i<=n;i++){
					if(a[i]!=i-1){
						a[i]=mx;
						opr.push_back(i);
						break;
					}
				}
			}
		}
		cout<<opr.size()<<endl;
		for(auto x:opr)cout<<x<<" ";cout<<endl;
	}
	return 0;
}