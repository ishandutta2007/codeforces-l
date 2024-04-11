#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
#define int long long

    template<typename T>
    inline bool whitespace(const vector<T> &) { return false; }

    template<typename T>
    inline bool whitespace(const T &) { return true; }

    inline bool whitespace(const char) { return false; }

    template<typename S, typename T>
    ostream &operator<<(ostream &os, const pair<S, T> &p) {
        os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n";
        return os;
    }

    template<typename S, typename T>
    istream &operator>>(istream &is, pair<S, T> &p) {
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
        for (const T &t : v) {
            os << t << (whitespace(t) ? "\n" : "");
        }
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
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
        os << "\n";
        return os;
    }

    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            T mod = a % b;
            a = b;
            b = mod;
        }
        return a;
    }

    template<typename T>
    T sum(const vector<T> &v) {
        T s = 0;
        for (T value : v) s += value;
        return s;
    }

    template<typename T>
    vector<T> prefix_sum(const vector<T> &v) {
        vector<T> res(v.size() + 1);
        res[0] = 0;
        for (int i = 0; i < v.size(); ++i) res[i + 1] = res[i] + v[i];
        return res;
    }

    class exit_exception : exception {
    };

    istream &in = cin;
    ostream &out = cout;

    template<typename T>
    void answer(T ans) {
        out << ans << "\n";
        throw exit_exception();
    }

    struct autoint {
        int x;

        autoint() { in >> x; }

        operator int() { return x; }

        autoint(autoint &i) { x = i.x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };

    template<typename T>
    struct autoread : T {
        template<typename... Args>
        autoread(Args &&... args): T(args...) { in >> *dynamic_cast<T *>(this); }
    };
}
//@formatter:on

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

typedef pair<int, int> point;
#define x first
#define y second

bool convex(vector<point> &c_h, int i, int j, int k) {
    if (c_h.size() <= 2) return true;
    point p1 = c_h[i];
    point p2 = c_h[j];
    point p3 = c_h[k];
    return (p3.y - p2.y) * (p2.x - p1.x) >= (p2.y - p1.y) * (p3.x - p2.x);
}

void solve() {
    cout << setprecision(10);
    autoint n;
    autoread<vector<int>> a(n);
    vector<int> p_s = prefix_sum(a);
    vector<point> hull(n + 1);
    for (int i = 0; i <= n; ++i) hull[i] = {i, p_s[i]};

    vector<int> hor(n + 1);
    hor.back() = n;
    for (int i = n - 1; i >= 0; --i) {
        hor[i] = i + 1;
        while (!convex(hull, i, hor[i], hor[hor[i]])) hor[i] = hor[hor[i]];
    }
    vector<double> ans(n);
    for (int i = 0; i < n;) {
        if (i == n - 1) {
            ans[i] = a[i];
            break;
        }
        double val = double(p_s[hor[i]] - p_s[i]) / (hor[i] - i);
        for (int right = hor[i]; i < right; ++i) ans[i] = val;
    }
    cout << ans;
}