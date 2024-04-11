#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
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
int v[100];
int main()
{
    long long a,b,n,t,i,j=1,ca,cb,mx=-99999999999999LL,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,ok=1,cur,cn,cnt=0,q,cj;
    cin>>n>>a>>b;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
    {
        j=n-i+1;
        if(v[i]==2 || v[j]==2)
        {
            if(v[i]==2 && v[j]==2 && i==j)
                s+=min(a,b);
            else
                if(v[i]==2 && i!=j && v[j]==2)
                    s+=2*min(a,b);
            else
                if(v[i]==0 || v[j]==0)
                    s+=a;
                else
                    s+=b;
            v[i]=v[j]=1;
        }
        else
        if(v[i]!=v[j])
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<s;
    return 0;
}