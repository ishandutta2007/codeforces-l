#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second
#define py pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
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
const int N = 5e5 + 10;


int main()
{
	int T = read();
	while (T --)
	{
		ll n = read1();
		map<ll, ll, greater<ll>> ma;
		int f = 0;
		rep(i, 1, 2 * n)
		{
			ll a = read1();
			ma[a] ++;
			if (a % 2 == 1) f = 1;
		}
		for (auto i : ma)
			if (i.Y != 2) f = 1;
		if (f) puts("NO");
		else
		{
			ll n = ma.size(), s = 0;
			for (auto i : ma)
			{
				if (i.X / 2 - s <= 0 || (i.X / 2 - s) % n != 0)
				{
					f = 1;
					break;
				}
				s += (i.X / 2 - s) / n;
				n --;
			}
			if (f) puts("NO");
			else puts("YES");
		}
	}

}