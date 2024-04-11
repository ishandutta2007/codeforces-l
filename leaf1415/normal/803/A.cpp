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
ll a[105][105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n){
		rep(j, 1, n){
			if(i > j) continue;
			if(k <= 0) goto end;
			if(i == j) a[i][j] = 1, k--;
			else if(k >= 2) a[i][j] = a[j][i] = 1, k-= 2;
		}
	}
	end:;
	if(k > 0) cout << -1 << endl;
	else{
		rep(i, 1, n){
			rep(j, 1, n) cout << a[i][j] << " ";
			cout << endl;
		}
	}
	
	return 0;
}