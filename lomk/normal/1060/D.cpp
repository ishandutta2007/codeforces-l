/*input
1
5 6


*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
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

int n;
vector<int> ml, mr;
vector<int> allL, allR;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef in1code
    freopen("1test.inp", "r", stdin);
#endif
    cin >> n;
    int ans = n;
    loop(i, 1, n) {
        pair<int, int> x; cin >> x.fi >> x.se;
        if (x.fi == x.se) {
            ans += x.fi;
            continue;
        }
        ml.push_back(x.fi); mr.push_back(x.se);
        allL.push_back(x.fi); allR.push_back(x.se);
    }
    sort(allL.begin(), allL.end()); reverse(allL.begin(), allL.end()); sort(allR.begin(), allR.end()); reverse(allR.begin(), allR.end());
    sort(ml.begin(), ml.end()); sort(mr.begin(), mr.end());
    for (auto it : allL) {
        ans += max(mr.back(), it);
        mr.pop_back();
    }
    cout << ans << endl;
}