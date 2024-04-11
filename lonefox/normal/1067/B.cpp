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

bool ReadLL(LL &x)
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

#define MOD 998244353
#define LIM 100005

int dist[LIM],prv[LIM];
vector<int> con[LIM];

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,c,d,x,y,z,v;
	queue<int> Q;
	Read(N),Read(K);
		Fox(i,N-1)
		{
			Read(j),Read(k),j--,k--;
			con[j].pb(k);
			con[k].pb(j);
		}
	Fill(dist,-1);
	Q.push(0),dist[0]=0;
		while (!Q.empty())
		{
			i=Q.front(),Q.pop();
				Fox(j,Sz(con[i]))
					if (dist[k=con[i][j]]<0)
						Q.push(k),dist[k]=dist[i]+1,prv[k]=i;
		}
	a=i;
	Fill(dist,-1);
	Q.push(a),dist[a]=0;
		while (!Q.empty())
		{
			i=Q.front(),Q.pop();
				Fox(j,Sz(con[i]))
					if (dist[k=con[i][j]]<0)
						Q.push(k),dist[k]=dist[i]+1,prv[k]=i;
		}
	b=i;
		if (dist[b]!=K*2)
			goto Imp;
	int R=b;
		Fox(i,K)
			R=prv[R];
	Fill(dist,-1);
	Q.push(R),dist[R]=0;
		while (!Q.empty())
		{
			i=Q.front(),Q.pop();
				if (Sz(con[i])==1)
				{
						if (dist[i]!=K)
							goto Imp;
					continue;
				}
				if (Sz(con[i])<(i==R ? 3 : 4))
					goto Imp;
				Fox(j,Sz(con[i]))
					if (dist[k=con[i][j]]<0)
						Q.push(k),dist[k]=dist[i]+1,prv[k]=i;
		}
	printf("Yes\n");
	return(0);
Imp:;
	printf("No\n");
	return(0);
}