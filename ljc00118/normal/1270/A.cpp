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

const int N = 105;

int T, n, a, b, ans;

int main() {
    read(T);
    while (T--) {
        read(n); read(a); read(b); ans = 0;
        for (int i = 1; i <= a; i++) {
            int x; read(x);
            if (x == n) ans = 1;
        }
        for (int i = 1; i <= b; i++) {
            int x; read(x);
            if (x == n) ans = 2;
        }
        if (ans == 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}