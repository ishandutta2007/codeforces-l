#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
 
#define X first
#define Y second
 
//#include <boost/unordered_map.hpp>
//using namespace boost;
 
/*
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
//rbtree T;
template<class T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//rbtree<int> T;
//template<class T, class cmp = less<T>, class tag = pairing_heap_tag>
//using pqueue = __gnu_pbds::priority_queue<T, cmp, tag>;
template<class T, class cmp = less<T>>
using pqueue = __gnu_pbds::priority_queue<T, cmp>;
//pqueue<int> T;
*/
 
using i32 = int;
using i64 = long long;
using u8 = unsigned char;
using u32 = unsigned;
using u64 = unsigned long long;
using f64 = double;
using f80 = long double;
//using i128 = __int128_t;
//using u128 = __uint128_t;
//using i128 = i64;
//using u128 = u64;
 
ll power(ll a, ll b, ll p)
{
	if (!b) return 1;
	ll t = power(a, b/2, p);
	t = t*t%p;
	if (b&1) t = t*a%p;
	return t;
}
 
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll px, py;
	ll d = exgcd(b, a%b, px, py);
	x = py;
	y = px-a/b*py;
	return d;
}
 
template<class T>
inline void freshmin(T &a, const T &b)
{
	if (a > b) a = b;
}
 
template<class T>
inline void freshmax(T &a, const T &b)
{
	if (a < b) a = b;
}
 
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
 
//#define FWRITE
 
namespace io
{
 
#ifndef FWRITE
#include <unistd.h>
#endif
const int BUFSIZE = 1<<20;
 
int isize, osize;
char ibuf[BUFSIZE+10], obuf[BUFSIZE+10];
char *is, *it, *os = obuf, *ot = obuf+BUFSIZE;
 
char getchar()
{
	if (is == it)
	{
		is = ibuf;
		#ifdef FWRITE
		it = ibuf+fread(ibuf, 1, BUFSIZE, stdin);
		#else
		it = ibuf+read(STDIN_FILENO, ibuf, BUFSIZE);
		#endif
		if (is == it) return EOF;
	}
	return *is ++;
}
 
char getalpha()
{
	char c = getchar();
	while (!isalpha(c)) c = getchar();
	return c;
}
 
void putchar(char c)
{
	*os ++ = c;
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
	for(ch = getchar(); !isdigit(ch); ch = getchar())
	{
		//if (ch == EOF) return -1;
		if(ch == '-') f = 1;
	}
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return f ? -x : x;
}
 
ll inp_ll() {
	ll x = 0; int f = 0; char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = 1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return f ? -x : x;
}
 
template<class T>
bool read(T &x)
{
	x = 0;
	char ch = getchar();
	if (ch == EOF) return 0;
	for(; !isdigit(ch); )
	{
		ch = getchar();
		if (ch == EOF) return 0;
	}
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return 1;
}
 
template<class T>
void write(T x)
{
	static char s[22];
	static char *it = s+20;
	static char *end = s+20;
	
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	
	do
	{
		*-- it = x%10+'0';
		x /= 10;
	}
	while (x);
	/*
	if (!x)
		*-- it = '0';
	while (x)
	{
		*-- it = x%10+'0';
		x /= 10;
	}
	*/
	for (; it < end; ++ it)
		putchar(*it);
}
 
template<>
void write(const char *s)
{
	for (; *s; ++ s) putchar(*s);
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
			fwrite(obuf, 1, os-obuf, stdout);
			#else
			write(STDOUT_FILENO, obuf, os-obuf);
			#endif
	}
}__ender;
 
}
 
template<class T>
void print(const T &a)
{
	for (auto x : a) printf("%d ", x); puts("");
}
 
const int MAXN = 500010;
//const int MAXM = 3000010;
const int MAXK = 20;
//const int INF = 1000000000;
const i64 INF = 2000000000000000000LL;
const int MOD = 998244353;
//const int INV2 = (MOD+1)/2;
//const int INV6 = power(6, MOD-2, MOD);
 
using namespace io;
 
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
 
#define rep(i,a,b) for (int i = (a), I = (b); i <= I; ++ i)
 
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
 
int F[MAXN];
 
