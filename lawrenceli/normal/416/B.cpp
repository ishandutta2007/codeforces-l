#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXM = 50100;
const int MAXN = 10;

int m, n, t[MAXM][MAXN], dp[MAXM][MAXN];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> m >> n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> t[i][j];

    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])+t[i][j];

    for (int i=1; i<=m; i++) cout << dp[i][n] << ' ';
    return 0;
}