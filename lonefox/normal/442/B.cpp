#define DEBUG 0

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }

const int INF = (int)1e9;
const double EPS = 1e-9;
const LD PI = acos(-1.0);

//#if DEBUG
#define GETCHAR getchar
/*#else
#define GETCHAR getchar_unlocked
#endif*/

bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if ((c<0) && (!r))
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,i,ans2,b;
	LD p1,p2,x1,x2;
	LD P[100];
	LD ans;
	Read(N);
		Fox(i,N)
			cin >> P[i];
	sort(P,P+N);
	reverse(P,P+N);
	ans=p1=P[0],p2=1-P[0];
		Fox1(i,N-1)
		{
			x1=p1*(1-P[i]) + p2*P[i];
			x2=p2*(1-P[i]);
			p1=x1;
			p2=x2;
			Max(ans,p1);
		}
	cout << fixed << setprecision(18) << ans << endl;
	/*ans=-1;
		Fox(b,1<<N)
		{
			p1=0,p2=1;
				Fox(i,N)
					if (b&(1<<i))
					{
						x1=p1*(1-P[i]) + p2*P[i];
						x2=p2*(1-P[i]);
						p1=x1;
						p2=x2;
					}
				if (p1>ans)
					ans=p1,ans2=b;
		}
		Fox(i,N)
			if (ans2&(1<<i))
				printf("%d ",i);
	printf("\n");
	cout << fixed << setprecision(18) << ans << endl;*/
	return(0);
}