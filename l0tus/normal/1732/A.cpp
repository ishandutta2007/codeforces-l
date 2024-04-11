#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cout << "[Debug] " << x << '\n'
#else
#define debug(x)
#endif

using str = string;
using ll = long long;
using db = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

#define mp make_pair
#define f first
#define s second
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
#define lb lower_bound
#define ub upper_bound

const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

const ll INF = 1e18;
const int MOD = (int)1e9 + 7; // 998244353;
const int MN = (int)2e5 + 5;

vi A(MN), X(MN);
vl S(MN);
vi table;
vi same_odd[MN], same_even[MN];

pair<ll, ll> egcd(ll a, ll b)
{
    if (b == 0)
        return {1, 0};
    auto t = egcd(b, a % b);
    return {t.second, t.first - t.second * (a / b)};
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    FAST_IO;
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vi A(N);
        int g = 0;
        F0R(i, N)
        {
            cin >> A[i];
            g = gcd(A[i], g);
        }
        int ans;
        if (g == 1)
            ans = 0;
        else
        {
            if (gcd(g, N) == 1)
            {
                ans = 1;
            }
            else if (gcd(g, N - 1) == 1)
            {
                ans = 2;
            }
            else
                ans = 3;
        }
        cout << ans << '\n';
    }
}