#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

ll a;
int arr[] = {0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401, 0};

void solve() {
	cin >> a;
	ll ans = 0;
	int fl = 0;
	int len = 0;
	while (a) {
		++len;
		if (a % 2 == 0)
			fl = 1;
		a /= 2;
		ans = ans * 2 + 1;
	}
	if (fl) {
		cout << ans << "\n";
	}
	else {
		cout << arr[len] << "\n";
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i)
		solve();
	return 0;
}