#include <bits/stdc++.h>

using namespace std;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,n,i,m,j,k,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int cnt0=0,cnt1=0;
        for(i=1;i<=n;++i)
        {
            if(v[i]%2==0)
                ++cnt0;
            else
                ++cnt1;
        }
        if(cnt1%2==0)
        {
            cout<<"YES\n";
            continue;
        }
        sort(v+1,v+n+1);
        for(i=1;i<n;++i)
        {
            if(v[i]==v[i+1]-1)
            {
                cout<<"YES\n";
                break;
            }
        }
        if(i==n)
            cout<<"NO\n";
    }
    return 0;
}