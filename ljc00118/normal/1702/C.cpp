#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
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

const int N = 2e5 + 5;

map <int, int> fir, las;
int a[N];
int T, n, m;

int main() {
    read(T);
    while (T--) {
        fir.clear(); las.clear();
        read(n); read(m);
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            if (!fir.count(a[i])) fir[a[i]] = i;
            las[a[i]] = i;
        }
        while (m--) {
            int a, b;
            read(a); read(b);
            if (fir.count(a) && las.count(b) && fir[a] <= las[b]) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}