#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
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
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(long long i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}*/
int t1[100003],t2[100003];
int tata1(int a)
{
    if(t1[a]==0 || t1[a]==a)
        return a;
    return t1[a]=tata1(t1[a]);
}
int tata2(int a)
{
    if(t2[a]==0 || t2[a]==a)
        return a;
    return t2[a]=tata2(t2[a]);
}
set<int>s1;
set<int>s2;
bool tryAdd (int a, int b)
{
    if(tata1(a)==tata1(b) || tata2(a)==tata2(b))
        return false;
    s1.erase(tata1(a));
    s2.erase(tata2(a));
    t1[tata1(a)]=tata1(b);
    t2[tata2(a)]=tata2(b);
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,a,b,j,k,m,n;
    cin>>n>>a>>b;
    for(i=1;i<=a;++i)
    {
        int x,y;
        cin>>x>>y;
        t1[tata1(x)]=tata1(y);
    }
    for(i=1;i<=b;++i)
    {
        int x,y;
        cin>>x>>y;
        t2[tata2(x)]=tata2(y);
    }
    for(i=1;i<=n;++i)
    {
        if(i==tata1(i))
            s1.insert(i);
    }
    for(i=1;i<=n;++i)
    {
        if(i==tata2(i))
            s2.insert(i);
    }
    vector<pair<int,int> >rz;
    while(1)
    {
        if(s1.size()==1 || s2.size()==1)
            break;
        int a,b,c;
        a=1;
        auto it=s1.begin();
        if(*it==tata1(a))
            ++it;
        b=*it;
        it=s2.begin();
        if(*it==tata2(a))
            ++it;
        c=*it;
        if(tryAdd(a,b))
            rz.push_back(make_pair(a,b));
        if(tryAdd(a,c))
            rz.push_back(make_pair(a,c));
        if(tryAdd(c,b))
            rz.push_back(make_pair(c,b));
    }
    cout<<rz.size()<<'\n';
    for(i=0;i<rz.size();++i)
        cout<<rz[i].first<<' '<<rz[i].second<<'\n';
    return 0;
}