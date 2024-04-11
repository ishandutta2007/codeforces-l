#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
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
const int N = 4e5 + 10;
int n, m, d[N], cnt[N], p[N];
vi G[N];
void bfs(int s)
{
	queue<int> Q;
	memset(d, -1, sizeof(d));
	d[s] = 0;
	Q.push(s);
	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for(auto to : G[x])
			if(d[to] == -1)
			{
				d[to] = d[x] + 1;
				Q.push(to);
			}
		
	}
}
int main()
{
	n = read();
	m = read();
	rep(i, 1, m)
	{
		int u = read();
		int v = read();
		G[v].pb(u);
	}
	int k = read();
	rep(i, 1, k) p[i] = read();
	int s = p[1], t = p[k];
	bfs(t);
	rep(x, 1, n)
		for(auto to : G[x])
			if(d[to] == d[x] + 1)
				cnt[to] ++;
			
	int ans1 = 0, ans2 = 0;
	rep(i, 1, k - 1)
	{
		if(d[p[i]] != d[p[i + 1]] + 1) ans1 ++, ans2 ++;
		else if(cnt[p[i]] > 1) ans2 ++;
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}