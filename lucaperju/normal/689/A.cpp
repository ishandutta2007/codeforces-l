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
char v[10];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,y,k,m,j=0,n,tt,p;
   // cin>>t;
    t=1;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int h1=0,h3=0,h2=0,h4=0,h5=0,h6=0;
        for(i=1;i<=n;++i)
        {
            if(v[i]=='1' || v[i]=='4' || v[i]=='7')
                h1=1;
            if(v[i]=='1' || v[i]=='2' || v[i]=='3')
                h2=1;
            if(v[i]=='0')
                h4=1;
            if(v[i]=='3' || v[i]=='6' || v[i]=='9')
                h3=1;

            if(v[i]=='4' || v[i]=='6')
                h5=1;
            if(v[i]=='7' || v[i]=='9')
                h6=1;
        }
        if(h2 && h4)
        {
            cout<<"YES\n";
            continue;
        }
        if((h2 && h6) && h1 && h3 && h6)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}