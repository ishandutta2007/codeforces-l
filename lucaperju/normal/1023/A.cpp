#include <bits/stdc++.h>
using namespace std;
long long cmmdc(long long a,long long b)
{
    long long r;
    while(b){r=a%b;a=b;b=r;}
    return a;
}
long long lgput (long long cnt, long long mod,long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    else if(cnt<0)
        return 0;
    while(cnt>1){
        if(!(cnt&1)){p=p*1LL*p%mod;cnt>>=1LL;}
        else{--cnt;r=r*1LL*p%mod;}}
    p=p*1LL*r;
    return p%mod;
}
char a[200005],b[200005];
int main()
{
   // ios_base::sync_with_stdio (0);
    long long l=0,r=0,n,t,i,j=1,ca,cb,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,cur,cn,cnt=0,q,cj,ok=1,ci,m;
    char cc;
    cin>>n>>m>>a>>b;
    ok=1;
    if(n>m+1)
        ok=0;
    i=0;
    while(a[i]!='*' && i<=n)
    {
        if(a[i]!=b[i])
            ok=0;
        ++i;
    }
    --n;
    --m;
    while(a[n]!='*' && n>=0)
    {
        if(a[n]!=b[m])
            ok=0;
        --n;
        --m;
    }
    if(ok==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}