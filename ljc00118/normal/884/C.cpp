#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1e5 + 5;

vector <int> cycle;
bool used[N];
int a[N], n; ll ans = 0;

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(a[i]);
	for(register int i = 1; i <= n; i++) {
		if(!used[i]) {
			int cnt = 1, now = a[i]; used[i] = 1;
			while(!used[now]) {
				cnt++; used[now] = 1; now = a[now];
			}
			cycle.push_back(cnt); ans += (ll)cnt * cnt; 
		}
	}
	sort(cycle.begin(), cycle.end());
	int len = cycle.size();
	if(len == 1) {
		cout << ans << endl;
	} else {
		cout << ans - (ll)cycle[len - 2] * cycle[len - 2] - (ll)cycle[len - 1] * cycle[len - 1] + (ll)(cycle[len - 2] + cycle[len - 1]) * (cycle[len - 2] + cycle[len - 1]) << endl;
	}
	return 0;
}