#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005
#define FLN "test"

int n, k; deque <int> DQ;
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	DQ.assign(n+2, 0);
	for (int i=1; i<=n; i++) cin>>DQ[i];
	while (!DQ.empty())
	{
		if (DQ.front()>k) break;
		DQ.pop_front();
	}
	while (!DQ.empty())
	{
		if (DQ.back()>k) break;
		DQ.pop_back();
	}
	
	cout<<n-DQ.size();
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: