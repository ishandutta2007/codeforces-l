/*
PROG: cf966a
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

using namespace std;

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
long long randomize(long long mod)
{
	return ((1ll << 30) * rand() + (1ll << 15) * rand() + rand()) % mod;
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-20;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 200013

long long normalize(long long x, long long mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, M, A, B, V;
ll a[MAXN], b[MAXN];
int Q;

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf966a.in", "r"))
	{	
		freopen ("cf966a.in", "r", stdin);
		freopen ("cf966a.out", "w", stdout);
	}
	cin >> N >> M >> A >> B >> V;
	for (int i = 0; i < A; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < B; i++)
	{
		cin >> b[i];
	}
	sort(a, a + A);
	sort(b, b + B);
	cin >> Q;
	while(Q--)
	{
		ll X1, X2, Y1, Y2;
		cin >> X1 >> Y1 >> X2 >> Y2;
		//either use elevator, use stairs
		if (X1 == X2)
		{
			cout << abs(Y2 - Y1) << '\n';
			continue;
		}
		ll ans = LLINF;
		vector<ll> els, sts;
		ll pos;
		pos = lower_bound(a, a + A, Y1) - a;
		if (0 <= pos && pos < A)
		{
			sts.PB(a[pos]);
		}
		pos = upper_bound(a, a + A, Y1) - a - 1;
		if (0 <= pos && pos < A)
		{
			sts.PB(a[pos]);
		}
		pos = lower_bound(a, a + A, Y2) - a;
		if (0 <= pos && pos < A)
		{
			sts.PB(a[pos]);
		}
		pos = upper_bound(a, a + A, Y2) - a - 1;
		if (0 <= pos && pos < A)
		{
			sts.PB(a[pos]);
		}
		pos = lower_bound(b, b + B, Y1) - b;
		if (0 <= pos && pos < B)
		{
			els.PB(b[pos]);
		}
		pos = upper_bound(b, b + B, Y1) - b - 1;
		if (0 <= pos && pos < B)
		{
			els.PB(b[pos]);
		}
		pos = lower_bound(b, b + B, Y2) - b;
		if (0 <= pos && pos < B)
		{
			els.PB(b[pos]);
		}
		pos = upper_bound(b, b + B, Y2) - b - 1;
		if (0 <= pos && pos < B)
		{
			els.PB(b[pos]);
		}
		for (int x : els)
		{
			ckmin(ans, abs(Y2 - x) + abs(Y1 - x) + (abs(X1 - X2) + V - 1)/V);
		}
		for (int x : sts)
		{
			ckmin(ans, abs(Y2 - x) + abs(Y1 - x) + abs(X1 - X2));
		}
		cout << ans << '\n';
	}
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}