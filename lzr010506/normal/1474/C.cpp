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
const int N = 2e6 + 10;
int a[N];
int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		rep(i, 1, 2 * n)
			a[i] = read();
		sort(a + 1, a + 2 * n + 1);
		rep(i, 1, 2 * n - 1)
		{
			multiset<int> b;
			rep(j, 1, 2 * n - 1) b.insert(a[j]);
			vector<pii> ans;
			ans.pb(mp(a[2 * n], a[i]));
			multiset <int>::iterator pos = b.find(a[i]); 
			b.erase(pos);
			int mx = a[2 * n];
			rep(j, 1, n - 1)
			{
				int x = *b.rbegin();
				pos = b.find(x); 
				b.erase(pos);
				if(b.count(mx - x) == 0) break;
				pos = b.find(mx - x);
				b.erase(pos);
				ans.pb(mp(x, mx - x));
				mx = x;
			}
			if((int)ans.size() == n) 
			{
				puts("YES");
				printf("%d\n", ans[0].X + ans[0].Y);
				rep0(i, n)
					printf("%d %d\n", ans[i].X, ans[i].Y);
				goto L1;
			}
			
		}
		puts("NO");
		L1:;
		

	}
	return 0;
}