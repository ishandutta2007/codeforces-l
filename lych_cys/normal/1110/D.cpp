#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 1000009
using namespace std;

int n,m,a[N],dp[N][3][3];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int main(){
	scanf("%d%d",&m,&n);
	int i,j,k,l;
	for (i=1; i<=m; i++) a[read()]++;
	memset(dp,195,sizeof(dp));
	int ans=0;
	dp[0][0][0]=0;
	for (i=1; i<=n; i++)
		for (j=0; j<3; j++)
			for (k=0; k<3; k++) if (dp[i-1][j][k]>=0)
				for (l=0; l<3; l++){
					int tmp=a[i]-j-k-l;
					if (tmp<0) continue;
					tmp/=3;
					up(dp[i][k][l],dp[i-1][j][k]+tmp+j);
					up(ans,dp[i][k][l]);	
				}
	printf("%d\n",ans);
	return 0;
}