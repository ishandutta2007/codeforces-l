/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>
using namespace std;
typedef int ll;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=2*(30+1)*(5+1);
ll a[2][mn][mn];
ll seen[mn][mn];
ll t[31];
ll vdx[8]={1,1,0,-1,-1,-1,0,1};
ll vdy[8]={0,1,1,1,0,-1,-1,-1};
class TaskD {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll n; in>>n;
		for (ll i=0;i<n;i++) in>>t[i];
		memset(seen,0,sizeof seen);
		memset(a,0,sizeof a);
		ll cur=0,nxt=1;
		for (ll y=0;y<=t[0]-1;y++) seen[mn/2][mn/2 + y]=1;
		a[cur][mn/2][mn/2+t[0]-1]=1<<2;
		for (ll i=1;i<n;i++) {
			memset(a[nxt],0,sizeof a[nxt]);
			for (ll x=0;x<mn;x++) {
				for (ll y = 0; y < mn; y++) {
					for (ll d = 0; d < 8; d++) {
						if (((1 << d) & a[cur][x][y]) == 0) continue;
						ll e = (d - 1 + 8) % 8;
						for (ll k = 0; k < 2; k++) {
							ll dx = vdx[e], dy = vdy[e];
							ll ix=x,iy=y;
							seen[ix][iy]=1;
							for (ll j=0;j<t[i];j++) {
								ix+=dx;iy+=dy;
								seen[ix][iy]=1;
							}
							a[nxt][ix][iy] |= 1<<e;
							e = (e + 2) % 8;
						}
					}
				}
			}
			//for (ll x=0;x<mn;x++) for (ll y=0;y<mn;y++) {
			//		if (a[cur][x][y]) printf("%d: %d %d\n",i,x-mn/2,y-mn/2);
			//	}
			swap(cur,nxt);
		}
		ll ans=0;
		for (ll x=0;x<mn;x++) for (ll y=0;y<mn;y++) ans+=seen[x][y];
		out<<ans<<endl;
	}
};


int main() {
	TaskD solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}