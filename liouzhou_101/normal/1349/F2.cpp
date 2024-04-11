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
const int MAXN = 5010;

//int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
//int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

ld det(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3)
{
	return x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
}

//polynomial inverse && sqrt added

const int MOD = 998244353;

struct mod_int {
	int val;

	mod_int(long long v = 0) {
		if (v < 0)
			v = v % MOD + MOD;

		if (v >= MOD)
			v %= MOD;

		val = v;
	}

	static int mod_inv(int a, int m = MOD) {
		// https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
		int g = m, r = a, x = 0, y = 1;

		while (r != 0) {
			int q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}

		return x < 0 ? x + m : x;
	}

	explicit operator int() const {
		return val;
	}

	mod_int& operator+=(const mod_int& other) {
		val += other.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}

	mod_int& operator-=(const mod_int& other) {
		val -= other.val;
		if (val < 0) val += MOD;
		return *this;
	}

	static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
		return x % m;
	}

	mod_int& operator*=(const mod_int& other) {
		val = fast_mod((uint64_t)val * other.val);
		return *this;
	}

	mod_int& operator/=(const mod_int& other) {
		return *this *= other.inv();
	}

	friend mod_int operator+(const mod_int& a, const mod_int& b) { return mod_int(a) += b; }
	friend mod_int operator-(const mod_int& a, const mod_int& b) { return mod_int(a) -= b; }
	friend mod_int operator*(const mod_int& a, const mod_int& b) { return mod_int(a) *= b; }
	friend mod_int operator/(const mod_int& a, const mod_int& b) { return mod_int(a) /= b; }

	mod_int& operator++() {
		val = val == MOD - 1 ? 0 : val + 1;
		return *this;
	}

	mod_int& operator--() {
		val = val == 0 ? MOD - 1 : val - 1;
		return *this;
	}

	mod_int operator++(int) { mod_int before = *this; ++* this; return before; }
	mod_int operator--(int) { mod_int before = *this; --* this; return before; }

	mod_int operator-() const {
		return val == 0 ? 0 : MOD - val;
	}

	bool operator==(const mod_int& other) const { return val == other.val; }
	bool operator!=(const mod_int& other) const { return val != other.val; }

	mod_int inv() const {
		return mod_inv(val);
	}

	mod_int pow(long long p) const {
		assert(p >= 0);
		mod_int a = *this, result = 1;

		while (p > 0) {
			if (p & 1)
				result *= a;

			a *= a;
			p >>= 1;
		}

		return result;
	}

	friend ostream& operator<<(ostream& stream, const mod_int& m) {
		return stream << m.val;
	}
};

const mod_int INV2 = mod_int(2).inv();

namespace NTT {
	vector<mod_int> roots = { 0, 1 };
	vector<int> bit_reverse;
	int max_size = -1;
	mod_int root;

	bool is_power_of_two(int n) {
		return (n & (n - 1)) == 0;
	}

	int round_up_power_two(int n) {
		assert(n > 0);

		while (n & (n - 1))
			n = (n | (n - 1)) + 1;

		return n;
	}

	// Given n (a power of two), finds k such that n == 1 << k.
	int get_length(int n) {
		assert(is_power_of_two(n));
		return __builtin_ctz(n);
	}

	// Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
	// This makes even-odd div-conquer much easier.
	void bit_reorder(int n, vector<mod_int>& values) {
		if ((int)bit_reverse.size() != n) {
			bit_reverse.assign(n, 0);
			int length = get_length(n);

			for (int i = 0; i < n; i++)
				bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
		}

		for (int i = 0; i < n; i++)
			if (i < bit_reverse[i])
				swap(values[i], values[bit_reverse[i]]);
	}

	void find_root() {
		int order = MOD - 1;
		max_size = 1;

		while (order % 2 == 0) {
			order /= 2;
			max_size *= 2;
		}

		root = 2;

		// Find a max_size-th primitive root of MOD.
		while (!(root.pow(max_size) == 1 && root.pow(max_size / 2) != 1))
			root++;
	}

