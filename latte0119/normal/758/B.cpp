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
    string S;
    cin>>S;
    string T=S;
    for(int i=4;i<T.size();i++){
        if(T[i-4]!='!')T[i]=T[i-4];
    }
    for(int i=(int)T.size()-5;i>=0;i--){
        if(T[i+4]!='!')T[i]=T[i+4];
    }

    int cnt[256]={};
    rep(i,S.size())if(S[i]=='!')cnt[T[i]]++;
    cout<<cnt['R']<<" "<<cnt['B']<<" "<<cnt['Y']<<" "<<cnt['G']<<endl;
    return 0;
}