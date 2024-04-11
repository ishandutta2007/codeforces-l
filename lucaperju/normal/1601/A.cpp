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
int cmmdc (int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int fv[50];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,q,t,i,j,k,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=40;++i)
            fv[i]=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            int j=0;
            while(a)
            {
                ++j;
                fv[j]+=a%2;
                a>>=1;
            }
        }
        int s=0;
        for(i=1;i<=40;++i)
        {
            s=cmmdc(s,fv[i]);
        }
        for(i=1;i<=n;++i)
            if(s%i==0)
                cout<<i<<' ';
        cout<<'\n';
    }
}