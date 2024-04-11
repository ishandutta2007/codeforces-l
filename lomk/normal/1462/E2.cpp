/*input
1
4 3 2
1 2 4 3
4 2 1
1 1 1 1
1 1 1
1
10 4 3
5 6 1 3 2 9 8 1 2 4
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
const int N = 2e5 + 5;

const int mod = 1e9 + 7;
struct Comb {
    int n;
    vector<int> fact, inv;
    Comb() = default;
    Comb(int n): n(n), fact(n + 5, 0), inv(n + 5, 0) {
        fact[0] = fact[1] = inv[0] = inv[1] = 1;
        loop(i, 2, n) {
            fact[i] = 1LL * fact[i - 1] * i % mod;
            inv[i] = (mod - 1LL * (mod / i) * inv[mod % i] % mod) % mod;
        }
        loop(i, 2, n) inv[i] = 1LL * inv[i] * inv[i - 1] % mod;
    }
    int operator()(int x, int y) { // x<=y; x>=0
        if (x > y) return 0;
        return 1LL * fact[y] * inv[x] % mod * inv[y - x] % mod;
    }
} C(N);

const int INF = numeric_limits<int>::max() / 2;
class Solver {
public:
    int n, m, lim;
    vector<int> a;
    Solver() {
    }
    void operator()() {
        cin >> n >> m >> lim;
        loop(i, 1, n) {
            int t; cin >> t; a.push_back(t);
        }
        sort(a.begin(), a.end());
        int L = 0; int ans = 0;
        loop(i, 0, n - 1) {
            while (a[i] - a[L] > lim) L++;
            ans = (ans + C(m - 1, i - L)) % mod;
        }
        cout << ans << endl;
    }
};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        Solver solve;
        solve();
    }
}