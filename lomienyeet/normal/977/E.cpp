// got rid of my other template because *a few people will complain*
#include <bits/stdc++.h>
// #include <bits/extc++.h> // use if non-cf & non-c++20
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> // use if cf & C++20 (iconv.h got deprecated or sth i dont remember)
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define ff first
#define ss second
#define rofl exit(1);
#define debug(x) cerr<<(#x)<<"::"<<(x)<<"\n";
template<typename T> using OST=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1e9+7,mod2=998244353,inf=1e18;
void yes(){cout<<"YES\n";}
void no(){cout<<"NO\n";}
int bm(int b,int p,int m=mod){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
const int mxN=2e5+5;
vector<int> adj[mxN];
int deg[mxN],vis[mxN];
bool dfs(int u){
    if(vis[u]||deg[u]!=2)return 0; // r u fucking srsa
    vis[u]=1;
    bool z=1;
    for(auto i:adj[u]){
        if(!vis[i])z&=dfs(i);
    }
    return z;
}
void eat(){
    /* 
     */
    int n,m;
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans+=dfs(i);
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}