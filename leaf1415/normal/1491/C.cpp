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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll T;
ll n;
ll a[5005], b[5005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n+1) b[i] = 0;
		
		ll ans = 0;
		rep(i, 1, n){
			if(b[i] > a[i]-1) b[i+1] += b[i]-(a[i]-1);
			if(a[i] > 5000) ans += a[i] - 5000, a[i] = 5000;
			rep(j, 2, a[i]){
				if(i+j > n) ans++;
				else b[i+j]++;
			}
		}
		ans += b[n+1];
		cout << ans << endl;
	}
	return 0;
}