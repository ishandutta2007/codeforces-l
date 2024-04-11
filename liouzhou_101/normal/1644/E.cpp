#ifndef IO_H_
#define IO_H_

#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <string>
#include <type_traits>
#include <utility>

namespace io
{
	namespace internal
	{

//#ifndef ONLINE_JUDGE
#define FWRITE
//#endif

#ifdef FWRITE
#include <cstdio>
#else
#include <unistd.h>
		auto unistd_read = read;
		auto unistd_write = write;
#endif

		const int BUFSIZE = 1 << 20;
		int isize, osize;
		char ibuf[BUFSIZE + 10], obuf[BUFSIZE + 10];
		char* is = nullptr, * it = nullptr;
		char* os = obuf;
		constexpr char* ot = obuf + BUFSIZE;

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

	static inline bool read(char& x)
	{
		using namespace internal;
		if (is == it)
		{
			is = ibuf;
#ifdef FWRITE
			it = ibuf + fread(ibuf, 1, BUFSIZE, stdin);
#else
			it = ibuf + unistd_read(STDIN_FILENO, ibuf, BUFSIZE);
#endif
			if (is == it) return false;
		}
		x = *is++;
		return true;
	}

	static inline bool read(char* x)
	{
		do
		{
			if (!read(*x)) return false;
		} while (isspace(*x));
		for (++x; read(*x) && !isspace(*x); ++x);
		*x = 0;
		return true;
	}

