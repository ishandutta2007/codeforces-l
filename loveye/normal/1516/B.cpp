#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 2005;
int t,a[N],n,s[N];
int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		fr(i,1,n) cin >> a[i],s[i] = s[i-1] ^ a[i];
		int ok = 0;
		fr(i,1,n) if(s[i] == (s[n] ^ s[i])) {
			cout << "YES" << endl;ok = 1;break;
		}
		if(!ok) fr(l,1,n) {
			fr(r,l+1,n) if(s[l] == (s[r] ^ s[l]) && s[l] == (s[n] ^ s[r]))
			{cout << "YES" << endl;ok = 1;break;}
			if(ok) break;
		}
		if(!ok) cout << "NO" << endl;
	}
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