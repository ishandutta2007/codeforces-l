#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
//#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi anstor<int>
#define vl anstor<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define All(x) (x).begin(), (x).end()
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
const int N = 1e6 + 10;
int a[N], nxt[N], bo[N];
vector<int> ans;
queue<int> Q;
int que[N];
int ql, qr;

int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		rep(i, 1, n)
		{
			a[i] = read();
			nxt[i] = i + 1;
			bo[i] = 0;
		}
		nxt[n] = 1;
		ans.clear(); 
		rep(i, 1, n)
		{
			if(bo[i]) continue;
			int j = nxt[i];
			if(__gcd(a[i], a[j]) == 1)
			{
				ans.pb(j);
				bo[j] = 1;
				nxt[i] = nxt[j];
				if(__gcd(a[i], a[nxt[i]]) == 1) Q.push(i);
			}
		}
		while(!Q.empty())
		{
			int i = Q.front();
			Q.pop();
			if(bo[i]) continue;
			int j = nxt[i];
			if(__gcd(a[i], a[j]) == 1)
			{
				ans.pb(j);
				bo[j] = 1;
				nxt[i] = nxt[j];
				if(__gcd(a[i], a[nxt[i]]) == 1) Q.push(i);
			}
		}
		
		printf("%d ", sz(ans));
		for(auto i : ans)
			printf("%d ", i);
		puts("");
	}
}