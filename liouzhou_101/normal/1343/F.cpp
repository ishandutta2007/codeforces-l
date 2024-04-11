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
			it = ibuf + read(STDIN_FILENO, ibuf, BUFSIZE);
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
			write(STDOUT_FILENO, obuf, BUFSIZE);
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
		char ch = getchar();
		if (ch == EOF) return 0;
		for (; !isdigit(ch); )
		{
			ch = getchar();
			if (ch == EOF) return 0;
		}
		for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		return 1;
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

	template<>
	void write(const char* s)
	{
		for (; *s; ++s) putchar(*s);
	}

	template<>
	void write(char c)
	{
		putchar(c);
	}

	template<class T, class V>
	void write(T x, V y)
	{
		write(x);
		write(y);
	}

	template<class T>
	void writeln(T x)
	{
		write(x);
		putchar('\n');
	}

	struct ender
	{
		~ender()
		{
			if (os != obuf)
#ifdef FWRITE
				fwrite(obuf, 1, os - obuf, stdout);
#else
				write(STDOUT_FILENO, obuf, os - obuf);
#endif
		}
	}__ender;

}

template<class T>
void print(const T& a)
{
	for (auto x : a) printf("%d ", x); puts("");
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
const ll MOD = 998244353;
//const int INF = 1000000010;
const ll INF = 1000000000000000000LL;
const int MAXN = 222;

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

ld det(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

using bits = bitset<MAXN>;

void solve()
{
	int n = inp();
	vector<bits> v(n - 1);
	vector<int> cc(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int k = inp();
		for (int j = 0; j < k; ++j)
		{
			int x = inp();
			v[i][x] = 1;
			cc[x] ++;
		}
	}
	vector<int> can;
	for (int i = 1; i <= n; ++i)
	{
		if (cc[i] == 1)
		{
			can.push_back(i);
		}
	}

	vector<int> ans(n + 1);

	auto go = [&](int end, int begin)
	{
		vector<int> u(n - 1);
		for (int p = n; p >= 2; --p)
		{
			vector<int> c(n + 1);
			for (int i = 0; i < n - 1; ++i)
			{
				if (u[i]) continue;
				for (int x = 1; x <= n; ++x)
					c[x] += v[i][x];
			}
			vector<int> can;
			for (int i = 1; i <= n; ++i)
			{
				if (c[i] == 1 && i != begin) can.push_back(i);
			}
			if (can.size() == 1)
				ans[p] = can[0];
			else if (can.size() >= 2)
			{
				int x = can[0];
				for (auto y : can)
					if (cc[y] > cc[x]) x = y;
				ans[p] = x;
			}
			else
				return false;
			for (int i = 0; i < n - 1; ++i)
			{
				if (u[i]) continue;
				if (v[i][ans[p]]) u[i] = 1;
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; ++i) sum += i;
		for (int i = 2; i <= n; ++i) sum -= ans[i];
		ans[1] = sum;
		return true;
	};

	if (can.size() == 1)
	{
		go(can[0], -1);
	}
	else
	{
		if (!go(can[0], can[1])) go(can[1], can[0]);
	}

	for (int i = 1; i <= n; ++i)
		write(ans[i], i == n ? '\n' : ' ');
}

int main()
{

	for (int T = inp(); T --; )
	solve();

	return 0;
}