	void prepare_roots(int n) {
		if (max_size < 0)
			find_root();

		assert(n <= max_size);

		if ((int)roots.size() >= n)
			return;

		int length = get_length(roots.size());
		roots.resize(n);

		// The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
		// the first half of the n-th primitive roots of MOD.
		while (1 << length < n) {
			// z is a 2^(length + 1)-th primitive root of MOD.
			mod_int z = root.pow(max_size >> (length + 1));

			for (int i = 1 << (length - 1); i < 1 << length; i++) {
				roots[2 * i] = roots[i];
				roots[2 * i + 1] = roots[i] * z;
			}

			length++;
		}
	}

	void fft_iterative(int N, vector<mod_int>& values) {
		assert(is_power_of_two(N));
		prepare_roots(N);
		bit_reorder(N, values);

		for (int n = 1; n < N; n *= 2)
			for (int start = 0; start < N; start += 2 * n)
				for (int i = 0; i < n; i++) {
					mod_int even = values[start + i];
					mod_int odd = values[start + n + i] * roots[n + i];
					values[start + n + i] = even - odd;
					values[start + i] = even + odd;
				}
	}

	const int FFT_CUTOFF = 150;

	vector<mod_int> mod_multiply(vector<mod_int> left, vector<mod_int> right) {
		int n = left.size();
		int m = right.size();

		// Brute force when either n or m is small enough.
		if (min(n, m) < FFT_CUTOFF) {
			const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t)MOD * MOD;
			vector<uint64_t> result(n + m - 1);

			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					result[i + j] += (uint64_t)((int)left[i]) * ((int)right[j]);

					if (result[i + j] > ULL_BOUND)
						result[i + j] %= MOD;
				}

			for (uint64_t& x : result)
				if (x >= MOD)
					x %= MOD;

			return vector<mod_int>(result.begin(), result.end());
		}

		int N = round_up_power_two(n + m - 1);
		left.resize(N);
		right.resize(N);

		bool equal = left == right;
		fft_iterative(N, left);

		if (equal)
			right = left;
		else
			fft_iterative(N, right);

		mod_int inv_N = mod_int(N).inv();

		for (int i = 0; i < N; i++)
			left[i] *= right[i] * inv_N;

		reverse(left.begin() + 1, left.end());
		fft_iterative(N, left);
		left.resize(n + m - 1);
		return left;
	}

	vector<mod_int> mod_power(const vector<mod_int>& v, int exponent) {
		assert(exponent >= 0);
		vector<mod_int> result = { 1 };

		if (exponent == 0)
			return result;

		for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
			result = mod_multiply(result, result);

			if (exponent >> k & 1)
				result = mod_multiply(result, v);
		}

		return result;
	}
}

vector<mod_int> inv, factorial, inv_factorial;

void prepare_factorials(int maximum) {
	inv.assign(maximum + 1, 1);

	// Make sure MOD is prime, which is necessary for the inverse algorithm below.
	for (int p = 2; p * p <= MOD; p++)
		assert(MOD % p != 0);

	for (int i = 2; i <= maximum; i++)
		inv[i] = inv[MOD % i] * (MOD - MOD / i);

	factorial.resize(maximum + 1);
	inv_factorial.resize(maximum + 1);
	factorial[0] = inv_factorial[0] = 1;

	for (int i = 1; i <= maximum; i++) {
		factorial[i] = i * factorial[i - 1];
		inv_factorial[i] = inv[i] * inv_factorial[i - 1];
	}
}

mod_int choose(long long n, long long r) {
	if (r < 0 || r > n)
		return 0;

	return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
}

mod_int inv_choose(long long n, long long r) {
	assert(0 <= r && r <= n);
	return inv_factorial[n] * factorial[r] * factorial[n - r];
}

