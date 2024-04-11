/*
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

struct chash
{
	int operator()(int x) const
	{
		x ^= (x >> 20) ^ (x >> 12);
		return x ^ (x >> 7) ^ (x >> 4);
	}
	int operator()(long long x) const
	{
		return x ^ (x >> 32);
	}
};

template<typename T> using orderedset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename U> using hashtable = gp_hash_table<T, U, chash>;

template<class T>
void readi(T &x)
{
	T input = 0;
	bool negative = false;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = input * 10 + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	x = input;
}
template<class T>
void printi(T output)
{
	if (output == 0)
	{
		putchar('0');
		return;
	}
	if (output < 0)
	{
		putchar('-');
		output = -output;
	}
	int aout[20];
	int ilen = 0;
	while(output)
	{
		aout[ilen] = ((output % 10));
		output /= 10;
		ilen++;
	}
	for (int i = ilen - 1; i >= 0; i--)
	{
		putchar(aout[i] + '0');
	}
	return;
}
template<class T>
void ckmin(T &a, T b)
{
	a = min(a, b);
}
template<class T>
void ckmax(T &a, T b)
{
	a = max(a, b);
}
template<class T, class U>
T normalize(T x, U mod = 1000000007)
{
	return (((x % mod) + mod) % mod);
}
long long randomizell(long long mod)
{
	return ((1ll << 45) * rand() + (1ll << 30) * rand() + (1ll << 15) * rand() + rand()) % mod;
}
int randomize(int mod)
{
	return ((1ll << 15) * rand() + rand()) % mod;
}

#define y0 ___y0
#define y1 ___y1
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define debug(x) cerr << #x << " = " << x << endl;

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-10;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 713

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

int N;
int arr[MAXN];
bool edge[MAXN][MAXN];
bitset<MAXN> dp[2][MAXN], vis[2][MAXN];

bool solve(int L, int R, bool flag)
{
	if (L > R) return true;
	if (vis[flag][L][R]) return dp[flag][L][R];
	vis[flag][L][R] = true;
	int need = (flag ? R + 1 : L - 1);
	for (int i = L; i <= R; i++)
	{
		if (!edge[i][need])
		{
			continue;
		}
		if (solve(L, i - 1, 1) && solve(i + 1, R, 0))
		{
			dp[flag][L][R] = true;
			return true;
		}
	}
	// cerr << L << ' ' << R << ' ' << need << ' ' << dp[flag][L][R] << endl;
	return false;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	srand(time(0));
	// cout << fixed << setprecision(10);
	// cerr << fixed << setprecision(10);
	// if (fopen("input.in", "r"))
	// {
	// 	freopen ("input.in", "r", stdin);
	// 	freopen ("output.out", "w", stdout);
	// }
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (__gcd(arr[i], arr[j]) != 1)
			{
				edge[i][j] = true;
			}
		}
		edge[i][0] = true;
		edge[0][i] = true;
		edge[i][N + 1] = true;
		edge[N + 1][i] = true;
	}
	cout << (solve(1, N, 0) ? "Yes" : "No") << '\n';
	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}