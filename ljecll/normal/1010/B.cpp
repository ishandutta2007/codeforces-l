/*
PROG: source
LANG: C++11
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
template<typename T> using hashtable = gp_hash_table<T, T, chash>;

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
template<class T>
T normalize(T x, T mod = 1000000007)
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
#define MAXN 1013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

int M, N;
bool istrue[MAXN];

int guess(int x)
{
    cout << x << '\n';
    fflush(stdout);
    int res; cin >> res;
    if (res == 0 || res == -2)
    {
        exit(0);
    }
    return res;
}


int32_t main()
{
	ios_base::sync_with_stdio(0);
	srand(time(0));
	//	cout << fixed << setprecision(10);
	//	cerr << fixed << setprecision(10);
	if (fopen("input.in", "r"))
	{
		freopen ("input.in", "r", stdin);
		freopen ("output.out", "w", stdout);
	}
    cin >> M >> N;
    // int x = 1000000000;
    // for (int i = 0; i < 30; i++)
    // {
    //     cout << i << ' ' << x << endl;
    //     x = (x) / 2;
    // }
    // return 0;
    for (int i = 0; i < N; i++)
    {
        int lol = guess(1);
        // the correct answer is 1!
        if (lol == 1)
        {
            istrue[i] = true;
        }
        else
        {
            istrue[i] = false;
        }
    }
    int lo = 1, hi = M;
    for (int i = 0; ; i++)
    {
        int mid = (lo + hi) / 2;
        int r = guess(mid);
        if (!istrue[i % N])
        {
            r = -r;
        }
        if (r == 1)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    //the nice thing is: you know x or n+x is correct
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}