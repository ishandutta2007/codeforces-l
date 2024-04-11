#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

const int mod=1000003;

int fact[mod],inv[mod];
int mpow(int n,int m){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}

int comb(int n,int k){
    return fact[n]*inv[k]%mod*inv[n-k]%mod;
}

signed main(){
    fact[0]=1;
    for(int i=1;i<mod;i++)fact[i]=fact[i-1]*i%mod;
    inv[mod-1]=mpow(fact[mod-1],mod-2);
    for(int i=mod-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;

    int N,C;
    cin>>N>>C;
    cout<<(comb(N+C,C)-1+mod)%mod<<endl;
    return 0;
}