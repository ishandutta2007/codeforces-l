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
using ld = double;

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

pll exgcd(ll a, ll b)
{
	if (b == 0) return { 1, 0 };
	//auto [x, y] = exgcd(b, a % b);
	auto e = exgcd(b, a % b);
	ll x = e.first;
	ll y = e.second;
	return { y, x - a / b * y };
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

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

template<class T>
T det(T x1, T y1, T x2, T y2, T x3, T y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

template<class T>
T dis(T x1, T y1, T x2, T y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

namespace Lyndon_factorization
{
	// return Lyndon factorization.
	// The Lyndon factorization of a string s is of the form
	//     s = w_1 w_2 ... w_k,
	// where w_i is simple and w_1 >= w_2 >= ... >= w_k.
	// The Lyndon factorization of any string is proved to be unique.
	// A string is called simple if it is strictly smaller than any of its own nontrivial suffixes, e.g. a, b, ab, aab, ababb.
	// A string is simple <==> it is the smallest cyclic shift of itself.
	// Format: [x_i, y_i] denotes w_i = s[x_i..x_i+y_i-1]
	// url: https://cp-algorithms.com/string/lyndon_factorization.html
	vector<pii> duval(const string& s)
	{
		int n = s.size();
		vector<pii> res;
		int i = 0;
		while (i < n)
		{
			int j = i + 1, k = i;
			while (j < n && s[k] <= s[j])
			{
				if (s[k] < s[j])
					k = i;
				else
					k++;
				j++;
			}
			while (i <= k)
			{
				res.push_back({ i, j - k });
				i += j - k;
			}
		}
		return res;
	}

	// return the factorization of pre-simple strings
	vector<pii> pre_duval(const string& s)
	{
		int n = s.size();
		vector<pii> res;
		int i = 0;
		while (i < n)
		{
			int j = i + 1, k = i;
			while (j < n && s[k] <= s[j])
			{
				if (s[k] < s[j])
					k = i;
				else
					k++;
				j++;
			}
			int pos = i;
			while (i <= k)
				i += j - k;
			res.push_back({ pos, i - pos });
		}
		return res;
	}

	template<class T>
	int minimal_representation(vector<T> s)
	{
		int n = s.size();
		for (int i = 0; i < n; ++i) s.push_back(s[i]);
		n *= 2;
		int i = 0;
		int pos = -1;
		while (i < n / 2)
		{
			pos = i;
			int j = i + 1, k = i;
			while (j < n && s[k] <= s[j])
			{
				if (s[k] < s[j])
					k = i;
				else
					k++;
				j++;
			}
			while (i <= k)
				i += j - k;
		}
		return pos;
	}
}

namespace string_algorithm
{
	// return an array z[0..n-1] with n the length of s, where
	//   1. z[0] = 0, and
	//   2. for 1 <= i < n, z[i] denotes the maximal integer such that s[0..z[i]-1] == s[i..i+z[i]-1].
	vector<int> z_algorithm(const string& s)
	{
		int n = s.size();
		vector<int> z(n);
		int x = 0, y = 0;
		for (int i = 1; i < n; ++i)
		{
			if (i <= y) z[i] = min(z[i - x], y - i);
			while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
			if (i + z[i] > y) x = i, y = i + z[i];
		}
		return z;
	}
};

void init()
{

}

const int MAXN = 5000010;

char buf[MAXN];

string solve(string s, int k)
{
	int n = s.size();
	if (n == 1) return s;
	
	if (k == 1)
	{
		string s_rev = s;
		reverse(s_rev.begin(), s_rev.end());
		string res = min(s, s_rev);
		return res;
	}

	if (k == 2)
	{
		string res = s;
		
		// Case 1: reverse suffix
		{
			string tmp = s;
			reverse(tmp.begin(), tmp.end());
			tmp += "#";
			tmp += s;
			auto z = string_algorithm::z_algorithm(tmp);
			int best = 0;
			for (int i = 1; i < n; ++i)
			{
				// note that best < i always holds
				if (z[best + n + 1] < i - best)
				{
					if (s[best + z[best + n + 1]] < tmp[z[best + n + 1]])
					{
						best = i;
					}
				}
				else
				{
					if (z[i - best] < n - i)
					{
						if (tmp[i - best + z[i - best]] > tmp[z[i - best]])
						{
							best = i;
						}
					}
				}
			}
			{
				string tmp = s;
				reverse(tmp.begin() + best, tmp.end());
				freshmin(res, tmp);
			}
		}

		// Case 2: reverse prefix
		{
			reverse(s.begin(), s.end());
			auto fact = Lyndon_factorization::pre_duval(s);
			reverse(fact.begin(), fact.end());
			int pos1 = fact[0].second;

			char c = 'z' + 1;
			string tmp;
			tmp += c;
			auto t = s + tmp;
			int pos2 = Lyndon_factorization::pre_duval(t).back().second - 1;

			string s_rev = s;
			reverse(s.begin(), s.end());
			freshmin(res, s_rev.substr(n - pos1, pos1) + solve(s.substr(pos1), 1));
			freshmin(res, s_rev.substr(n - pos2, pos2) + solve(s.substr(pos2), 1));
		}

		return res;
	}

	reverse(s.begin(), s.end());
	auto fact = Lyndon_factorization::pre_duval(s);
	int m = fact.size();
	reverse(fact.begin(), fact.end());

	string res;
	int i = 0;

	if (k > 2 && s[fact[0].first] == s[fact[0].first + fact[0].second - 1])
	{
		k--;
		while (i < m && s[fact[i].first] == s[fact[i].first + fact[i].second - 1])
		{
			res += s.substr(fact[i].first, fact[i].second);
			i++;
		}
	}

	while (i < m && k > 2)
	{
		auto [x, y] = fact[i];
		res += s.substr(x, y);
		i++;
		k--;
	}

	if (i == m) return res;
	assert(k == 2);

	auto [x, y] = fact[i];
	reverse(s.begin(), s.end());
	res += solve(s.substr((int)res.size()), 2);
	return res;
}

void solve()
{
	read(buf);
	string s = buf;
	int n = s.size();
	int k = inp();
	//if (s.substr(0, 5) == "aaabe") writeln(k);
	string res = solve(s, k);
	writeln(res.c_str());
}

int main()
{

	int T = 1;
	//read(T);
	init();
	for (int test = 1; test <= T; ++test)
	{
		//write("Case #", test, ": ");
		solve();
	}

	return 0;
}