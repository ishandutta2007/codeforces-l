#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }
template <int mod>
class mint {
	public:
		int x;
		mint() : x(0) {}
		mint(int _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mint(long long _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mint(unsigned int _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mint(unsigned long long _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		friend mint operator + (mint a, mint b) { return (a.x += b.x) >= mod ? a.x -= mod : 0, a; }
		friend mint operator - (mint a, mint b) { return (a.x -= b.x) < 0 ? a.x += mod : 0, a; }
		friend mint operator * (mint a, mint b) { return a.x = 1ll * a.x * b.x % mod, a; }
		template <typename __Tp> friend mint operator ^ (mint a, __Tp p) {
			mint ans = 1;
			while (p) {
				if (p & 1) ans = ans * a;
				a = a * a, p >>= 1;
			}
			return ans;
		}
		friend mint operator / (mint a, mint b) { return a * (b ^ (mod - 2)); }
		friend mint & operator += (mint &a, mint b) { return a = a + b; }
		friend mint & operator -= (mint &a, mint b) { return a = a - b; }
		friend mint & operator *= (mint &a, mint b) { return a = a * b; }
		friend mint & operator /= (mint &a, mint b) { return a = a / b; }
		friend mint & operator ^= (mint &a, int b) { return a = a ^ b; }

		mint & operator ++ () { return *this += 1; }
		const mint operator ++ (int) { mint t = *this; *this += 1; return t; }
		mint & operator -- () { return *this -= 1; }
		const mint operator -- (int) { mint t = *this; *this -= 1; return t; }

		friend bool operator == (mint a, mint b) { return a.x == b.x; }
		friend bool operator != (mint a, mint b) { return a.x != b.x; }
};

const int maxn = 210, inf = 1e9, mod = 998244353;
typedef mint <mod> mi;
int n, d[maxn][maxn], mnd[maxn], mark[maxn];
pii a[maxn];
vector <int> to[maxn];
mi f[maxn], g[maxn];

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i].fir, a[i].sec);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			d[i][j] = abs(a[i].fir - a[j].fir) + abs(a[i].sec - a[j].sec);

	for (int i = 1; i <= n; ++i) {
		mnd[i] = inf;
		for (int j = 1; j <= n; ++j) if (i != j) mnd[i] = min(mnd[i], d[i][j]);
		for (int j = 1; j <= n; ++j) if (i != j && mnd[i] == d[i][j]) to[i].push_back(j);
	}

	f[0] = 1;
	vector <int> com;
	auto trans = [&] (int x) {
		com.push_back(x);
		for (int i = 0; i <= n; ++i) {
			g[i + 1] += f[i];
			if (x > 1) g[i + x] += f[i];
			f[i] = g[i], g[i] = 0;
		}
	};
	for (int i = 1; i <= n; ++i) {
		if (mark[i]) continue;
		queue <int> q;
		vector <int> vec;
		bitset <maxn> vis;
		q.push(i), vec.push_back(i), vis[i] = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : to[u])
				if (!vis[v]) q.push(v), vec.push_back(v), vis[v] = 1;
		}
		for (int u : vec)
			for (int v : vec)
				if (u != v && d[u][v] != mnd[i]) mark[i] = 1;
		if (mark[i]) trans(1);
		else {
			trans(vec.size());
			for (int u : vec) mark[u] = 1;
		}
	}

	sort(com.begin(), com.end());
	mi t = 1, ans = 0;
	for (int i = 1; i <= n; ++i)
		t *= (n - i + 1), ans += t * f[i];
	write(ans.x, '\n');
	return 0;
}