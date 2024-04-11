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
char c[305][305];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(y, 1, n) rep(x, 1, n) cin >> c[x][y];
		
		ll cntO[3] = {}, cntX[3] = {};
		rep(y, 1, n) rep(x, 1, n){
			if(c[x][y] == 'O') cntO[(x+y)%3]++;
			if(c[x][y] == 'X') cntX[(x+y)%3]++;
		}
		ll mn = inf, mn_i;
		rep(i, 0, 2){
			if(mn > cntO[i]+cntX[(i+1)%3]) mn = cntO[i]+cntX[(i+1)%3], mn_i = i;
		}
		rep(y, 1, n) rep(x, 1, n){
			if(c[x][y] == 'O' && (x+y)%3 == mn_i) c[x][y] = 'X';
			if(c[x][y] == 'X' && (x+y)%3 == (mn_i+1)%3) c[x][y] = 'O';
		}
		
		rep(y, 1, n){
			rep(x, 1, n) cout << c[x][y];
			cout << endl;
		}
	}
	
	return 0;
}