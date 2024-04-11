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

int N,L,R;
int A[111111];
int B[111111];
signed main(){
    scanf("%lld%lld%lld",&N,&L,&R);
    rep(i,N)scanf("%lld",&A[i]),A[i]=-A[i];

    vpint vec;
    rep(i,N){
        int p;scanf("%lld",&p);
        vec.pb({p,i});
    }
    sort(all(vec));
    int ma=A[vec[0].se];
    for(int i=1;i<N;i++){
        int j=vec[i].se;
        if(ma>=A[j]){
            B[j]=ma+1-A[j];
            ma++;
        }
        else ma=A[j];
    }
    rep(i,N)B[i]+=L;

    rep(i,N)if(B[i]>R){
        puts("-1");
        return 0;
    }
    rep(i,N)printf("%lld ",B[i]);
    puts("");
    return 0;
}