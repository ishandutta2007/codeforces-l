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

ll k;
string s;
vector<ll> vec;

bool check(ll w)
{
	ll ret = 1, sum = 0;
	for(auto x : vec){
		if(x > w) return false;
		if(sum + x <= w) sum += x;
		else{
			ret++;
			sum = x;
		}
	}
	return ret <= k;
}

int main(void)
{
	ios::sync_with_stdio(0);
	
	cin >> k;
	while(cin >> s){
		string t;
		for(auto c : s){
			t += c;
			if(c == '-') vec.push_back(t.size()), t = "";
		}
		vec.push_back(t.size()+1);
	}
	vec.back()--;
	
	ll ub = 1e7, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	
	return 0;
}