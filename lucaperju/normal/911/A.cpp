#include <iostream>
#include <cstring>
using namespace std;
long long cmmdc(long long a,long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long lgput (long long cnt, long long mod,long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    else
    if(cnt<0)
        return 0;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1LL;
        }
        else
        {
            --cnt;
            r=r*1LL*p%mod;
        }
    }
    p=p*1LL*r;
    return p%mod;
}
int v[100005];
int main()
{
    long long a,b,nrca,nrcb,n,i,j,c,ca,cb,mx=9999999999,mn=9999999999,s=0,k,x,y,z,nra,nrb,ok,poz,cur=0,m;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(v[i]<mn)
            mn=v[i];
    }
    poz=-1;
    for(i=1;i<=n;++i)
    {
        if(v[i]==mn)
        {
            if(poz==-1)
                poz=i;
            else
                if(i-poz<mx)
                    mx=i-poz;
            poz=i;
        }
    }
    cout<<mx;
    return 0;
}