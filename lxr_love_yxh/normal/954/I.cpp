/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
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
string s,t;
vector<int>z_function(const string& s){
    int n=(int)s.size();
    vector<int>z(n);
    int l=0,r=1;
    for(int i=1;i<n;++i){
        if(i<r){
            z[i]=min(z[i-l],r-i);
        }
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]){
            ++z[i];
        }
        if (i+z[i]>=r){
            l=i;
            r=i+z[i];
        }
    }
    return move(z);
}
bool bs[64][125005];
string get_str(int mask,string ori){
	string ret="";
	for(char c:ori){
		ret+=(mask&(1<<c-'a'))?'1':'0';
	}
	return move(ret);
}
void calc(string a,string b,int id){
	string tmp=a+"$"+b;
	vector<int>match=z_function(tmp);
	for(int i=a.size()+1;i<match.size();i++){
		int pos=i-a.size()-1;
		if(match[i]>=a.size())bs[id][pos]=1;
	}
}
int main(){
	cin>>s>>t;
	for(int i=1;i<64;i++){
		calc(get_str(i,t),get_str(i,s),i);
	}
	for(int i=0;i<=s.size()-t.size();i++){
		int hv=0,ans=0;
		for(int j=1;j<64;j++){
			if(hv&j)continue;
			if(bs[j][i])hv|=j,ans++;
		}
		printf("%d ",6-ans);
	}
	return 0;
}