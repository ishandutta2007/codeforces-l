#include <bits/stdc++.h>

using namespace std;


/*
const long long mod = 998244353;

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
int v[1003][1003];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,i,h,k,j,n,s=0,t;
    cin>>t;
    while(t--)
    {
        int ok=0;
        cin>>n;
        for(i=0;i<=n+1;++i)
            for(j=0;j<=n+1;++j)
                v[i][j]=0;
        for(i=2;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                int cnt=0;
                for(k=0;k<=3;++k)
                {
                    int a=i-1+dx[k];
                    int b=j+dy[k];
                    if(v[a][b])
                        ++cnt;
                }
                if(cnt%2==0)
                    v[i][j]=1;
                else
                    v[i][j]=0;
            }
        }
        long long ans=0;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                int a;
                cin>>a;
                if(v[i][j])
                    ans=(ans^a);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}