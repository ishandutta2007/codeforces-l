#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n;

int main ()
{
	int i , j;
	cin >> n;
	cout << n*3/2 << "\n";
	for (i = 2 ; i <= n ; i += 2)
	{
		printf("%d ",i);
	}	
	for (i = 1 ; i <= n ; i += 2)
	{
		printf("%d ",i);
	}	
	for (i = 2 ; i <= n ; i += 2)
	{
		printf("%d ",i);
	}	
	cout << "\n";
	//system("PAUSE");
	return 0;
}