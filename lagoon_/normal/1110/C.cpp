#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define re register
int num[]={0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main()
{
	re int q,cc,cc1,ck;
	scanf("%d",&q);
	for(re int i=1;i<=q;i++)
	{
		scanf("%d",&cc);
		cc++;cc1=cc;
		ck=0;
		for(;cc!=1;ck++,cc>>=1);
		if((cc1&-cc1)!=cc1)printf("%d\n",(1<<(ck+1))-1);
		else
		{
			printf("%d\n",num[ck]);
		}
	}
}