#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define ll long long
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
int n;
char A,B;
char hh[5]={'^','>','v','<'};
int main()
{
	cin>>A>>B;
	n=read();
	n%=4;
	int a,b;
	for(int i=0;i<4;i++)
	{
		if(hh[i]==A)a=i;
		if(hh[i]==B)b=i;
	}
	if((a+n)%4==b&&((a-n)%4+4)%4!=b)
	cout<<"cw";
	else if((a+n)%4!=b&&((a-n)%4+4)%4==b)
	cout<<"ccw";
	else cout<<"undefined";
}