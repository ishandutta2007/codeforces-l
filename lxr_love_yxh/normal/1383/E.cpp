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
int n;
string s;
int dist[1000005],dp[1000005],nxt0[1000005],nxt1[1000005],prv[1000005];
int main(){
	cin>>s;n=s.size();s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')dist[i]=dist[i-1]+1;
	}
	if(dist[n]==n){
		cout<<n<<endl;
		return 0;
	}
	for(int i=0;i<=1e6;i++)prv[i]=n+1;
	for(int i=n;i>=1;i--){
		nxt1[i]=prv[0];
		nxt0[i]=prv[dist[i]+1];
		prv[dist[i]]=i;
	}
	int pos=1;
	while(s[pos]=='0')pos++;
	dp[pos]=1;
	for(int i=pos;i<=n;i++){
		(dp[nxt0[i]]+=dp[i])%=mod;
		(dp[nxt1[i]]+=dp[i])%=mod;
	}
	int ans=0;
	for(int i=pos;i<=n;i++){
		if(dist[i]<=dist[n]){
			(ans+=dp[i])%=mod;
		}
	}
	cout<<1ll*ans*pos%mod<<endl;
	return 0;
}