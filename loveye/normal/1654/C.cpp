#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5;
int n; ll a[N];
map<ll,ll> cnt;
set<ll> s;
priority_queue<ll> pq;
int main() {
	int t; cin>>t; while(t--) {
		cin>>n;
		cnt.clear();
		s.clear();
		ll sum=0;
		fr(i,1,n) cin>>a[i],++cnt[a[i]],sum+=a[i];
		for(ll u=sum;u;u>>=1) s.insert(u);
		for(ll u=sum;u>1;u=u+1>>1) s.insert(u);
		int ok=1;
		fr(i,1,n) if(!s.count(a[i])) ok=0;
		if(!ok) {
			cout<<"No"<<endl;
			continue;
		}
		//cout<<sum<<endl;
		while(!pq.empty()) pq.pop();
		pq.push(sum);
		while(!pq.empty()) {
			ll u=pq.top(); pq.pop();
			//cout<<u<<endl;
			if(cnt.empty()) {
				ok=0; break;
			}
			if(u<(--cnt.end())->first) {
				ok=0; break;
			}
			if(cnt.count(u)) {
				if(!--cnt[u]) cnt.erase(cnt.lower_bound(u));
			} else pq.push(u>>1),pq.push(u+1>>1);
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}