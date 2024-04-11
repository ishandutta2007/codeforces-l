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
int v[1003][6];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); /// damn... this contest sucks
    int n,m,t,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            for(j=1;j<=5;++j)
                cin>>v[i][j];
        int ok=0;
        for(int a=1;a<=5;++a)
            for(int b=a+1;b<=5;++b)
            {
                int cnta=0,cntb=0,cntab=0,cntnab=0;
                for(i=1;i<=n;++i)
                {
                    if(v[i][a]==0 && v[i][b]==0)
                        ++cntnab;
                    if(v[i][a]==1 && v[i][b]==0)
                        ++cnta;
                    if(v[i][a]==0 && v[i][b]==1)
                        ++cntb;
                    if(v[i][a]==1 && v[i][b]==1)
                        ++cntab;
                }
                if(cntnab!=0)
                    continue;
                if(min(cnta,cntb)+cntab<n/2)
                    continue;
                ok=1;
            }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}