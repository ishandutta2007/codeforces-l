#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
//using ll = long long;
using ull = uint64_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;

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
		return input(a.begin(), a.end());
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

pll exgcd(ll a, ll b)
{
	if (b == 0) return { 1, 0 };
	//auto [x, y] = exgcd(b, a % b);
	auto e = exgcd(b, a % b);
	ll x = e.first;
	ll y = e.second;
	return { y, x - a / b * y };
}

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rd(678);

using namespace io;

template<class T>
inline bool freshmin(T& a, const T& b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	else
		return false;
}

template<class T>
inline bool freshmax(T& a, const T& b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	else
		return false;
}

template<class T>
auto arr(int n = 0)
{
	return vector<T>(n);
}

template<class T, class... Args>
auto arr(int n, Args... args)
{
	return vector<decltype(arr<T>(args...))>(n, arr<T>(args...));
}

//int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
//int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

template<class T>
T det(T x1, T y1, T x2, T y2, T x3, T y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}
/*
template<class T>
T dis(T x1, T y1, T x2, T y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
*/

#ifdef ONLINE_JUDGE
const int OJ = 1;
#else
const int OJ = 0;
#endif

const int MAXN = 600010;

void init()
{
}

const int INF = 1000000000;

template<class weight_type>
struct weighted_directed_graph
{
	int n;
	vector<vector<pair<int, weight_type>>> v;

	weighted_directed_graph(int n = 0)
	{
		init(n);
	}
	void init(int n)
	{
		assert(n >= 0);
		this->n = n;
		v = vector<vector<pair<int, weight_type>>>(n + 1);
	}
	void addedge(int x, int y, weight_type z)
	{
		assert(1 <= x && x <= n);
		assert(1 <= y && y <= n);
		v[x].push_back({ y, z });
	}

	vector<weight_type> dis;
	weight_type shortest_path(int s, int t)
	{
		dis = vector<weight_type>(n + 1, INF);
		dis[s] = 0;
		priority_queue<pair<weight_type, int>, vector<pair<weight_type, int>>, greater<pair<weight_type, int>>> Q;
		Q.push({ 0, s });
		while (!Q.empty())
		{
			weight_type d;
			int x;
			tie(d, x) = Q.top();
			Q.pop();
			if (dis[x] != d) continue;
			for (auto e : v[x])
			{
				int y;
				weight_type z;
				tie(y, z) = e;
				if (dis[y] > d + z) Q.push({ dis[y] = d + z, y });
			}
		}
		return dis[t];
	}
};


void solve()
{
	int n, m, k;
	read(n, m, k);
	weighted_directed_graph<int> G(n);
	vector<pii> edge;
	for (int i = 1; i <= m; ++i)
	{
		int x, y, z;
		read(x, y, z);
		G.addedge(x, y, z);
		G.addedge(y, x, z);
		edge.push_back({ x, y });
	}
	auto d = arr<int>(n + 1, n + 1);
	for (int i = 1; i <= n; ++i)
	{
		G.shortest_path(i, i);
		for (int j = 1; j <= n; ++j)
			d[i][j] = G.dis[j];
	}
	vector<pii> path;
	for (int i = 1; i <= k; ++i)
	{
		int x, y;
		read(x, y);
		path.push_back({ x, y });
	}
	int res = INF;
	for (auto [u, v] : edge)
	{
		int tmp = 0;
		for (auto [x, y] : path)
		{
			tmp += min({ d[x][u] + d[v][y], d[x][v] + d[u][y], d[x][y] });
		}
		freshmin(res, tmp);
	}
	writeln(res);
}

int main()
{
	if (!OJ)
	{
		freopen("try.in", "r", stdin);
		freopen("try.out", "w", stdout);
	}

	int T = 1;
	//read(T);
	//init();
	for (int test = 1; test <= T; ++test)
	{
		//write("Case #", test, ": ");
		solve();
	}

	return 0;
}