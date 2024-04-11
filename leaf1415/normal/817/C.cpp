#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << (x) << endl
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, s;

ll get(ll x)
{
	ll ret = 0;
	for(;x;x/=10) ret += x%10;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	if(n <= s){
		cout << 0 << endl;
		return 0;
	}
	ll ans = s;
	rep(i, s+1, min(s+1000, n)){
		if(get(i)+s > i) ans++;
	}
	ans = n - ans;
	outl(ans);
	
	return 0;
}