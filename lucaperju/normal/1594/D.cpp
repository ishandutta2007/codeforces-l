#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
//*
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
/*/
vector<int>v[200005];
vector<int>c[200005];
int ok=1;
int viz[200005];
int cnt[5];
char sus[50];
void dfs (int pz)
{
    ++cnt[viz[pz]];
    for(int i=0;i<v[pz].size();++i)
    {
        if(viz[v[pz][i]])
        {
            if(viz[v[pz][i]]!=viz[pz] && c[pz][i]==0 || viz[v[pz][i]]==viz[pz] && c[pz][i]==1)
                ok=0;
        }
        else
        {
            viz[v[pz][i]]=viz[pz];
            if(c[pz][i]==1)
                viz[v[pz][i]]=3-viz[v[pz][i]];
            dfs(v[pz][i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); /// damn... this contest sucks
    int n,m,t,i,j,k;
    cin>>t;
    while(t--)
    {
        ok=1;
        int s=0;
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            viz[i]=0;
            v[i].clear();
            c[i].clear();
        }
        for(i=1;i<=m;++i)
        {
            int a,b;
            cin>>a>>b>>sus;
            v[a].push_back(b);
            v[b].push_back(a);
            if(sus[0]=='i')
            {
                c[a].push_back(1);
                c[b].push_back(1);
            }
            else
            {
                c[a].push_back(0);
                c[b].push_back(0);
            }
        }
        for(i=1;i<=n;++i)
        {
            if(!viz[i])
            {
                cnt[1]=cnt[2]=0;
                viz[i]=1;
                dfs(i);
                s=s+max(cnt[1],cnt[2]);
            }
        }
        if(!ok)
            cout<<"-1\n";
        else
            cout<<s<<'\n';
    }
    return 0;
}