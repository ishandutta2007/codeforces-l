#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int n,k;
    cin>>n>>k;

    vint vec(n);rep(i,n)vec[i]=i;
    int x=0;
    for(int i=0;i<k;i++){
        int a;cin>>a;
        x=(x+a)%vec.size();
        cout<<vec[x]+1<<" ";
        vec.erase(vec.begin()+x);
        if(x==vec.size())x=0;
    }puts("");
    return 0;
}