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

ll n, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	vector<ll> vec;
	rep(i, 2, 1000){
		while(n % i == 0){
			vec.push_back(i);
			n /= i;
		}
	}
	if(n > 1) vec.push_back(n);

	while(vec.size() > k){
		ll x = vec.back();
		vec.pop_back();
		vec.back() *= x;
	}
	if(vec.size() < k) cout << -1 << endl;
	else{
		for(auto x : vec) cout << x << " "; cout << endl;
	}

	return 0;
}