	static inline bool read(std::string& s)
	{
		char c;
		do
		{
			if (!read(c)) return false;
		} while (isspace(c));
		s.clear();
		for (s += c; read(c) && !isspace(c); s += c);
		return true;
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_unsigned_v<T>, bool> read(T& x)
	{
		char ch = 0;
		do
		{
			if (!read(ch)) return false;
		} while (!isdigit(ch));
		for (x = ch - '0'; read(ch) && isdigit(ch); x = x * 10 + ch - '0');
		return true;
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_signed_v<T>, bool> read(T& x)
	{
		char ch = 0;
		bool sign = 0;
		do
		{
			if (!read(ch)) return false;
		} while (!isdigit(ch) && ch != '-');
		if (ch == '-')
		{
			sign = 1;
			x = 0;
		}
		else
			x = ch - '0';
		for (; read(ch) && isdigit(ch); x = x * 10 + ch - '0');
		if (sign) x = -x;
		return true;
	}

	// This implementation of reading floating point numbers does not cover all cases.
	// It is assumed that both integer and fractional parts can be stored in int64_t.
	// This assumption covers common cases and deserves efficiency.
	// If general cases are really needed, please use the function TODO.
	template<typename T>
	inline std::enable_if_t<std::is_floating_point_v<T>, bool> read(T& x)
	{
		constexpr T pow10[] = { 1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10,
			1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18 };
		char ch = 0;
		do
		{
			if (!read(ch)) return false;
		} while (!isdigit(ch) && ch != '-' && ch != '.');
		bool sign = ch == '-';
		if (sign)
			if (!read(ch)) return false;
		uint64_t a = 0;
		if (isdigit(ch))
		{
			a = ch - '0';
			while (read(ch) && isdigit(ch))
				a = a * 10 + ch - '0';
		}
		if (ch == '.')
		{
			uint64_t b = 0;
			int len = 0;
			while (read(ch) && isdigit(ch))
			{
				b = b * 10 + ch - '0';
				len++;
			}
			x = a + b / pow10[len];
		}
		else
			x = a;
		if (sign) x = -x;
		return true;
	}

	template<typename T, typename... Args>
	bool read(T& x, Args&... args)
	{
		return read(x) && read(args...);
	}

	static inline void write(const char& x)
	{
		using namespace internal;
		*os++ = x;
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

	static inline void write(const char* x)
	{
		for (; *x; ++x) write(*x);
	}

	static inline void write(const std::string& s)
	{
		write(s.c_str());
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_unsigned_v<T>, void> write(T x)
	{
		static char buf[22] = { };
		static char* it = buf + 20;
		static char* end = buf + 20;
		do
		{
			*--it = x % 10 + '0';
			x /= 10;
		} while (x);
		for (; it < end; ++it)
			write(*it);
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_unsigned_v<T>, void> write_number(T x, int fill)
	{
		static char buf[22] = { };
		static char* it = buf + 20;
		static char* end = buf + 20;
		do
		{
			*--it = x % 10 + '0';
			x /= 10;
		} while (x);
		for (int i = end - it; i < fill; ++i)
			write('0');
		for (; it < end; ++it)
			write(*it);
	}

	template<typename T>
	inline std::enable_if_t<!std::is_same_v<T, char>&& std::is_integral_v<T>&& std::is_signed_v<T>, void> write(const T& x)
	{
		if (x < 0) write('-'), write(std::make_unsigned_t<T>(-x));
		else write(std::make_unsigned_t<T>(x));
	}

	static inline void write_float(double x, int precision = 10)
	{
		if (std::isnan(x)) return write("NaN");
		if (std::isinf(x)) return write("Inf");
		if (x < 0) x = -x, write('-');
		constexpr double pow10[] = { 1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10, 
			1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18 };
		constexpr double pow10inv[] = { 1e-0, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9, 1e-10, 
			1e-11, 1e-12, 1e-13, 1e-14, 1e-15, 1e-16, 1e-17, 1e-18 };
		x += pow10inv[precision] * 0.5;
		uint64_t a = uint64_t(x);
		write(a);
		write('.');
		uint64_t b = uint64_t((x - a) * pow10[precision]);
		write_number(b, precision);
	}

	template<typename T>
	inline std::enable_if_t<std::is_floating_point_v<T>, void> write(const T& x)
	{
		write_float(double(x));
	}

	template<typename T, typename... Args>
	void write(const T& x, const Args&... args)
	{
		write(x), write(args...);
	}
	
	static inline void writeln()
	{
		write('\n');
	}

	template<typename T, typename... Args>
	void writeln(const T& x, const Args&... args)
	{
		write(x), writeln(args...);
	}

	template<typename T>
	T next()
	{
		T x;
		read(x);
		return std::move(x);
	}

	template<typename InputIt>
	bool input(InputIt first, InputIt last)
	{
		for (; first != last; ++first)
			if (!read(*first)) return false;
		return true;
	}

	template<typename Iterable>
	bool input(Iterable& a)
	{
		for (auto& x : a)
			if (!read(x)) return false;
		return true;
	}

	template<typename InputIt>
	void print(InputIt first, InputIt last, const char* sep = " ")
	{
		for (; first != last; )
		{
			write(*first);
			if (++first != last) write(sep);
		}
		writeln();
	}

	template<typename Iterable>
	void print(const Iterable& a, const char* sep = " ")
	{
		print(a.begin(), a.end(), sep);
	}

	template<typename InputIt>
	void println(InputIt first, InputIt last)
	{
		print(first, last, "\n");
	}

	template<typename Iterable>
	void println(const Iterable& a)
	{
		println(a.begin(), a.end());
	}
}

#endif

#ifndef BITS_H_
#define BITS_H_

#include <cstdint>

#ifdef __GNUC__

#define bit_popcount __builtin_popcount
#define bit_ctz __builtin_ctz
#define bit_clz __builtin_clz
#define bit_popcountll __builtin_popcountll
#define bit_ctzll __builtin_ctzll
#define bit_clzll __builtin_clzll

#else

static constexpr inline int32_t bit_popcount(uint32_t x)
{
	constexpr uint32_t m1 = 0x55555555;
	constexpr uint32_t m2 = 0x33333333;
	constexpr uint32_t m4 = 0x0f0f0f0f;
	constexpr uint32_t h01 = 0x01010101;
	x -= (x >> 1) & m1;
	x = (x & m2) + ((x >> 2) & m2);
	x = (x + (x >> 4)) & m4;
	return (x * h01) >> 24;
}

static constexpr inline int32_t bit_ctz(uint32_t x)
{
	return bit_popcount((x & -int32_t(x)) - 1);
}

static constexpr inline int32_t bit_clz(uint32_t x)
{
	int n = 0;
	if (!(x & 0xffff0000)) n += 16, x <<= 16;
	if (!(x & 0xff000000)) n += 8, x <<= 8;
	if (!(x & 0xf0000000)) n += 4, x <<= 4;
	if (!(x & 0xc0000000)) n += 2, x <<= 2;
	if (!(x & 0x80000000)) n += 1;
	return n;
}

static constexpr inline int32_t bit_popcountll(uint64_t x)
{
	constexpr uint64_t m1 = 0x5555555555555555;
	constexpr uint64_t m2 = 0x3333333333333333;
	constexpr uint64_t m4 = 0x0f0f0f0f0f0f0f0f;
	constexpr uint64_t h01 = 0x0101010101010101;
	x -= (x >> 1) & m1;
	x = (x & m2) + ((x >> 2) & m2);
	x = (x + (x >> 4)) & m4;
	return (x * h01) >> 56;
}

static constexpr inline int32_t bit_ctzll(uint64_t x)
{
	return bit_popcountll((x & -int64_t(x)) - 1);
}

static constexpr inline int32_t bit_clzll(uint64_t x)
{
	int n = 0;
	if (!(x & 0xffffffff00000000)) n += 32, x <<= 32;
	if (!(x & 0xffff000000000000)) n += 16, x <<= 16;
	if (!(x & 0xff00000000000000)) n += 8, x <<= 8;
	if (!(x & 0xf000000000000000)) n += 4, x <<= 4;
	if (!(x & 0xc000000000000000)) n += 2, x <<= 2;
	if (!(x & 0x8000000000000000)) n += 1;
	return n;
}

#endif

static constexpr inline int32_t bit_lg(uint32_t x)
{
	return 31 - bit_clz(x);
}

static constexpr inline int32_t bit_lgll(uint64_t x)
{
	return 63 - bit_clzll(x);
}

#endif

#ifndef SEGMENTTREE_H_
#define SEGMENTTREE_H_

#include <cassert>
#include <algorithm>
#include <vector>

namespace data_structure
{
	// 0-indexed segment tree.
	// Every query range has the form [l, r).
	template<typename ValueType, typename ValueMerge,
		typename TagType, typename TagMerge, typename TagSpread>
	class SegmentTree
	{
	private:
		int n, lg, size;
		const ValueType value_init;
		const ValueMerge& value_merge;
		const TagType tag_init;
		const TagMerge& tag_merge;
		const TagSpread& tag_spread;
		std::vector<ValueType> value;
		std::vector<TagType> tag;
		void Update(int k)
		{
			value[k] = value_merge(value[k << 1], value[k << 1 | 1]);
		}
		void AddTag(int k, const TagType& cur_tag)
		{
			tag_spread(cur_tag, value[k]);
			if (k < size) tag_merge(cur_tag, tag[k]);
		}
		void PushTag(int k)
		{
			AddTag(k << 1, tag[k]);
			AddTag(k << 1 | 1, std::move(tag[k]));
			tag[k] = tag_init;
		}
	public:
		template<typename InputIt>
		explicit SegmentTree(InputIt first, InputIt last, const ValueType& value_init, const ValueMerge& value_merge,
			const TagType& tag_init, const TagMerge& tag_merge, const TagSpread& tag_spread) : 
			n(last - first), value_init(value_init), value_merge(value_merge), 
			tag_init(tag_init), tag_merge(tag_merge), tag_spread(tag_spread)
		{
			assert(n >= 1);
			lg = bit_lg(2 * n - 1);
			size = 1 << lg;
			value = std::vector<ValueType>(size << 1, value_init);
			tag = std::vector<TagType>(size, tag_init);
			std::copy(first, last, value.begin() + size);
			for (int k = size - 1; k >= 1; --k) Update(k);
		}
		explicit SegmentTree(const std::vector<ValueType>& data, const ValueType& value_init, const ValueMerge& value_merge,
			const TagType& tag_init, const TagMerge& tag_merge, const TagSpread& tag_spread) :
			SegmentTree(data.begin(), data.end(), value_init, value_merge, tag_init, tag_merge, tag_spread)
		{ }
		explicit SegmentTree(int n, const ValueType& value_init, const ValueMerge& value_merge,
			const TagType& tag_init, const TagMerge& tag_merge, const TagSpread& tag_spread) :
			SegmentTree(std::vector<ValueType>(n, value_init), value_init, value_merge, tag_init, tag_merge, tag_spread)
		{ }
		ValueType Query(int left, int right)
		{
			assert(0 <= left && left <= right && right <= n);
			if (left == right) return value_init;
			left += size, right += size;
			for (int k = lg; k >= 1; --k)
			{
				if ((left >> k << k) != left) PushTag(left >> k);
				if ((right >> k << k) != right) PushTag((right - 1) >> k);
			}
			ValueType left_res = value_init, right_res = value_init;
			for (; left < right; left >>= 1, right >>= 1)
			{
				if (left & 1) left_res = value_merge(std::move(left_res), value[left++]);
				if (right & 1) right_res = value_merge(value[--right], std::move(right_res));
			}
			return value_merge(std::move(left_res), std::move(right_res));
		}
		ValueType Query(int pos)
		{
			assert(0 <= pos && pos < n);
			pos += size;
			for (int k = lg; k >= 1; --k) PushTag(pos >> k);
			return value[pos];
		}
		void ModifyTag(int left, int right, const TagType& add_tag)
		{
			assert(0 <= left && left <= right && right <= n);
			if (left == right) return;
			left += size, right += size;
			for (int k = lg; k >= 1; --k)
			{
				if ((left >> k << k) != left) PushTag(left >> k);
				if ((right >> k << k) != right) PushTag((right - 1) >> k);
			}
			for (int l = left, r = right; l < r; l >>= 1, r >>= 1)
			{
				if (l & 1) AddTag(l++, add_tag);
				if (r & 1) AddTag(--r, add_tag);
			}
			for (int k = 1; k <= lg; ++k)
			{
				if ((left >> k << k) != left) Update(left >> k);
				if ((right >> k << k) != right) Update((right - 1) >> k);
			}
		}
		void ModifyTag(int pos, const TagType& add_tag)
		{
			assert(0 <= pos && pos < n);
			pos += size;
			for (int k = lg; k >= 1; --k) PushTag(pos >> k);
			AddTag(pos, add_tag);
			for (int k = 1; k <= lg; ++k) Update(pos >> k);
		}
		void ModifyValue(int pos, const ValueType& new_value)
		{
			assert(0 <= pos && pos < n);
			pos += size;
			for (int k = lg; k >= 1; --k) PushTag(pos >> k);
			value[pos] = new_value;
			for (int k = 1; k <= lg; ++k) Update(pos >> k);
		}
		// Find the leftmost position "right" such that
		//   1. left < right <= n,
		//   2. check(value_merge(value[left], ..., value[right - 1])) = true.
		// If not found, right = -1.
		template<typename Checker>
		int FindFirst(int left, const Checker& check)
		{
			assert(0 <= left && left <= n);
			if (left == n) return -1;
			left += size;
			for (int k = lg; k >= 1; --k) PushTag(left >> k);
			ValueType cur = value_init;
			do
			{
				left >>= bit_ctz(left);
				if (check(value_merge(cur, value[left])))
				{
					while (left < size)
					{
						PushTag(left);
						left <<= 1;
						if (ValueType tmp = value_merge(cur, value[left]); !check(tmp))
							cur = tmp, left += 1;
					}
					return left - size + 1;
				}
				cur = value_merge(std::move(cur), value[left++]);
			} while ((left & -left) != left);
			return -1;
		}
		// Find the rightmost position "left" such that
		//   1. 0 <= left < right,
		//   2. check(value_merge(value[left], ..., value[right - 1])) = true.
		// If not found, left = -1.
		template<typename Checker>
		int FindLast(int right, const Checker& check)
		{
			assert(0 <= right && right <= n);
			if (right == 0) return -1;
			right += size;
			for (int k = lg; k >= 1; --k) PushTag((right - 1) >> k);
			ValueType cur = value_init;
			do
			{
				right >>= bit_ctz(right);
				if (right) right -= 1;
				if (check(value_merge(value[right], cur)))
				{
					while (right < size)
					{
						PushTag(right);
						(right <<= 1) += 1;
						if (ValueType tmp = value_merge(value[right], cur); !check(tmp))
							cur = tmp, right -= 1;
					}
					return right - size;
				}
				cur = value_merge(value[right], std::move(cur));
			} while ((right & -right) != right);
			return -1;
		}
	};
}

#endif

#include <bits/stdc++.h>

using namespace std;
using namespace io;
//using namespace algorithm;
//using namespace data_structure;

template<class T>
bool freshmax(T& a, const T& b)
{
	return a < b ? a = b, 1 : 0;
}

template<class T>
bool freshmin(T& a, const T& b)
{
	return a > b ? a = b, 1 : 0;
}

//using modular = algorithm::SafeModularInt32<998244353>;
//using modular = algorithm::SafeModularInt32<1000000007>;
//using modint = algorithm::ModInt<modular>;

using ll = int64_t;
using ld = long double;

//const int INF = 1000000000;
//const ll INF = 1000000000000000000LL;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

// string
vector<string> split(const string& s, char stop)
{
	vector<string> ret;
	string t;
	for (auto c : s)
	{
		if (c == stop)
		{
			ret.push_back(t);
			t = "";
		}
		else
			t += c;
	}
	ret.push_back(t);
	return ret;
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 500010;

void solve()
{
	int n;
	read(n);
	string s;
	read(s);
	int q = s.size();
	vector<int> sx(q + 1), sy(q + 1);
	for (int i = 0; i < q; ++i)
	{
		sx[i + 1] = sx[i] + (s[i] == 'D');
		sy[i + 1] = sy[i] + (s[i] == 'R');
	}
	vector<int> px, py;
	px.push_back(0);
	px.push_back(n);
	py.push_back(0);
	py.push_back(n);
	vector<tuple<int, int, int, int>> ev;
	auto add = [&](int x1, int y1, int x2, int y2)
	{
		// [x1, x2) times [y1, y2)
		px.push_back(x1);
		px.push_back(x2);
		py.push_back(y1);
		py.push_back(y2);
		ev.push_back({ x1,y1,x2,y2 });
		//writeln(x1, ' ', y1, ' ', x2, ' ', y2);
	};
	add(0, 0, 1, 1);
	for (int i = 0; i < q; ++i)
	{
		int x = sx[i + 1], y = sy[i + 1];
		int extra_x = sx[q] - sx[i + 1], extra_y = sy[q] - sy[i + 1];
		if (x && y)
		{
			add(x, y, n - extra_x, n - extra_y);
		}
		else if (x)
		{
			add(x, 0, n - extra_x, 1);
		}
		else if (y)
		{
			add(0, y, 1, n - extra_y);
		}
	}
	sort(px.begin(), px.end());
	px.erase(unique(px.begin(), px.end()), px.end());
	sort(py.begin(), py.end());
	py.erase(unique(py.begin(), py.end()), py.end());
	vector<vector<pair<int, int>>> v(px.size()), w(px.size());
	for (auto [x1, y1, x2, y2] : ev)
	{
		x1 = lower_bound(px.begin(), px.end(), x1) - px.begin();
		x2 = lower_bound(px.begin(), px.end(), x2) - px.begin();
		y1 = lower_bound(py.begin(), py.end(), y1) - py.begin();
		y2 = lower_bound(py.begin(), py.end(), y2) - py.begin();
		v[x1].push_back({ y1, y2 });
		w[x2].push_back({ y1, y2 });
	}

	const int INF = 1000000000;
	struct ValueType
	{
		int minv, cnt;
	};
	ValueType value_init = { INF, 0 };
	auto value_merge = [](const ValueType& a, const ValueType& b) -> ValueType
	{
		if (a.minv < b.minv)
			return ValueType{ a.minv, a.cnt };
		else if (a.minv > b.minv)
			return ValueType{ b.minv, b.cnt };
		else
			return ValueType{ a.minv, a.cnt + b.cnt };
	};

	struct TagType
	{
		int add;
	};
	TagType tag_init = { 0 };
	auto tag_merge = [](const TagType& a, TagType& b) -> void
	{
		b.add += a.add;
	};
	auto tag_spread = [](const TagType& tag, ValueType& value) -> void
	{
		value.minv += tag.add;
	};

	vector<ValueType> tmp(py.size() - 1);
	for (int i = 0; i + 1 < py.size(); ++i)
	{
		tmp[i] = { 0, py[i + 1] - py[i] };
	}

	data_structure::SegmentTree<ValueType, decltype(value_merge), TagType, decltype(tag_merge), decltype(tag_spread)>
		tree(tmp.begin(), tmp.end(), value_init, value_merge, tag_init, tag_merge, tag_spread);
	
	ll res = 0;
	for (int i = 0; i + 1 < px.size(); ++i)
	{
		for (auto [l, r] : w[i])
		{
			tree.ModifyTag(l, r, TagType{ -1 });
		}
		for (auto [l, r] : v[i])
		{
			tree.ModifyTag(l, r, TagType{ 1 });
		}
		auto [minv, cnt] = tree.Query(0, py.size() - 1);
		if (minv == 0)
		{
			res += ll(px[i + 1] - px[i]) * (n - cnt);
		}
		else
		{
			res += ll(px[i + 1] - px[i]) * n;
		}
	}
	writeln(res);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("try.in", "r", stdin);
	//freopen("try.out", "w", stdout);
#endif
	int tests = 1;
	tests = next<int>();
	for (int test = 1; test <= tests; ++test)
	{
		//write("Case #", test, ": ");
		solve();
	}
	return 0;
}