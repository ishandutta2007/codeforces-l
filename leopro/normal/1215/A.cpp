#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
//@formatter:off
namespace {
    using namespace std;
    typedef long long ll;
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>bool space(vector<T>) { return false; }
    template<typename T>bool space(T) { return true; }
    bool space(char) { return false; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) { os << t << (space(t) ? " " : ""); } os << "\n"; return os; }
    ll gcd(ll a, ll b) { while (b) { ll mod = a % b; a = b; b = mod; } return a; }
    template<typename T>void incr_sort(vector<T> &v) { stable_sort(v.begin(), v.end()); }
    template<typename T>void decr_sort(vector<T> &v) { stable_sort(v.rbegin(), v.rend()); }
    ll sum(const vector<int> &v) { ll s = 0; for (ll value : v) s += value; return s; }
}
//@formatter:on

void solve();

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 0; i < t; ++i) solve();
    return 0;
}

void solve() {
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int min = a1 * (k1 - 1) + a2 * (k2 - 1);
    cout << (min > n ? 0 : n - min) << " ";
    int count = 0;
    if (k1 < k2) {
        if (n < k1 * a1) {
            cout << n / k1 << "\n";
            return;
        }
        count += a1;
        n -= k1 * a1;
    } else {
        if (n < k2 * a2) {
            cout << n / k2 << "\n";
            return;
        }
        count += a2;
        n -= k2 * a2;
    }
    if (k1 >= k2) {
        if (n < k1 * a1) {
            cout << n / k1 + count << "\n";
            return;
        } else {
            cout << a1 + a2 << "\n";
        }
    } else {
        if (n < k2 * a2) {
            cout << n / k2 + count << "\n";
            return;
        } else {
            cout << a2 + a1 << "\n";
        }
    }

}