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
int T;
char s[100010], t[100010];
int nxt[26][100010];
int main()
{
	T = read();
	while(T --)
	{
		scanf("%s", s);
		scanf("%s", t);
		int n = strlen(s);
		int m = strlen(t);
		rep0(i, 26)
			rep0(j, n + 1)
				nxt[i][j] = n;
		rep0(i, 26)
			rrep(j, n - 1, 0)
				nxt[i][j] = (s[j] == 'a' + i ? j : nxt[i][j + 1]);
		int cur = 0;
		int ans = 1;
		rep0(i, m)
		{
			int x = t[i] - 'a';
			if(nxt[x][0] == n) {ans = -1; break;}
			if(nxt[x][cur] == n) {ans ++; cur = 0;}
			cur = nxt[x][cur] + 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}