#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
#define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n"; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()+1); res[0] = 0; for (int i = 0; i < v.size(); ++i) res[i+1] = res[i] + v[i]; return res; }
    template<typename S, typename T>S min(S a, T b){return a < (S)b ? a : b; }
    template<typename S, typename T>S max(S a, T b){return a < (S)b ? b : a; }
    class exit_exception : exception {};
    istream &in = cin; ostream &out = cout;
    template<typename T>void answer(T ans){out << ans << "\n"; throw exit_exception();}
    struct autoint{int x; autoint(){in >> x;} operator int(){return x;} autoint(autoint &i){x = i.x;}
        int operator--(){return --x;} int operator--(signed){return x--;} int operator ++(){return ++x;} int operator++(signed){return x++;} };
    template<typename T> struct autoread : T{template<typename... Args>autoread(Args&&... args): T(args...){ in >> *dynamic_cast<T *>(this);} };
}
//@formatter:on

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

void solve() {
    autoint n, k;
    string s;
    cin >> s;
    vector<map<char, int>> groups((k + 1) / 2);
    for (int i = 0; i < (k + 1) / 2; ++i) {
        for (int j = i; j < n; j += k) groups[i][s[j]]++;
        if (i + i < k - 1) for (int j = k - i - 1; j < n; j += k) groups[i][s[j]]++;
    }
    int ans = 0;
    for (auto m : groups) {
        vector<int> cnts;
        for (auto p : m) cnts.push_back(p.second);
        stable_sort(cnts.rbegin(), cnts.rend());
        ans += accumulate(cnts.begin(), cnts.end(), 0ll) - cnts.front();
    }
    answer(ans);

}