#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
char v[1003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,n,h,k,s=0,t;
    long long i,j;
    cin>>t;
    while(t--)
    {
        long long a,b=0,s;
        cin>>a>>s;
        int ok=1;
        long long pc=1;
        while(a)
        {
            int cc=a%10;
            int nc=(s%10-cc+10)%10;
            b=b+nc*1LL*pc;
            pc=pc*10LL;
            s/=10;
            if(cc+nc>=10 && s%10!=1)
            {
                ok=0;
                break;
            }
            else if(cc+nc>=10)
            {
                s/=10;
            }
            a/=10;
        }
        if(ok)
            cout<<b+s*1LL*pc<<'\n';
        else
            cout<<"-1\n";
    }
}