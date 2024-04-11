#include<bits/stdc++.h>
using namespace std;

#define int long long 

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

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

signed main(){
	int N,M,K;
	cin>>N>>M>>K;

	if(K<N){
		cout<<K+1<<" "<<1<<endl;
		return 0;
	}
	K-=N;

	
	int y=N-2*(K/(2*(M-1)));
	K%=(2*(M-1));

	int x;
	if(K<M-1){
		x=2+K;
	}
	else{
		y--;
		x=M-(K-(M-1));
	}
	cout<<y<<" "<<x<<endl;
	return 0;
}