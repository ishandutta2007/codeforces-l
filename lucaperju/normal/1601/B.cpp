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
int a[300005],b[300005];
struct ura
{
    int pz,cat;
}v[300005];
bool cmp (ura a, ura b)
{
    return a.cat>b.cat;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,q,t,i,k;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for(i=1;i<=n;++i)
        cin>>b[i];
    for(i=1;i<=n;++i)
    {
        v[i].pz=i;
        v[i+b[i]].cat=max(v[i+b[i]].cat,i);
    }
    v[n].cat=n;
    sort(v+1,v+n+1,cmp);
    int j=1,pz=n;
    int ok=1;
    vector<int>rz;
    while(1)
    {
        int sar=pz-a[pz];
        if(sar<=0)
        {
            rz.push_back(0);
            break;
        }
        int sarmin=j;
        int jv=j;
        while(j<n && v[j+1].cat>=sar)
        {
            ++j;
            if(v[j].pz-a[v[j].pz]<v[sarmin].pz-a[v[sarmin].pz])
                sarmin=j;
        }
        if(sarmin==jv)
        {
            ok=0;
            break;
        }
        rz.push_back(v[sarmin].cat);
        pz=v[sarmin].pz;
    }
    if(ok==0)
        cout<<-1<<'\n';
    else
    {
        cout<<rz.size()<<'\n';
        for(i=0;i<rz.size();++i)
            cout<<rz[i]<<' ';
    }
    return 0;
}