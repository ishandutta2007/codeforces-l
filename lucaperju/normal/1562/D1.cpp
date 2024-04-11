#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
long long fct[400005],invfct[400005],inv[400005];
long long put2[400005];
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
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=400000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int v[300005];
int sp[300005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,k,m,n,q;
    cin>>t;
  /*  ciur[0]=ciur[1]=1;
    for(i=2;i*i<=1000;++i)
    {
        if(!ciur[i])
        for(j=i*i;j<=1000;j+=i)
                ciur[j]=1;
    }*/
    while(t--)
    {
        cin>>n>>q;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            if(c=='+')
                v[i]=1;
            else
                v[i]=-1;
            if(i%2==0)
            {
                v[i]=-v[i];
            }
            sp[i]=sp[i-1]+v[i];
        }
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            if(sp[r]-sp[l-1]==0)
                cout<<0<<'\n';
            else
            {
                if((r-l)%2==1)
                    cout<<2<<'\n';
                else
                    cout<<1<<'\n';
            }
        }
    }
    return 0;
}