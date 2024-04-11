#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int n;
string s;

int main() {
    cin >> n;
    int ans = 0;
    while (cin >> s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i)
            if (isupper(s[i]))
                ++cnt;
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}