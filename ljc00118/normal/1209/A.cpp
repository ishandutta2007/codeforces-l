#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 105;

int vis[N], a[N];
int n, ans;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]);
    sort(a + 1, a + n + 1);
    for(register int i = 1; i <= n; i++) {
        if(!vis[i]) {
            ++ans;
            for(register int j = i; j <= n; j++) {
                if(a[j] % a[i] == 0) {
                    vis[j] = 1;
                }
            }
        }
    }
    print(ans, '\n');
    return 0;
}