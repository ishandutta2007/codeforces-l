#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

inline int topbit(unsigned long long x){
    return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){
    return __builtin_parity(x);
}

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int calc(int a,int b){
	if(b==0)return 0;
	int g=gcd(a,b);

	a/=g;
	b/=g;

	int aa=a;

	int nex=0;
	for(int i=2;i*i<=aa;i++){
		if(a%i)continue;
		chmax(nex,b/i*i);
		while(aa%i==0)aa/=i;
	}
	if(aa>1)chmax(nex,b/aa*aa);

	return b-nex+calc(a,nex);
}

signed main(){
	int x,y;
	cin>>x>>y;
	cout<<calc(x,y)<<endl;
    return 0;
}