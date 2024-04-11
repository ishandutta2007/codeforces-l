// Lynkcat.
// Problem: C. Representative Edges
// Contest: Codeforces - Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 105 
using namespace std;
int n,a[N];
void BellaKira()
{
	cin>>n;
	int ans=0;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n<=2)
	{
		return cout<<0<<endl,void();
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			int now=0;
			for (int k=1;k<=n;k++)
				if (k!=i&&k!=j)
				{
					if ((a[k]-a[i])*(k-j)==(a[k]-a[j])*(k-i))now++;
				} else now++;
			ans=max(ans,now);
		}
	cout<<n-ans<<endl;
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}