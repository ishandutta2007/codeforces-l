#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
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
 
const int N = 2e5 + 10;
int a[N], f[N];
int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		rep0(i, n) a[i] = read();
		int ts = (1 << n);
		rep0(i, ts) f[i] = 0;
		rep(i, 1, ts - 1)
			rep0(j, n)
				if ((1 << j) & i) f[i] += a[j];

		bool ok = 0;
		rep(i, 1, ts - 1)
			rep(j, 1, ts - 1)
				if (!(i & j) && abs(f[i]) == abs(f[j])) ok = 1;

		rep0(i, n) if (!a[i]) ok = 1;

		if (ok) puts("YES");
		else puts("NO");
	}
}