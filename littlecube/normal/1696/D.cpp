/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n, a[250005], far[250005];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    deque<int> mx, mi;
    mx.emplace_front(n);
    mi.emplace_front(n);
    for (int i = n - 1; i >= 1; i--)
    {
        while (!mx.empty() && a[i] > a[mx.back()])
            mx.pop_back();
        while (!mi.empty() && a[i] < a[mi.back()])
            mi.pop_back();

        if (mi.empty())
            far[i] = mx.front();
        else if (mx.empty())
            far[i] = mi.front();
        else
        {
            auto iter1 = lower_bound(mx.begin(), mx.end(), mi.back(), greater<>());
            auto iter2 = lower_bound(mi.begin(), mi.end(), mx.back(), greater<>());
            far[i] = max((iter1 != mx.end() ? *iter1 : 0), (iter2 != mi.end() ? *iter2 : 0));
        }
        mx.emplace_back(i);
        mi.emplace_back(i);

    }
    int cur = 1, ans = 0;
    while (cur != n)
        cur = far[cur], ans++;
    cout << ans << '\n';
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}