mod_int permute(long long n, long long k) {
	if (k < 0 || k > n)
		return 0;

	return factorial[n] * inv_factorial[n - k];
}

mod_int inv_permute(long long n, long long k) {
	assert(0 <= k && k <= n);
	return inv_factorial[n] * factorial[n - k];
}

using poly = vector<mod_int>;

poly mod_multiply_together(const vector<poly>& v)
{
	if (v.empty()) return poly{ 1 };
	struct poly_node
	{
		poly p;
		bool operator < (const poly_node& rhs) const
		{
			return p.size() > rhs.p.size();
		}
	};
	priority_queue<poly_node> q;
	for (auto& p : v) q.push({ p });
	while (q.size() > 1)
	{
		auto a = q.top();
		q.pop();
		auto b = q.top();
		q.pop();
		q.push({ NTT::mod_multiply(a.p, b.p) });
	}
	return q.top().p;
}

// a*n mod x^n
poly poly_multiply(const poly& a, const poly& b, int n)
{
	auto c = NTT::mod_multiply(a, b);
	c.resize(n);
	return c;
}

// a^{-1} mod x^n
poly poly_inverse(const poly& a, int n)
{
	if (n == 1)
	{
		assert(a[0] != 0);
		return poly{ a[0].inv() };
	}
	int m = (n + 1) / 2;
	poly b(m);
	for (int i = 0; i < m && i < a.size(); ++i) b[i] = a[i];
	b = poly_inverse(b, m);
	auto c = poly_multiply(b, a, n);
	for (int i = 0; i < n; ++i) c[i] = -c[i];
	c[0] += 2;
	return poly_multiply(b, c, n);
}

// sqrt(a) mod x^n provided that a(0) = 1
poly poly_sqrt(const poly& a, int n)
{
	if (n == 1)
	{
		assert(a[0] == 1);
		return poly{ 1 };
	}
	int m = (n + 1) / 2;
	poly b(m);
	for (int i = 0; i < m && i < a.size(); ++i) b[i] = a[i];
	b = poly_sqrt(b, m);
	b.resize(n);
	auto c = poly_multiply(poly_inverse(b, n), a, n);
	for (int i = 0; i < m; ++i)
		c[i] += b[i];
	for (int i = 0; i < n; ++i)
		c[i] *= INV2;
	return c;
}

// a'(x) mod x^n
poly poly_derivate(const poly& a, int n)
{
	poly b(n);
	for (int i = 1; i < n && i < a.size(); ++i)
		b[i - 1] = i * a[i];
	return b;
}

// \int a(x) dx mod x^n
poly poly_integrate(const poly& a, int n)
{
	if (inv.size() <= n) prepare_factorials(n);
	poly b(n);
	for (int i = 0; i + 1 < n && i + 1 < a.size(); ++i)
		b[i + 1] = a[i] * inv[i + 1];
	return b;
}

// ln(a) mod x^n provided that a(0) = 1
poly poly_ln(const poly& a, int n)
{
	assert(a[0] == 1);
	return poly_integrate(poly_multiply(poly_inverse(a, n), poly_derivate(a, n), n), n);
}

// exp(a) mod x^n provided that a(0) = 0
poly poly_exp(const poly& a, int n)
{
	if (n == 1)
	{
		assert(a[0] == 0);
		return poly{ 1 };
	}
	int m = (n + 1) / 2;
	poly b(m);
	for (int i = 0; i < m && i < a.size(); ++i) b[i] = a[i];
	b = poly_exp(b, m);
	auto c = poly_ln(b, n);
	int tmp = min((int)a.size(), n);
	for (int i = 0; i < tmp; ++i) c[i] = a[i] - c[i];
	for (int i = tmp; i < n; ++i) c[i] = -c[i];
	c[0] += 1;
	return poly_multiply(b, c, n);
}

