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
#define int long long
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
//using namespace __gnu_pbds;

#define LOCAL

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> val)
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

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m = 0, M = 0, l = 0;
        cin >> n;
        vector<pair<pii, int>> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].F.F >> v[i].F.S >> v[i].S;
        for (int i = 0; i < n; i++)
        {
            if (make_pair(v[i].F.F, v[i].S) < make_pair(v[m].F.F, v[m].S))
                m = i;
            if (make_pair(-v[i].F.S, v[i].S) < make_pair(-v[M].F.S, v[M].S))
                M = i;
            if (make_pair(-v[i].F.S + v[i].F.F, v[i].S) < make_pair(-v[l].F.S + v[l].F.F, v[l].S))
                l = i;
            if (v[M].F.S - v[m].F.F < v[l].F.S - v[l].F.F)
                cout << v[l].S << '\n';
            if (v[M].F.S - v[m].F.F == v[l].F.S - v[l].F.F)
                cout << min(v[l].S, v[M].S + v[m].S) << '\n';
            if (v[M].F.S - v[m].F.F > v[l].F.S - v[l].F.F)
                cout << v[M].S + v[m].S << '\n';
        }
    }
}