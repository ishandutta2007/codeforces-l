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
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define rrep(i, x, y) for (int i = x; i >= y; i--)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define per0(i, n) for (int i = (n)-1; i >= 0; i--)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
#define vi vector<int>
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
int a[1000010];
int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		int m = read();
		int Mn = 1e9;
        bool flag = n == 1;
        bool ok = 0;
        int now = 0;
        rep(i, 1, n)
        {
        	int x = read();
        	if(x >= m) now ++, a[i] = 1;
        	else a[i] = 0;
        	if(x == m) ok = 1;
            a[i] += a[i - 1];
            if (i - 2 >= 0) Mn = min(Mn, a[i - 2] * 2 - (i - 2));
            if (now * 2 - i > Mn) flag = 1;
        }
        if(flag && ok) puts("yes");
        else puts("no");
    }

	return 0;
}