poly poly_power(poly& v, int exponent, int n) {
	assert(exponent >= 0);
	vector<mod_int> result = { 1 };

	if (exponent == 0)
		return result;

	if (v[0] == 1) // special case
	{
		result = poly_ln(v, n);
		for (int i = 0; i < n; ++i) result[i] *= exponent;
		result = poly_exp(result, n);
		return result;
	}

	// general case, the following code is not optimized yet.
	for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
		result = poly_multiply(result, result, n);

		if (exponent >> k & 1)
			result = poly_multiply(result, v, n);
	}

	return result;
}

void solve()
{
	int n = inp();
	int N = n + 7;
	prepare_factorials(N);

	auto calc = [&](const poly& C, const poly& D)
	{
		auto b = poly_derivate(C, N);
		for (int i = N - 1; i >= 1; --i) b[i] = b[i - 1];
		b[0] = 0;
		for (int i = 0; i < N; ++i) b[i] -= 2 * C[i];
		auto P = poly_multiply(b, D, N);

		poly lhs(N), rhs(N);
		for (int i = 0; i < N; ++i)
		{
			lhs[i] = n + 2 - i >= 0 ? inv_factorial[i] * P[n + 2 - i] : 0;
			rhs[i] = inv_factorial[i];
		}
		auto res = poly_multiply(lhs, rhs, N);
		for (int i = 0; i < N; ++i) res[i] *= factorial[i];

		b = C;
		for (int i = N - 1; i >= 1; --i) b[i] = b[i - 1];
		b[0] = 0;
		P = poly_multiply(b, D, N);
		for (int i = 0; i < N; ++i)
		{
			lhs[i] = n + 2 - i >= 0 ? inv_factorial[i] * P[n + 2 - i] : 0;
			rhs[i] = inv_factorial[i];
		}
		auto tmp = poly_multiply(lhs, rhs, N);
		for (int i = 0; i < N; ++i) tmp[i] *= factorial[i];
		for (int i = N - 1; i >= 1; --i) tmp[i] = tmp[i - 1] * i;
		tmp[0] = 0;

		for (int i = 0; i < N; ++i) res[i] += tmp[i];
		return res;
	};

	poly res(N);
	
	poly z1{ 1,1 };
	auto inv_z1 = poly_inverse(z1, N);
	poly z{ 0,1 };
	auto invA = poly_multiply(z, inv_z1, N);
	auto b = poly_multiply(poly_exp(invA, N), inv_z1, N);
	for (int i = 0; i < N; ++i) b[i] = -b[i];
	b[0] += 1;
	b = poly_multiply(inv_z1, b, N);
	assert(b[0] == 0 && b[1] == 0 && b[2] != 0);
	poly C(N);
	for (int i = 0; i < N - 2; ++i) C[i] = b[i + 2];
	C = poly_inverse(C, N);
	auto D = poly_power(z1, n, N);
	auto tmp = calc(C, D);
	for (int i = 0; i < N; ++i) res[i] += tmp[i];

	b = invA;
	invA = poly_ln(z1, N);
	for (int i = 0; i < N; ++i) b[i] -= invA[i];
	assert(b[0] == 0 && b[1] == 0 && b[2] != 0);
	C = poly(N);
	for (int i = 0; i < N - 2; ++i) C[i] = b[i + 2];
	C = poly_inverse(C, N);
	b = poly_ln(z1, N);
	D = poly(N);
	for (int i = 0; i < N - 1; ++i) D[i] = b[i + 1];
	D = poly_inverse(D, N);
	D = poly_power(D, n, N);
	tmp = calc(C, D);
	for (int i = 0; i < N; ++i) res[i] += tmp[i];

	poly y1{ 1, -1 };
	tmp = poly_power(y1, n + 2, N);
	res = poly_multiply(tmp, res, N);

	mod_int invn = mod_int(n).inv();
	for (int i = 1; i <= n; ++i) res[i] *= factorial[n-1];

	for (int i = 1; i <= n; ++i)
		write(int(res[i]), i == n ? '\n' : ' ');
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