//{{{
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf,buffer[1<<21];int P1=-1;const int P2=(1<<21)-1;
inline void flush() {fwrite(buffer,1,P1+1,stdout),P1=-1;}
inline void putc(const char &x) {if(P1==P2) flush();buffer[++P1]=x;}
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar();for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
}
template<typename T>inline void write(T x)
{
	int y=10,len=1;while(y<=x) y*=10,len++;
	while(len--) y/=10,putc(x/y+48),x%=y;
}/*}}}*/
int n,a[5005],cn[5005],res[5005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++)
	{
		memset(cn,0,sizeof(cn));int nw=5001;
		for(int j=i;j<=n;j++)
		{
			cn[a[j]]++;
			if(cn[a[j]]>cn[nw]||(cn[a[j]]==cn[nw]&&a[j]<nw)) nw=a[j];
			res[nw]++;
		}
	}
	for(int i=1;i<=n;i++) printf("%d%c",res[i],i==n?'\n':' ');
	return 0;
}