int father(int x)
{
	return F[x] == x ? x : F[x] = father(F[x]);
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
		pushdown(a[k], L, R, a[k<<1], a[k<<1|1]);
	}
	void update(int k)
	{
		merge(a[k], a[k<<1], a[k<<1|1]);
	}
	void build(int k, int L, int R)
	{
		if (L == R)
		{
			initialize(a[k], L);
			return;
		}
		int m = (L+R)>>1;
		build(k<<1, L, m);
		build(k<<1|1, m+1, R);
		update(k);
	}
	segment_tree(int n, const initialize_type &initialize, const merge_type &merge, const pushdown_type &pushdown)
	{
		assert(n >= 1);
		this->n = n;
		this->initialize = initialize;
		this->merge = merge;
		this->pushdown = pushdown;
		a = vector<T>(4*n+1);
		build(1, 1, n);
	}
	
	using modifier_type = function<void(T&, int, int)>;
	void modify(int k, int L, int R, int x, int y, const modifier_type &modifier)
	{
		if (L == x && R == y)
		{
			modifier(a[k], L, R);
			return;
		}
		int m = (L+R)>>1;
		clear(k, L, R);
		if (y <= m)
			modify(k<<1, L, m, x, y, modifier);
		else if (x > m)
			modify(k<<1|1, m+1, R, x, y, modifier);
		else
		{
			modify(k<<1, L, m, x, m, modifier);
			modify(k<<1|1, m+1, R, m+1, y, modifier);
		}
		update(k);
	}
	void modify(int x, int y, const modifier_type &modifier)
	{
		assert(1 <= x && x <= y && y <= n);
		modify(1, 1, n, x, y, modifier);
	}
	
	template<class result_type, class convert_type = function<result_type(const T&)>, class calculate_type = function<result_type(const result_type&, const result_type&)>>
	result_type query(int k, int L, int R, int x, int y, const convert_type &convert, const calculate_type &calculate)
	{
		if (L == x && R == y)
			return convert(a[k]);
		int m = (L+R)>>1;
		clear(k, L, R);
		if (y <= m)
			return query<result_type>(k<<1, L, m, x, y, convert, calculate);
		if (x > m)
			return query<result_type>(k<<1|1, m+1, R, x, y, convert, calculate);
		return calculate(query<result_type>(k<<1, L, m, x, m, convert, calculate), query<result_type>(k<<1|1, m+1, R, m+1, y, convert, calculate));
	}
	template<class result_type, class convert_type = function<result_type(const T&)>, class calculate_type = function<result_type(const result_type&, const result_type&)>>
	result_type query(int x, int y, const convert_type &convert, const calculate_type &calculate)
	{
		assert(1 <= x && x <= y && y <= n);
		return query<result_type>(1, 1, n, x, y, convert, calculate);
	}
	
	T query(int x, int y)
	{
		assert(1 <= x && x <= y && y <= n);
		function<T(const T&)> convert = [](const T &it) -> T
		{
			return it;
		};
		function<T(const T&, const T&)> calculate = [&](const T &Lc, const T &Rc) -> T
		{
			T ret;
			merge(ret, Lc, Rc);
			return ret;
		};
		return query<T>(x, y, convert, calculate);
	}
};

int n, q;
ll a[MAXN];
ll t[MAXN];
	

void solve()
{
	n = inp();
	q = inp();
	for (int i = 1; i <= n; ++ i)
	{
		a[i] = inp();
		a[i] = (a[i])*power(100, MOD-2, MOD)%MOD;
	}
	
	for (int i = n; i >= 1; -- i)
	{
		t[i] = (t[i+1]*a[i]+a[i])%MOD;
	}
	
	using node = ll;
	auto initialize = [&](node &it, int id) -> void
	{
		it = a[id];
		/*
		it = 0;
		if (id == 1) it = 100LL*power(a[id], MOD-2, MOD)%MOD;
		*/
	};
	auto merge = [&](node &it, const node& Lc, const node& Rc) -> void
	{
		it = (Lc*Rc)%MOD;
	};
	auto pushdown = [&](node &it, int L, int R, node &Lc, node &Rc) -> void
	{
	};
	segment_tree<node> T(n, initialize, merge, pushdown);
	
	auto calc = [&](int x, int y)
	{
		if (x == y)
		{
			ll tmp = T.query(x,x);
			ll ans = power(tmp, MOD-2, MOD);
			return ans;
		}
		if (x+1 == y)
		{
			ll p1 = a[x];
			ll p2 = a[x+1];
			ll ans = (1+power(p1, MOD-2, MOD))*power(p2, MOD-2, MOD)%MOD;
			return ans;
		}
		ll tmp = (t[x+1]-t[y]*T.query(x+1, y-1)%MOD+MOD)%MOD;
		
		ll p1 = a[x];
		ll ans = (1+power(p1, MOD-2, MOD)+tmp)*power(T.query(x+1, y), MOD-2, MOD)%MOD;
		
		return ans;
	};
	
	set<int> H;
	H.insert(1);
	H.insert(n+1);
	ll ans = calc(1, n);
	
	while (q --)
	{
		int x = inp();
		if (H.count(x))
		{
			auto it = H.lower_bound(x);
			auto itx = it; itx --;
			auto ity = it; ity ++;
			ans = ans-calc(*itx, x-1)+MOD;
			ans = ans-calc(x, *ity-1)+MOD;
			ans = ans+calc(*itx, *ity-1);
			ans %= MOD;
			H.erase(x);
		}
		else
		{
			H.insert(x);
			auto it = H.lower_bound(x);
			auto itx = it; itx --;
			auto ity = it; ity ++;
			ans = ans+calc(*itx, x-1);
			ans = ans+calc(x, *ity-1);
			ans = ans-calc(*itx, *ity-1)+MOD;
			ans %= MOD;
		}
		/*
		H.modify(x, x, [&](node& it, int L, int R)
		{
			if (u[x] == 1)
				it = 100LL*power(a[L], MOD-2, MOD)%MOD;
			else
				it = 0;
		});
		ll ans = H.query(1, n);
		*/
		writeln(ans);
	}
}

int32_t main()
{
	
	//for (int T = inp(); T --; )
		solve();
	
	return 0;
}