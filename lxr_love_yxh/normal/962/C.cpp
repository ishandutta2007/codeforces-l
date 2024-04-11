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
string s;
int main(){
	cin>>s;
	int ans=inf;
	for(int i=1;i<(1<<(int)s.size());i++){
		int val=0;string tmp;
		for(int j=0;j<s.size();j++)if(i&(1<<j)){
			tmp+=s[j];val=val*10+s[j]-'0';
		}
		if(tmp[0]=='0'){
			continue;
		}
		int vv=sqrt(val);
		if(vv*vv==val){
			ans=min(ans,(int)s.size()-__builtin_popcount(i));
		}
	}
	if(ans>=s.size()){
		puts("-1");
	}else{
		cout<<ans<<endl;
	}
	return 0;
}