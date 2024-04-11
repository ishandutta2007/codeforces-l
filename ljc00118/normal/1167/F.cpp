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

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv, last_id;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    void clear() {
        for(register int i = 1; i <= tot; i++) head[v[i] % mod] = 0;
        tot = 0;
        v.clear(); val.clear(); nxt.clear();
        v.resize(1); val.resize(1); nxt.resize(1);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                last_id = i;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        // fprintf(stderr, "debug %d %d\n", x, y);
        if(count(x)) {
            val[last_id] = y;
            lastans = y;
            return;
        }
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 5e5 + 5, md = 1e9 + 7;

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

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

struct segment_tree {
    struct node_t { int l, r, val, tag; } p[N << 2];

    void update(int u) { p[u].val = add(p[u << 1].val, p[u << 1 | 1].val); }

    void add_tag(int u, int x) {
        p[u].val = add(p[u].val, mul(p[u].r - p[u].l + 1, x));
        p[u].tag = add(p[u].tag, x);
    }

    void pushdown(int u) {
        if(p[u].tag) {
            add_tag(u << 1, p[u].tag);
            add_tag(u << 1 | 1, p[u].tag);
            p[u].tag = 0;
        }
    }

    void build(int u, int l, int r) {
        p[u].l = l; p[u].r = r;
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    }

    void change(int u, int l, int r, int x) {
        if(l <= p[u].l && p[u].r <= r) {
            add_tag(u, x);
            return;
        }
        pushdown(u);
        int mid = (p[u].l + p[u].r) >> 1;
        if(mid >= l) change(u << 1, l, r, x);
        if(mid + 1 <= r) change(u << 1 | 1, l, r, x);
        update(u);
    }

    int query(int u, int l, int r) {
        if(l <= p[u].l && p[u].r <= r) return p[u].val;
        pushdown(u);
        int mid = (p[u].l + p[u].r) >> 1, ans = 0;
        if(mid >= l) ans = query(u << 1, l, r);
        if(mid + 1 <= r) ans = add(ans, query(u << 1 | 1, l, r));
        return ans;
    }
} tr1, tr2;

pii a[N];
int f[N];
int n, ans;

inline int lowbit(int x) { return x & -x; }

inline void add(int x) {
    for(register int i = x; i <= n; i += lowbit(i))
        ++f[i];
}

inline int query(int x) {
    int ans = 0;
    for(register int i = x; i; i -= lowbit(i))
        ans += f[i];
    return ans;
}

int main() {
    read(n);
    tr1.build(1, 1, n); tr2.build(1, 1, n);
    for(register int i = 1; i <= n; i++) {
        int t; read(t);
        a[i] = make_pair(t, i);
    }
    sort(a + 1, a + n + 1);
    for(register int i = 1; i <= n; i++) {
        int l = tr1.query(1, 1, a[i].second);
        int r = tr2.query(1, a[i].second, n);
        int cnt1 = query(a[i].second);
        int cnt2 = i - 1 - cnt1;
        l = sub(l, mul(cnt2, a[i].second));
        r = sub(r, mul(cnt1, n - a[i].second + 1));
        ans = add(ans, mul(a[i].first, add(mul(l, n - a[i].second + 1), mul(r, a[i].second))));
        ans = add(ans, mul(a[i].first, mul(a[i].second, n - a[i].second + 1)));
        tr1.change(1, 1, a[i].second, 1); tr2.change(1, a[i].second, n, 1); add(a[i].second);
        // fprintf(stderr, "l = %d, r = %d, ans = %d\n", l, r, ans);
    }
    print(ans, '\n');
    return 0;
}