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
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll a[5005], s[5005];
ll l[5005], r[5005];
bool used[5005];
ll dp[5005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 0, 5000) l[i] = inf, r[i] -inf;
	rep(i, 1, n) chmin(l[a[i]], i), chmax(r[a[i]], i);
	
	//rep(j, 0, n) cout << ng[j] << " "; cout << endl;
	
	rep(i, 1, n) dp[i] = -inf;
	rep(i, 0, n-1){
		rep(j, 0, 5000) used[j] = false;
		ll cost = 0, R = -inf;
		chmax(dp[i+1], dp[i]);
		
		rep(j, i+1, n){
			chmax(R, r[a[j]]);
			if(l[a[j]] < i+1) break;
			
			if(!used[a[j]]) cost ^= a[j];
			used[a[j]] = true;
			if(R <= j) chmax(dp[j], dp[i] + cost);
		}
	}
	cout << dp[n] << endl;
	
	return 0;
}