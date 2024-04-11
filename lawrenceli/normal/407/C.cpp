#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define dwn(i, n) for (int i=(n); --i>=0; )
#define repr(i, l, r) for (int i=(l), _##i=(r); i<_##i; ++i)
#define dwnr(i, l, r) for (int i=(r), _##i=(l); --i>=_##i; )
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define dwni(i, n) for (__typeof((n).rbegin()) i=(n).rbegin(), _##i=(n).rend(); i!=_##i; ++i)
#define repv(i, n) for (int i=0, _##i=((n).size()); i<_##i; ++i)
#define dwnv(i, n) for (int i=((n).size()); --i>=0; )
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;
typedef vector<int> vi;

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <class T> void setmin(T& a, T b) { if (b < a) a = b; }
template <class T> void setmax(T& a, T b) { if (b > a) a = b; }

const int MAXN = 100105;
const int MAXK = 105;
const int MOD = 1e9 + 7;

int n, m, ar[MAXN], add[MAXN];
int fact[MAXN], inv[MAXN], invfact[MAXN];
vector<pii> queries[MAXK];

int pow(int b, int e) {
    if (!e) return 1;
    int res = pow(b, e/2);
    if (e&1) return ll(res)*res%MOD*b%MOD;
    return ll(res)*res%MOD;
}

int C(int i, int j) {
    return ll(fact[i])*invfact[j]%MOD*invfact[i-j]%MOD;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) scanf("%d", &ar[i]);
    for (int i=0; i<m; i++) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        l--;
        queries[k].push_back(pii(l, r));
    }
    fact[0] = invfact[0] = 1;
    for (int i=1; i<MAXN; i++) fact[i] = ll(fact[i-1])*i%MOD;
    for (int i=1; i<MAXN; i++) inv[i] = pow(i, MOD-2);
    for (int i=1; i<MAXN; i++) invfact[i] = ll(invfact[i-1])*inv[i]%MOD;
    for (int k=MAXK-1; k>=0; k--) {
        for (int i=0; i<queries[k].size(); i++) {
            int l = queries[k][i].fi, r = queries[k][i].se;
            add[l] = (add[l]+1)%MOD;
        }
        for (int k1=MAXK-1; k1>=k; k1--)
            for (int i=0; i<queries[k1].size(); i++) {
                int l = queries[k1][i].fi, r = queries[k1][i].se;
                add[r] = (add[r]-C(r-l+k1-k-1, k1-k)+MOD)%MOD;
            }
        for (int i=1; i<n; i++)
            add[i] = (add[i-1]+add[i])%MOD;
    }
    for (int i=0; i<n; i++)
        printf("%d ", (ar[i]+add[i])%MOD);
    return 0;
}