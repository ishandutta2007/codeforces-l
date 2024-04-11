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

const int md = 998244353;

inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if(x < 0) x += md;
    return x;
}

inline int mul(int x, int y) {
    return 1ll * x * y % md;
}

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

namespace ntt {
    int base = 1, root = -1, maxbase = -1;
    vector <int> roots = {0, 1}, rev = {0, 1};

    void init() {
        int tmp = md - 1; maxbase = 0;
        while(!(tmp & 1)) {
            tmp >>= 1;
            maxbase++;
        }
        root = 2;
        while(1) {
            if(fpow(root, 1 << maxbase) == 1 && fpow(root, 1 << (maxbase - 1)) != 1) break;
            root++;
        }
    }

    void ensure_base(int nbase) {
        if(maxbase == -1) init();
        if(nbase <= base) return;
        assert(nbase <= maxbase);
        rev.resize(1 << nbase);
        for(register int i = 1; i < (1 << nbase); i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (nbase - 1));
        roots.resize(1 << nbase);
        while(base < nbase) {
            int z = fpow(root, 1 << (maxbase - base - 1));
            for(register int i = (1 << (base - 1)); i < (1 << base); i++) {
                roots[i << 1] = roots[i];
                roots[i << 1 | 1] = mul(roots[i], z);
            }
            base++;
        } 
    }

    void dft(vector <int> &a) {
        int n = a.size(), zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;
        for(register int i = 0; i < n; i++) if(i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);
        for(register int mid = 1; mid < n; mid <<= 1) {
            for(register int i = 0; i < n; i += (mid << 1)) {
                for(register int j = 0; j < mid; j++) {
                    int x = a[i + j], y = mul(a[i + j + mid], roots[mid + j]);
                    a[i + j] = add(x, y); a[i + j + mid] = sub(x, y);
                }
            }
        }
    }

    vector <int> pmul(vector <int> a, vector <int> b, bool is_sqr = false) {
        int need = a.size() + b.size() - 1, nbase = 0;
        while((1 << nbase) < need) nbase++;
        ensure_base(nbase); int size = 1 << nbase;
        a.resize(size); dft(a); if(!is_sqr) b.resize(size), dft(b); else b = a;
        int inv = fpow(size, md - 2);
        for(register int i = 0; i < size; i++) a[i] = mul(a[i], mul(b[i], inv));
        reverse(a.begin() + 1, a.end()); dft(a); a.resize(need); return a;
    }

    vector <int> psqr(vector <int> a) { return pmul(a, a, 1); }

    vector <int> inv(vector <int> a, int size) {
        if(size == 1) return vector <int> { fpow(a[0], md - 2) };
        vector <int> b = inv(a, size >> 1); a = pmul(a, psqr(b)); b.resize(size);
        for(register int i = 0; i < size; i++) b[i] = sub(add(b[i], b[i]), a[i]);
        return b;
    }

    vector <int> pinv(vector <int> a) {
        int nbase = 0; while((1 << nbase) < (int)a.size()) nbase++;
        return inv(a, 1 << nbase);
    }
}

using ntt::pmul;

const int N = 2e5 + 5;

vector <int> a, fac, inv;
int n, k, ans, cnt;

inline int C(int n, int m) {
    return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
    read(n); read(k); a.resize(n + 1); fac = inv = a; k %= md;
    fac[0] = 1;
    for(register int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
    inv[n] = fpow(fac[n], md - 2);
    for(register int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    for(register int i = 1; i <= n; i++) read(a[i]);
    for(register int i = 1; i <= n; i++) {
        int go = i % n + 1;
        if(a[i] != a[go]) {
            ++cnt;
        }
    }
    ans = fpow(k, cnt);
    for(register int i = 0; i * 2 <= cnt; i++) ans = sub(ans, mul(mul(C(cnt, i), C(cnt - i, i)), fpow(sub(k, 2), cnt - i * 2)));
    ans = mul(ans, fpow(2, md - 2));
    print(mul(ans, fpow(k, n - cnt)), '\n');
    return 0;
}