// Problem: CF1188D Make Equal
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1188D
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 2022-01-21 21:05:35
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
#define int long long
const int maxn=1e5+5,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,a[maxn],f[65][maxn],k,z,cnt=0,tot=0;
bool cmp(int x,int y){return (x&((1ll<<k)-1))>(y&((1ll<<k)-1));}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)a[i]=a[n]-a[i];f[0][0]=0;
	for(int i=0;i<=60;i++)
	{
	//	cout<<"A";
		k=i;if(i)sort(a+1,a+n+1,cmp);z=1ll<<i;cnt=0,tot=0;
	//	cout<<a[1]<<" "<<a[2]<<endl;
		for(int j=1;j<=n;j++)
		{
		//	cout<<"A"<<' '<<a[j]<<" ";
			if(a[j]&z)cnt++;//,cout<<j<<endl;
		}
			//return 0;
		for(int j=0;j<=n;j++)
		{
		//	cout<<"A";
			if(a[j]&z)tot++;
			f[i+1][tot]=min(f[i+1][tot],f[i][j]+j-tot+cnt-tot);
			f[i+1][cnt+j-tot]=min(f[i+1][cnt+j-tot],f[i][j]+n-j-cnt+tot+tot);
		}
	//	for(int j=0;j<=n;j++)cout<<f[i+1][j]<<" ";cout<<endl;
	}
	cout<<f[61][0]<<endl;
 	return 0;
}