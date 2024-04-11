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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n;
llint a[105][3], ans[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int j = 0; j < 3; j++){
			for(int i = 0; i < n; i++){
				cin >> a[i][j];
			}
		}
		
		for(int i = 0; i < n; i++) ans[i] = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 3; j++){
				if(a[i][j] == ans[(i+1)%n] || a[i][j] == ans[(i-1+n)%n]) continue;
				ans[i] = a[i][j];
				break;
			}
		}
		for(int i = 0; i < n; i++) cout << ans[i] << " ";
		cout << endl;
	}
	
	return 0;
}