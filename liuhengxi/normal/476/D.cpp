#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k;
int main()
{
	read(n);read(k);
	printf("%d\n",(n*6-1)*k);
	F(i,0,n)printf("%d %d %d %d\n",(i*6+1)*k,(i*6+2)*k,(i*6+3)*k,(i*6+5)*k);
	return 0;
}