#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int N,M;cin>>N>>M;
    vector<string>A(N),B(M);
    rep(i,N)cin>>A[i];
    rep(i,M)cin>>B[i];

    set<string>s;rep(i,N)s.insert(A[i]);
    int cnt=0;
    rep(i,M){
        if(s.find(B[i])!=s.end()){
            cnt++;
        }
    }

    if(cnt&1)M--;
    if(N>M)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}