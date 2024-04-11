#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
#else
#endif

#include <bits/stdc++.h>

namespace {
    using namespace std;
//#define int long long
    using ll = long long;
    using ull = unsigned long long;

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (is_integral_v<S> && !is_same_v<S, char> ? " " : "") << p.second;
        return os;
    }

    template<typename F, typename S>
    istream &operator>>(istream &is, pair<F, S> &p) {
        is >> p.first >> p.second;
        return is;
    }

    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) os << t << (is_integral_v<T> && !is_same_v<T, char> ? " " : "");
        os << "\n";
        return os;
    }

    template<typename T>
    istream &operator>>(istream &is, deque<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const deque<T> &v) {
        for (const T &t : v) os << t << (is_integral_v<T> && !is_same_v<T, char> ? " " : "");
        os << "\n";
        return os;
    }

    class exit_exception : exception {
    };

    void answer() {}

    template<typename First, typename... Args>
    void answer(First &&val, Args &&... ans) {
        cout << val << "\n";
        answer(ans...);
        throw exit_exception();
    }

    struct autoint {
        int x;

        explicit autoint(int i) : x(i) {}

        autoint() { cin >> x; }

        operator int() const { return x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };
}

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;

}

struct mod_int {
    static const int MOD = 1e9 + 7;
    int value;

    mod_int(int i = 0) : value(i) {}
    mod_int operator+(mod_int m) const {
        mod_int lhs = *this;
        lhs += m;
        return lhs;
    }

    mod_int operator+=(mod_int m) {
        value += m.value;
        if (value >= MOD) value -= MOD;
        return value;
    }

    mod_int operator-(mod_int m) const {
        mod_int lhs = *this;
        lhs -= m;
        return lhs;
    }

    mod_int operator-=(mod_int m) {
        value -= (m.value - MOD);
        if (value >= MOD) value -= MOD;
        return value;
    }

    mod_int operator*(mod_int m) const { return (value * 1LL * m.value) % MOD; }

    mod_int operator*=(mod_int m) {
        value = (value * 1LL * m.value) % MOD;
        return value;
    }

    mod_int power(int exp) {
        if (exp == 0) return 1;
        mod_int res = (exp & 1 ? value : 1);
        mod_int half = power(exp >> 1);
        return res * half * half;
    }

    mod_int operator/(mod_int m) const { return *this * m.power(MOD - 2); }

    mod_int operator/=(mod_int m) { return *this *= m.power(MOD - 2); }

    friend std::istream &operator>>(std::istream &is, mod_int &m) {
        is >> m.value;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const mod_int &m) {
        os << m.value;
        return os;
    }

    explicit operator int() const { return value; }
};

void solve() {
    autoint n;
    vector<vector<int>> tree(n);
    vector<vector<int>> dist(n, vector<int>(n, n));
    for (int i = 0; i < n - 1; ++i) {
        autoint u, v;
        --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        dist[u][v] = dist[v][u] = 1;
    }
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    vector<vector<mod_int>> dp(n, vector<mod_int>(n, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            mod_int x = dp[i][j - 1] / mod_int(2);
            mod_int y = dp[i - 1][j] / mod_int(2);
            dp[i][j] = x + y;
        }
    }
    mod_int ans = 0;
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < u; ++v) {
            vector<bool> shortestPath(n);
            for (int i = 0; i < n; ++i) {
                shortestPath[i] = (dist[u][i] + dist[i][v]) == dist[u][v];
            }
            vector<int> prev(n, -1);
            for (int i = 0; i < n; ++i) if (shortestPath[i]) prev[i] = i;
            vector<int> dfs;
            for (int i = 0; i < n; ++i) if (shortestPath[i]) dfs.push_back(i);
            while (!dfs.empty()) {
                int x = dfs.back();
                dfs.pop_back();
                for (int y : tree[x]) {
                    if (prev[y] == -1) {
                        prev[y] = prev[x];
                        dfs.push_back(y);
                    }
                }
            }
            vector<int> sz(n);
            for (int i = 0; i < n; ++i) sz[prev[i]]++;
            mod_int p = 0;
            for (int i = 0; i < n; ++i) {
                if (!shortestPath[i]) continue;
                p += mod_int(sz[i]) * dp[dist[i][v]][dist[i][u]];
            }
            ans += p / mod_int(n);
        }
    }
    cout << ans << '\n';
}