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
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int n; cin >> n;
    if (n%2 == 0) {
        cout << 4 << ' ' << n-4 << '\n';
    } else {
        cout << 9 << ' ' << n-9 << '\n';
    }
}