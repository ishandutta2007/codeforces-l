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

ll T;
ll n;
ll a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		ll sum = 0;
		rep(i, 1, n) cin >> a[i], sum += a[i];
		sort(a+1, a+n+1);
		
		ll need = max(a[n]*(n-1), (sum+n-2)/(n-1)*(n-1));
		cout << need - sum << endl;
	}
	
	return 0;
}