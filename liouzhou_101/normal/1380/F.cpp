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

#define X first
#define Y second

//#ifndef ONLINE_JUDGE
#define FWRITE
//#endif

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

//mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rd(1);

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

//const ll B = 31;
//const ll MOD = 1000000007;
const int INF = 1000000010;
const ll INFll = 4000000000000000000LL;
const int MAXN = 600010;
const int MAXK = 20;

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

ld det(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

template<class data_type>
struct segment_tree
{
	using T = data_type;
	int n;
	vector<T> a;

	using initialize_type = function<void(T&, int)>;
	using merge_type = function<void(T&, const T&, const T&)>;
	using pushdown_type = function<void(T&, int, int, T&, T&)>;
	initialize_type initialize;
	merge_type merge;
	pushdown_type pushdown;

	void clear(int k, int L, int R)
	{
		pushdown(a[k], L, R, a[k << 1], a[k << 1 | 1]);
	}
	void update(int k)
	{
		merge(a[k], a[k << 1], a[k << 1 | 1]);
	}
	void build(int k, int L, int R)
	{
		if (L == R)
		{
			initialize(a[k], L);
			return;
		}
		int m = (L + R) >> 1;
		build(k << 1, L, m);
		build(k << 1 | 1, m + 1, R);
		update(k);
	}
	segment_tree(int n, const initialize_type& initialize, const merge_type& merge, const pushdown_type& pushdown)
	{
		assert(n >= 1);
		this->n = n;
		this->initialize = initialize;
		this->merge = merge;
		this->pushdown = pushdown;
		a = vector<T>(4 * n + 1);
		build(1, 1, n);
	}

	using modifier_type = function<void(T&, int, int)>;
	void modify(int k, int L, int R, int x, int y, const modifier_type& modifier)
	{
		if (L == x && R == y)
		{
			modifier(a[k], L, R);
			return;
		}
		int m = (L + R) >> 1;
		clear(k, L, R);
		if (y <= m)
			modify(k << 1, L, m, x, y, modifier);
		else if (x > m)
			modify(k << 1 | 1, m + 1, R, x, y, modifier);
		else
		{
			modify(k << 1, L, m, x, m, modifier);
			modify(k << 1 | 1, m + 1, R, m + 1, y, modifier);
		}
		update(k);
	}
	void modify(int x, int y, const modifier_type& modifier)
	{
		assert(1 <= x && x <= y && y <= n);
		modify(1, 1, n, x, y, modifier);
	}

	template<class result_type, class convert_type = function<result_type(const T&)>, class calculate_type = function<result_type(const result_type&, const result_type&)>>
	result_type query(int k, int L, int R, int x, int y, const convert_type& convert, const calculate_type& calculate)
	{
		if (L == x && R == y)
			return convert(a[k]);
		int m = (L + R) >> 1;
		clear(k, L, R);
		if (y <= m)
			return query<result_type>(k << 1, L, m, x, y, convert, calculate);
		if (x > m)
			return query<result_type>(k << 1 | 1, m + 1, R, x, y, convert, calculate);
		return calculate(query<result_type>(k << 1, L, m, x, m, convert, calculate), query<result_type>(k << 1 | 1, m + 1, R, m + 1, y, convert, calculate));
	}
	template<class result_type, class convert_type = function<result_type(const T&)>, class calculate_type = function<result_type(const result_type&, const result_type&)>>
	result_type query(int x, int y, const convert_type& convert, const calculate_type& calculate)
	{
		assert(1 <= x && x <= y && y <= n);
		return query<result_type>(1, 1, n, x, y, convert, calculate);
	}

	T query(int x, int y)
	{
		assert(1 <= x && x <= y && y <= n);
		function<T(const T&)> convert = [](const T& it) -> T
		{
			return it;
		};
		function<T(const T&, const T&)> calculate = [&](const T& Lc, const T& Rc) -> T
		{
			T ret;
			merge(ret, Lc, Rc);
			return ret;
		};
		return query<T>(x, y, convert, calculate);
	}
};

char s[MAXN];
int trans[10][2][2] = {
	{{1, 9},{0, 0}},
	{{2, 8},{1, 0}},
	{{3, 7},{0, 0}},
	{{4, 6},{0, 0}},
	{{5, 5},{0, 0}},
	{{6, 4},{0, 0}},
	{{7, 3},{0, 0}},
	{{8, 2},{0, 0}},
	{{9, 1},{0, 0}},
	{{10, 0},{0, 0}},
};

void solve()
{
	int n, m;
	read(n, m, s);
	const int MOD = 998244353;
	struct node
	{
		int val[2][2];
	};
	auto initialize = [](node& it, int id) -> void
	{
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				it.val[i][j] = trans[s[id - 1] - '0'][i][j];
	};
	auto merge = [&](node& it, const node& Lc, const node& Rc) -> void
	{
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
			{
				it.val[i][j] = 0;
				for (int k = 0; k < 2; ++k)
					it.val[i][j] = (it.val[i][j] + (ll)Rc.val[i][k] * Lc.val[k][j]) % MOD;
			}
	};
	auto pushdown = [&](node& it, int L, int R, node& Lc, node& Rc) -> void
	{
	};
	segment_tree<node> H(n, initialize, merge, pushdown);

	while (m--)
	{
		int x, d;
		read(x, d);
		H.modify(x, x, [&](node& it, int, int)
			{
				for (int i = 0; i < 2; ++i)
					for (int j = 0; j < 2; ++j)
						it.val[i][j] = trans[d][i][j];
			});
		auto res = H.query(1, n);
		writeln(res.val[0][0]);
	}
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