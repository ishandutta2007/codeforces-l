#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
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

const int maxn = 210;
int n, p[maxn], fa[maxn], to[maxn], fr[maxn];
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
void work() {
	read(n);
	for (int i = 1; i <= n; ++i) read(p[i]), fa[i] = i, to[p[i]] = i, fr[i] = p[i];
	for (int i = 1; i <= n; ++i) fa[get(p[i])] = get(i);
	for (int i = 1; i < n; ++i) if (get(i) != get(i + 1)) {
		int x = to[i], y = to[i + 1];
		fr[x] = i + 1, fr[y] = i;
		to[i] = y, to[i + 1] = x;
		fa[get(i)] = get(i + 1);
	}
	int i = 1;
	do {
		write(i, ' ');
		i = to[i];
	} while (i != 1);
	write('\n');
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}