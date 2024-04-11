#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=5005;
int tt,n,x,y,s[N],cnt,pos[N];
long long f[N];
char a[N],b[N];
int main()
{
	read(tt);
	while(tt--)
	{
		read(n,x,y);
		scanf("%s",a);
		scanf("%s",b);
		cnt=0;
		F(i,0,n)cnt+=(s[i]=a[i]^b[i]);
		if(cnt&1)puts("-1");
		else
		{
			if(x>=y)
			{
				bool c=false;
				F(i,0,n-1)if(s[i]&&s[i+1])c=true;
				if(cnt==2&&c)printf("%d\n",min(y*2,x));
				else printf("%lld\n",(long long)y*(cnt>>1));
			}
			else
			{
				long long na=(long long)y*(cnt>>1);
				cnt=0;
				F(i,0,n)if(s[i])pos[cnt++]=i;
				f[0]=0;
				F(i,1,cnt+1)
				{
					f[i]=f[i-1];
					if(i>=2)f[i]=max(f[i],f[i-2]+max(y-(pos[i-1]-pos[i-2])*(long long)x,0ll));
				}
				printf("%lld\n",na-f[cnt]);
			}
		}
	}
	return 0;
}