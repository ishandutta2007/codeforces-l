#include <iostream>
#define llint long long

using namespace std;

llint T;
llint x, y;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> x >> y;
		if(x == y+1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	
	return 0;
}