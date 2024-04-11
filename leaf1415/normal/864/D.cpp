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
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll a[200005], cnt[200005];
bool used[200005];
set<ll> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], cnt[a[i]]++;
	
	ll ans = 0;
	rep(i, 1, n){
		if(cnt[i] == 0) S.insert(i), ans++;
	}
	
	rep(i, 1, n){
		if(cnt[a[i]] == 1) continue;
		if(!used[a[i]]) S.insert(a[i]);
		ll x = *S.begin();
		S.erase(a[i]);
		cnt[a[i]]--;
		a[i] = x;
		cnt[a[i]]++;
		used[x] = true;
		S.erase(x);
	}
	
	cout << ans << endl;
	rep(i, 1, n){
		cout << a[i];
		if(i < n) cout << " ";
	}
	cout << endl;
	
	return 0;
}