#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

int n, k, a, b; ll ans;

int main() {
	read(n); read(k); read(a); read(b);
	while(n > 1) {
		if(n < k) { print(ans + (ll)(n - 1) * a, '\n'); return 0; }
		int up = n / k * k;
		ans += (ll)(n - up) * a; n = up;
		if((ll)(n - n / k) * a < b) { print(ans + (ll)(n - 1) * a, '\n'); return 0; }
		else ans += b, n /= k;
	}
	print(ans, '\n');
	return 0;
}

// Rotate Flower Round.