#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=2e5+5;
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
int n; 
double a[maxn],b[maxn],sum,ans,m;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
    for(int i=1;i<=n;i++)scanf("%lf",&b[i]);
    sum=b[1]/a[1];
    for(int i=1;i<=n;i++)sum=min(b[i]/a[i],sum);
   	for(int i=1;i<=n;i++)ans+=a[i]*sum;
	printf("%.5lf\n",min(ans,m));
 	return 0;
}