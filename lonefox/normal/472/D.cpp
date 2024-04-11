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
const LD EPS = 1e-12;
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
	int N;
	int i,j,a,b,p;
	static int D[2000][2000];
	static PR P[2000][2000];
	static vector<PR> ch[2000];
	Read(N);
		Fox(i,N)
			Fox(j,N)
			{
				Read(D[i][j]);
					if (bool(i==j)!=bool(D[i][j]==0))
						goto Bad;
				P[i][j]=mp(D[i][j],j);
			}
		Fox(i,N)
			Fox(j,N)
				if (D[i][j]!=D[j][i])
					goto Bad;
	sort(P[0],P[0]+N);
		Fox1(i,N-1)
		{
			a=P[0][i].y;
				FoxR1(j,i-1)
				{
					b=P[0][j].y;
						if (D[0][a]==D[0][b]+D[b][a])
						{
							p=b;
							ch[b].pb(mp(a,P[0][i].x));
							goto Skip;
						}
				}
			p=0;
			ch[0].pb(mp(a,P[0][i].x));
Skip:;
				Fox(j,i)
				{
					b=P[0][j].y;
						if (D[a][b]!=D[a][p]+D[p][b])
							goto Bad;
				}
		}
	printf("YES\n");
	return(0);
Bad:;
	printf("NO\n");
	return(0);
}