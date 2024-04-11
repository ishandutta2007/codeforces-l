#include<cstdio>
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

const int N=3e5+5;
int n,m,a[N];
int chk(int x) {
	int res=0;
	fr(i,1,n) {
		if(a[i]+x>=m) {
			if(res<a[i]&&res>a[i]+x-m) res=a[i];
		} else {
			if(a[i]+x<res) return 0;
			res=max(res,a[i]);
		}
	} return 1;
}
int main() {
	scanf("%d%d",&n,&m);
	fr(i,1,n) scanf("%d",a+i);
	int l=0,r=m-1;
	while(l<r) {
		int mid=l+r>>1;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
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