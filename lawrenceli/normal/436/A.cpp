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

const int MAXN = 2005;

int n, x;
pii ar[2][MAXN];
int sze[2];

int go(bool cur) {
    int ret = 0, cnt[2] = {0, 0}, y = x;
    multiset<int> st[2];
    while (1) {
        while (cnt[cur] < sze[cur] && ar[cur][cnt[cur]].fi <= y)
            st[cur].insert(ar[cur][cnt[cur]++].se);
        if (st[cur].empty()) return ret;
        y += *st[cur].rbegin();
        typeof(st[cur].begin()) it = st[cur].end(); it--;
        st[cur].erase(it);
        ret++;
        cur ^= 1;
    }
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> x;
    for (int i=0; i<n; i++) {
        int t, h, m;
        cin >> t >> h >> m;
        ar[t][sze[t]++] = pii(h, m);
    }
    sort(ar[0], ar[0]+sze[0]);
    sort(ar[1], ar[1]+sze[1]);

    cout << max(go(0), go(1)) << '\n';
    return 0;
}