#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>

using namespace std;

typedef long long ll;

namespace {
    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    bool space(vector<T>) { return false; }

    template<typename T>
    bool space(T) { return true; }

    bool space(char) { return false; }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) { os << t << (space(t) ? " " : ""); }
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
    void incr_sort(vector<T> &v) { stable_sort(v.begin(), v.end()); }

    template<typename T>
    void decr_sort(vector<T> &v) { stable_sort(v.rbegin(), v.rend()); }

    ll sum(vector<int> v) {
        int s = 0;
        for (int value : v) s += value;
        return s;
    }
}

void solve();

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    /*int t;
    cin >> t;
    for (int i = 0; i < t; ++i) */solve();
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int odds, evens = 0;
    for (int i = 0; i < n; ++i) {
        evens += (a[i] % 2 == 0);
    }
    odds = n - evens;
    cout << min(odds, evens);
}