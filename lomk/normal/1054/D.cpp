/*input
3 1
1 1 1

6 3
1 4 4 7 3 4


3 2
1 3 0

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define int long long
#define N
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)(l); i<=(int)(r); i++)

void read(int &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    while (c == ' ' || c == '\n')
        c = getchar();
    if (c == '-') {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
    if (negative)
        number = -number;
}

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
    return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1 ? ", " : "");
    os << ']';
    return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &a) {
    os << '{';
    for (typename set<T>::iterator it = a.begin(); it != a.end(); it++) {
        typename set<T>::iterator jt = it;
        os << *it << (++jt != a.end() ? ", " : "");
    }
    os << '}';
    return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, map<T1, T2> &a) {
    os << "{\n";
    for (typename map<T1, T2>::iterator it = a.begin(); it != a.end(); it++) {
        typename map<T1, T2>::iterator jt = it;
        os << "  " << it->first << ": " << it->second << (++jt != a.end() ? ",\n" : "\n");
    }
    os << '}';
    return os;
}

map<int, int> cnt;

int n, m;
int flipAll(int x) {
    int ret = 0;
    loop(i, 0, m - 1) {
        ret |= ((bit(x, i) ^ 1) << i);
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef in1code
    freopen("1test.inp", "r", stdin);
#endif
    cin >> n >> m;
    cnt[0] = 1;
    int preSum = 0;
    int ans = 0;
    loop(i, 1, n) {
        int x; cin >> x;
        int cur = preSum ^ x;
        int cnt0 = cnt[cur], cnt1 = cnt[flipAll(cur)];
        if (cnt1 < cnt0) {
            cur = flipAll(cur);
        }
        cnt0 = cnt[cur], cnt1 = cnt[flipAll(cur)];
        ans += i - cnt0;
        cnt[cur]++;
        preSum = cur;
    }
    cout << ans << endl;
}