#include <bits/stdc++.h>
#include <ctime>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define mpi map<int,vector<int> > ::iterator
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 2010;

int n, k, col[N], a[N][N], ans;

mt19937 rng;
int dp[N], ndp[N];
void solve()
{
	rep(i, 1, n - 1) col[i] = static_cast<unsigned>(rng()) % 2;
	memset(dp, INF, sizeof(dp));
	dp[0] = 0;
	rep0(i, k)
	{
		memset(ndp, INF, sizeof(ndp));
		rep0(j, n)
			rep0(k, n)
				if(col[j] != col[k])
					ndp[k] = min(ndp[k], dp[j] + a[j][k]);
		memcpy(dp, ndp, sizeof(dp));
	}
	ans = min(ans, dp[0]);
}

int main()
{
	rng = mt19937(chrono::high_resolution_clock().now().time_since_epoch().count());
	n = read();
	k = read();
	rep0(i, n)
		rep0(j, n)
			scanf("%d", a[i] + j);
	
	ans = INF;
	rep0(i, 40506) solve();
	printf("%d\n", ans);
	return 0;
}