#include <bits/stdc++.h>

using namespace std;

//using ll = int64_t;
using ll = long long;
using ull = uint64_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = double;

#define X first
#define Y second

#ifndef ONLINE_JUDGE
#define FWRITE
#endif

namespace io
{

#ifndef FWRITE
#include <unistd.h>
	auto unistd_read = read;
	auto unistd_write = write;
#endif
	const int BUFSIZE = 1 << 20;

	int isize, osize;
	char ibuf[BUFSIZE + 10], obuf[BUFSIZE + 10];
	char* is, * it, * os = obuf, * ot = obuf + BUFSIZE;

	char getchar()
	{
		if (is == it)
		{
			is = ibuf;
#ifdef FWRITE
			it = ibuf + fread(ibuf, 1, BUFSIZE, stdin);
#else
			it = ibuf + unistd_read(STDIN_FILENO, ibuf, BUFSIZE);
#endif
			if (is == it) return EOF;
		}
		return *is++;
	}

	char getalpha()
	{
		char c = getchar();
		while (!isalpha(c)) c = getchar();
		return c;
	}

	void putchar(char c)
	{
		*os++ = c;
		if (os == ot)
		{
#ifdef FWRITE
			fwrite(obuf, 1, BUFSIZE, stdout);
#else
			unistd_write(STDOUT_FILENO, obuf, BUFSIZE);
#endif
			os = obuf;
		}
	}

	int inp() {
		int x = 0, f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
		{
			if (ch == EOF) return -1;
			if (ch == '-') f = 1;
		}
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		return f ? -x : x;
	}

	ll inp_ll() {
		ll x = 0; int f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
			if (ch == '-') f = 1;
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		return f ? -x : x;
	}

	template<class T>
	bool read(T& x)
	{
		x = 0;
		int f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
		{
			if (ch == EOF) return 0;
			if (ch == '-') f = 1;
		}
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		if (f) x = -x;
		return 1;
	}

	bool read(char* s)
	{
		char* t = s;
		char ch = getchar();
		for (; ch == ' ' || ch == '\n'; ch = getchar());
		for (; ch != ' ' && ch != '\n' && ch != EOF; ch = getchar())
			*t++ = ch;
		*t = 0;
		return s != t;
	}

	template<class T, class... Args>
	bool read(T& x, Args&... args)
	{
		return read(x) && read(args...);
	}

	template<class T>
	bool readln(T& x)
	{
		x = 0;
		int f = 0; char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar())
		{
			if (ch == EOF) return 0;
			if (ch == '-') f = 1;
		}
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		if (f) x = -x;
		for (; ch != '\n' && ch != EOF; ch = getchar());
		return 1;
	}

	bool readln(char* s)
	{
		char* t = s;
		while (1)
		{
			char ch = getchar();
			if (ch == '\n' || ch == EOF) break;
			*t++ = ch;
		}
		*t = 0;
		return s != t;
	}

	template<class T, class... Args>
	bool readln(T& x, Args&... args)
	{
		return read(x) && readln(args...);
	}

	template<class T>
	void write(T x)
	{
		static char s[22];
		static char* it = s + 20;
		static char* end = s + 20;

		if (x < 0)
		{
			putchar('-');
			x = -x;
		}

		do
		{
			*--it = x % 10 + '0';
			x /= 10;
		} while (x);
		/*
		if (!x)
			*-- it = '0';
		while (x)
		{
			*-- it = x%10+'0';
			x /= 10;
		}
		*/
		for (; it < end; ++it)
			putchar(*it);
	}

	void write(const char* s)
	{
		for (; *s; ++s) putchar(*s);
	}

	template<>
	void write(char* s)
	{
		write((const char*)s);
	}

	template<>
	void write(char c)
	{
		putchar(c);
	}

	template<class T, class... Args>
	void write(T x, Args... args)
	{
		write(x);
		write(args...);
	}

	void writeln()
	{
		putchar('\n');
	}

	template<class T, class... Args>
	void writeln(T x, Args... args)
	{
		write(x);
		writeln(args...);
	}

	template<class Iterator>
	bool input(Iterator st, Iterator ed)
	{
		for (; st != ed; ++st)
		{
			if (!read(*st)) return false;
		}
		return true;
	}

	template<class T>
	bool input(T& a)
	{
		input(a.begin(), a.end());
	}

	template<class Iterator>
	void print(Iterator st, Iterator ed, const char* c = " ")
	{
		int flag = 0;
		for (; st != ed; ++st)
		{
			if (flag) write(c);
			flag = 1;
			write(*st);
		}
		writeln();
	}

	template<class T>
	void print(const T& a, const char* c = " ")
	{
		print(a.begin(), a.end(), c);
	}

	struct ender
	{
		~ender()
		{
			if (os != obuf)
#ifdef FWRITE
				fwrite(obuf, 1, os - obuf, stdout);
#else
				unistd_write(STDOUT_FILENO, obuf, os - obuf);
#endif
		}
	}__ender;

}

