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
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << '\n'; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename C>void incr_sort(C &v) { stable_sort(v.begin(), v.end()); }
    template<typename C>void decr_sort(C &v) { stable_sort(v.rbegin(), v.rend()); }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}}
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    cin >> x;
    set<int> trees;
    for (int pos : x) trees.insert(pos);
    set<int> people;
    vector<int> ans;
    for (int pos : x) {
        if (trees.find(pos - 1) == trees.end() && people.find(pos - 1) == people.end()) {
            ans.push_back(pos - 1);
            people.insert(pos - 1);
        }
        if (trees.find(pos + 1) == trees.end() && people.find(pos + 1) == people.end()) {
            ans.push_back(pos + 1);
            people.insert(pos + 1);
        }
    }
    int res = ans.size();
    if (res >= m) {
        cout << m << "\n";
        for (int i = 0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        return;
    }
    queue<int> b;
    int a = 1;
    b.push(0);
    for (int i = 0; i < ans.size() && ans.size() < m; ++i) {
        int pos = ans[i];
        if (i == b.front()) {
            b.pop();
            ++a;
            b.push(ans.size());
        }
        if (trees.find(pos - 1) == trees.end() && people.find(pos - 1) == people.end()) {
            ans.push_back(pos - 1);
            people.insert(pos - 1);
            res += a;
        }
        if (ans.size() == m) break;
        if (trees.find(pos + 1) == trees.end() && people.find(pos + 1) == people.end()) {
            ans.push_back(pos + 1);
            people.insert(pos + 1);
            res += a;
        }
    }
    cout << res << "\n";
    cout << ans;
}