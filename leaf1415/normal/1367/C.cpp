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
llint n, k;
string s;
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		cin >> s;
		
		vec.clear();
		vec.push_back(-k-1);
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '1') vec.push_back(i);
		}
		vec.push_back(s.size()+k);
		
		llint ans = 0;
		for(int i = 1; i < vec.size(); i++){
			llint d = vec[i]-vec[i-1];
			ans += max(0LL, d/(k+1)-1);
		}
		cout << ans << endl;
	}
	
	return 0;
}