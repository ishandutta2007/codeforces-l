#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) begin(v), end(v)
#define sz(v) ((int) (v).size())
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " \
		<< #x<< " = " << (x) << endl

template<class T> ostream& operator<<(ostream &os,
		const vector<T> &v) {
	os << "\n[";
	for(const T &x : v) os << x << ',';
	return os << "]\n";
}

namespace std { template<class T1, class T2>
struct hash<pair<T1,T2>> { public:
	size_t operator()(const pair<T1,T2> &p) const {
		size_t x = hash<T1>()(p.x), y = hash<T2>()(p.y);
		return x ^ (y + 0x9e3779b9 + (x<<6) + (x>>2));
	}
}; }

void run() {
	ll a, b, n;
	cin >> a >> b >> n;
	int op = 0;
	while (a <= n && b <= n) {
		if (a < b)
			a += b;
		else
			b += a;
		// cerr << a << " " << b << endl;
		op++;
	}
	cout << op << endl;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	while (n--) run();
	return 0;
}