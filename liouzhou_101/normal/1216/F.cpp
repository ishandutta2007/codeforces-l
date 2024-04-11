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
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
rbtree T;
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

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a%b) : a;
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

template<class T>
void print(const T &a)
{
	for (auto x : a) printf("%d ", x); puts("");
}

const int MAXN = 400010;
const int MAXM = 30*30*16*16+10;
const int MAXK = 19;
const i64 INF = 1000000000000000000LL;
//const int INF = 1000000000;
//const int MOD = 998244353;
//const int MOD = 1000000007;
//const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, k;
char s[MAXN];

ll tmp[MAXN];
ll *f = tmp+200000;
ll a[MAXN*4];

ll get(int k, int L, int R, int x, int y)
{
	if (L == x && R == y)
	{
		return a[k];
	}
	int m = (L+R)/2;
	if (y <= m)
		return get(k<<1, L, m, x, y);
	if (x > m)
		return get(k<<1|1, m+1, R, x, y);
	return min(get(k<<1, L, m, x, m), get(k<<1|1, m+1, R, m+1, y));
}

void add(int k, int L, int R, int x, ll d)
{
	if (L == R)
	{
		a[k] = d;
		return;
	}
	int m = (L+R)/2;
	if (x <= m)
		add(k<<1, L, m ,x, d);
	else
		add(k<<1|1, m+1, R, x, d);
	a[k] = min(a[k<<1], a[k<<1|1]);
}

void solve()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s+1);
	
	f[-k] = 0;
	for (int i = -k+1; i <= 0; ++ i)
	{
		f[i] = f[i-1]+i+k;
		add(1, -k +k, n +k, i +k, f[i]);
	}
	for (int i = 1; i <= n; ++ i)
	{
		int j = max(i-2*k-1, -k);
		ll t1 = (s[i] == '1') ? get(1, -k +k, n +k, j +k, i-1 +k)+i : INF;
		ll t2 = i+k <= n ? f[i-1]+i+k : INF;
		f[i] = min(t1, t2);
		add(1, -k +k, n +k, i +k, f[i]);
	}
	ll ans = INF;
	for (int i = -k; i <= n; ++ i)
		if (i+k >= n) freshmin(ans, f[i]);
	cout << ans << endl;
}

int main()
{
	
	int T;
	T = 1;
	//scanf("%d", &T);
	while (T --)
	solve();
	
	return 0;
}