int64_t power(int64_t a, int64_t b, int64_t p)
{
	if (!b) return 1;
	int64_t t = power(a, b >> 1, p);
	t = t * t % p;
	if (b & 1) t = t * a % p;
	return t;
}

//mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

using namespace io;

template<class T>
inline void freshmin(T& a, const T& b)
{
	if (a > b) a = b;
}

template<class T>
inline void freshmax(T& a, const T& b)
{
	if (a < b) a = b;
}

const ll B = 31;
//const ll MOD = 1000000007;
const int INF = 1000000010;
const ll INFll = 4000000000000000000LL;
const int MAXN = 500010;

//int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
//int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

ld det(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

struct undirected_graph
{
	int n;
	vector<pii> edge;
	undirected_graph(int n)
	{
		init(n);
	}
	void init(int n)
	{
		assert(n >= 0);
		this->n = n;
	}
	void addedge(int x, int y)
	{
		assert(1 <= x && x <= n);
		assert(1 <= y && y <= n);
		edge.push_back({ x, y });
	}
};

struct tree
{
	const static int K = 1; // for LCA
	int n;
	vector<vector<int>> v;
	tree(const undirected_graph& G)
	{
		n = G.n;
		v = vector<vector<int>>(n + 1);
		for (auto e : G.edge)
		{
			int x = e.X, y = e.Y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}

	vector<int> r;
	int times;
	vector<int> X, Y;
	vector<int> dis;
	vector<array<int, K>> pre;
	void dfs(int x, int p)
	{
		X[x] = ++times;
		for (auto y : v[x])
		{
			if (y == p) continue;
			dis[y] = dis[x] + 1;
			pre[y][0] = x;
			dfs(y, x);
		}
		Y[x] = times;
	}
	void build_dfs_order(int root)
	{
		assert(1 <= root && root <= n);
		r = vector<int>(n + 1);
		X = vector<int>(n + 1);
		Y = vector<int>(n + 1);
		dis = vector<int>(n + 1);
		pre = vector<array<int, K>>(n + 1);
		times = 0;
		dfs(root, 0);
		for (int k = 1; k < K; ++k)
			for (int i = 1; i <= n; ++i)
				pre[i][k] = pre[pre[i][k - 1]][k - 1];
	}

	int getLCA(int x, int y)
	{
		assert(n <= 1 << K);
		if (dis[x] < dis[y]) swap(x, y);
		for (int k = K - 1; k >= 0; --k)
			if (dis[x] - dis[y] >= 1 << k)
				x = pre[x][k];
		if (x == y) return x;
		for (int k = K - 1; k >= 0; --k)
			if (pre[x][k] != pre[y][k])
			{
				x = pre[x][k];
				y = pre[y][k];
			}
		return pre[x][0];
	}
};

void solve()
{
	int n = inp();
	vector<int> a(n + 1), b(n + 1), c(n + 1);
	vector<int> u(2);
	for (int i = 1; i <= n; ++i)
	{
		read(a[i], b[i], c[i]);
		u[b[i]] ++;
		u[c[i]] --;
	}
	if (u[0] != 0 || u[1] != 0) return writeln(-1);
	undirected_graph G(n);
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		read(x, y);
		G.addedge(x, y);
	}
	tree T(G);
	T.build_dfs_order(1);

	vector<vector<int>> w(2, vector<int>(n + 1));
	auto add = [&](vector<int> &a, int x, int p)
	{
		for (; x <= n; x += x & -x) a[x] += p;
	};
	auto get = [&](vector<int>& a, int x)
	{
		int ret = 0;
		for (; x; x ^= x & -x) ret += a[x];
		return ret;
	};
	auto calc = [&](vector<int>& a, int x, int y)
	{
		return get(a, y) - get(a, x - 1);
	};
	for (int i = 1; i <= n; ++i)
	{
		if (b[i] == c[i]) continue;
		add(w[b[i]], T.X[i], 1);
	}

	set<pii> H;
	for (int i = 1; i <= n; ++i) H.insert({ a[i], i });
	u = vector<int>(n + 1);
	ll res = 0;
	while (!H.empty())
	{
		auto [cost, x] = *H.begin();
		{
			queue<int> q;
			q.push(x);
			u[x] = 1;
			while (!q.empty())
			{
				int x = q.front();
				q.pop();
				H.erase({ a[x], x });
				for (auto y : T.v[x])
					if (y != T.pre[x][0] && !u[y])
					{
						u[y] = 1;
						q.push(y);
					}
			}
		}
		int w0 = calc(w[0], T.X[x], T.Y[x]);
		int w1 = calc(w[1], T.X[x], T.Y[x]);
		int go = min(w0, w1);
		res += (ll)go * 2 * a[x];
		add(w[0], T.X[x], -go);
		add(w[1], T.X[x], -go);
	}
	writeln(res);
}

int main()
{

	int T = 1;
	//read(T);
	for (int test = 1; test <= T; ++test)
	{
		//write("Case #", test, ": ");
		solve();
	}

	return 0;
}