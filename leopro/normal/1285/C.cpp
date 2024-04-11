#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
#define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << '\n'; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename C>void incr_sort(C &v) { stable_sort(v.begin(), v.end()); }
    template<typename C>void decr_sort(C &v) { stable_sort(v.rbegin(), v.rend()); }
    template<typename C,typename Cmp>void incr_sort(C &v, Cmp comp) { stable_sort(v.begin(), v.end(), comp); }
    template<typename C,typename Cmp>void decr_sort(C &v, Cmp comp) { stable_sort(v.rbegin(), v.rend(), comp); }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
    void answer(ostream &os = cout){os << "\n"; throw ExitException();}
    istream &is = cin;
    struct autoint {int x; autoint() { is >> x; } operator int(){return x;}};
    template<typename T> struct autoread : T{template<typename... Args>autoread(Args&&... args): T(args...){ is >> *dynamic_cast<T *>(this);} };
}
//@formatter:on

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (ExitException) {}} while (--t);
    return 0;
}

int power(int b, int e) {
    if (e == 0) return 1;
    return b * power(b, e - 1);
}

void solve() {
    int x;cin >> x;
    map<int, int> divs;
    for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {divs[i]++; x /= i;}
    }
    if (x > 1) divs[x]++;
    int cnt = divs.size();
    vector<int> a;
    for (auto p : divs) {
        a.push_back(power(p.first, p.second));
    }
    pair<int, int> ans = {1e13,1e13};
    for (int mask = 0; mask < (2 << cnt); ++mask) {
        vector<bool> m(cnt);
        int copy = mask;
        for (int i = 0; i < cnt; ++i) {
            m[i] = copy & 1;
            copy >>= 1;
        }
        int x1 = 1, x2 = 1;
        for (int j = 0; j < cnt; ++j) {
            (m[j] ? x1 : x2) *= a[j];
        }
        if (max(ans.first,ans.second) > max(x1, x2)) ans = {x1, x2};
    }
    answer(ans);
}