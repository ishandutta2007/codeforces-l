#pragma comment(linker,"/STACK:102400000,102400000") 
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
#define endl '\n'
#define PII pair<int,int>
#define	PD pair<double,double>
#define PDI pair<double,int>
#define ll long long
#define Fori(x) for(int i=0;i<x;i++)
#define Forj(x) for(int j=0;j<x;j++)
#define For1i(x) for(int i=1;i<=x;i++)
#define For1j(x) for(int j=1;j<=x;j++)
#define For(i,n) for(int i=0;i<n;i++)
#define y1 asdfeawf
using namespace std;
const int INF = 2147483647;
const int mod = 1000000007;
const double eps= 1e-8;
const long double pi = acosl(-1.0);
const int maxn = 1234567;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	if(n<6)
		cout<<-1<<endl;
	else
	{
		cout<<"1 2"<<endl;
		cout<<"1 3"<<endl;
		cout<<"1 4"<<endl;
		cout<<"2 5"<<endl;
		for(int i=6;i<=n;i++)
			cout<<"2 "<<i<<endl;
	}
	for(int i=1;i<n;i++)
		cout<<i<<" "<<i+1<<endl;
	return 0;
}