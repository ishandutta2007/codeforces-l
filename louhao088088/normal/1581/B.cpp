#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
const int maxn=2e5+5,mod=1e9+7;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
void print(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m,T,f[maxn],ans,k; 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();m=read(),k=read();
		if(k<2)puts("NO");
		else if(n>m+1)puts("NO");
		else if(k==2&&m==0)puts("YES");
		else if(k==2)puts("NO"); 
		else if(m>(n-1)*(n)/2)puts("NO");
		else if(k>3)puts("YES");
		else
		{
			if(m>=(n-1)*n/2)puts("YES");
			else puts("NO");
		}
	}
 	return 0;
}