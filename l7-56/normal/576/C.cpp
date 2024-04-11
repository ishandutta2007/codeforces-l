#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second
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

const int maxn = 1e6 + 10, T = 1e3;
int n;
#define bel(x) ((x) / T)
struct node {
	int l, r, i;
	friend bool operator < (node a, node b) {
		if (bel(a.l) != bel(b.l)) return bel(a.l) < bel(b.l);
		return bel(a.l) & 1 ? a.r < b.r : a.r > b.r;
	}
} a[maxn];

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i].l, a[i].r), a[i].i = i;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) printf("%d%c", a[i].i, " \n"[i == n]);
	return 0;
}