#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 2e5 + 5;
int n,m,a[N],ans[N];
pair<int,int> b[N];
struct Query {
	int k,p,id;
} q[N];
vector<int> s;
int ch[N*30][2],nds = 1,siz[N*30];
void Insert(int x) {
	int cur = 1;
	rf(i,29,0) {
		int &son = ch[cur][x >> i & 1];
		if(!son) son = ++nds;
		++siz[cur = son];
	}
}
int getkth(int k) {
	int cur = 1,ans = 0;
	rf(i,29,0) {
		int res = siz[ch[cur][0]];
		if(k <= res) cur = ch[cur][0];
		else k -= res,cur = ch[cur][1],ans |= 1 << i;
	} return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	fr(i,1,n) {
		cin >> a[i];
		b[i] = make_pair(a[i],n-i);
	}
	sort(b+1,b+n+1,greater<pair<int,int> >());
	cin >> m;
	fr(i,1,m) cin >> q[i].k >> q[i].p,q[i].id = i;
	sort(q+1,q+m+1,[](const Query &a,const Query &b) {
		return a.k < b.k;
	});
	int p = 1;
	fr(i,1,m) {
		while(p <= q[i].k) {
			Insert(n-b[p].second);
			++p;
		}
		ans[q[i].id] = a[getkth(q[i].p)];
	}
	fr(i,1,m) cout << ans[i] << endl;
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}