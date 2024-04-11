#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

int main() { _
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    int t, k;
    cin >> t >> k;
    rep(i, t) {
        int n, m;
        cin >> n >> m;
        if (n > m) swap(n, m);
        if (k > 1) {
            if (n%(k+1) == 0) cout << "+\n";
            else {
                if (n > m) swap(n, m);
                if (((n/(k+1))&1)^((m-n)&1)) cout << "+\n";
                else cout << "-\n";
            }
        } else {
            if (n%2 == 0) cout << "+\n";
            else if ((m-n)%2 == 0) cout << "-\n";
            else cout << "+\n";
        }
    }
    return 0;
}