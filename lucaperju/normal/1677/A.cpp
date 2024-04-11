#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;

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
*/
int v[5005];
int sp[5005];
int pzs[5005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,k,s,d,m,j=0,tt,p,n,K;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sp[n+1]=0;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<=n;++i)
            pzs[v[i]]=i;
        long long s=0;
        for(int b=2;b+2<=n;++b)
        {
            for(i=1;i<=n;++i)
                sp[i]=0;
            for(i=b+1;i<=n;++i)
                if(v[i]<v[b])
                    ++sp[i];
            for(i=n-1;i>=1;--i)
                sp[i]+=sp[i+1];
            int cnt=0;
            for(i=1;i<=n;++i)
            {
                if(pzs[i]==b)
                    continue;
                else if(pzs[i]<b)
                    ++cnt;
                else
                {
                    s+=cnt*1LL*sp[pzs[i]+1];
                }
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}