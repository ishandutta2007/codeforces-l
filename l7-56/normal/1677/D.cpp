#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }
template <int mod>
class mint {
	public:
		int x;
		mint() : x(0) {}
		mint(int _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mint(long long _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mint(unsigned int _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		mint(unsigned long long _x) { (x = _x % mod) < 0 ? x += mod : 0; }
		friend mint operator + (mint a, mint b) { return (a.x += b.x) >= mod ? a.x -= mod : 0, a; }
		friend mint operator - (mint a, mint b) { return (a.x -= b.x) < 0 ? a.x += mod : 0, a; }
		friend mint operator * (mint a, mint b) { return a.x = 1ll * a.x * b.x % mod, a; }
		template <typename __Tp> friend mint operator ^ (mint a, __Tp p) {
			mint ans = 1;
			while (p) {
				if (p & 1) ans = ans * a;
				a = a * a, p >>= 1;
			}
			return ans;
		}
		friend mint operator / (mint a, mint b) { return a * (b ^ (mod - 2)); }
		friend mint & operator += (mint &a, mint b) { return a = a + b; }
		friend mint & operator -= (mint &a, mint b) { return a = a - b; }
		friend mint & operator *= (mint &a, mint b) { return a = a * b; }
		friend mint & operator /= (mint &a, mint b) { return a = a / b; }
		friend mint & operator ^= (mint &a, int b) { return a = a ^ b; }

		mint & operator ++ () { return *this += 1; }
		const mint operator ++ (int) { mint t = *this; *this += 1; return t; }
		mint & operator -- () { return *this -= 1; }
		const mint operator -- (int) { mint t = *this; *this -= 1; return t; }

		friend bool operator == (mint a, mint b) { return a.x == b.x; }
		friend bool operator != (mint a, mint b) { return a.x != b.x; }
};

const int maxn = 1e6 + 10, mod = 998244353;
typedef mint <mod> mi;
int n, k, v[maxn];
void work() {
	read(n, k);
	for (int i = 1; i <= n; ++i) read(v[i]);
	mi ans = 1;
	for (int i = 1; i <= k; ++i)
		ans *= i * (v[n - i + 1] <= 0);
	for (int i = 1; i <= n - k; ++i) {
		if (v[i] == 0) ans *= k + 1;
		else if (v[i] == -1) ans *= k + i;
	}
	write(ans.x, '\n');
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}