//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int n,sum,ans;

struct node
{
	int x,y;
}a[100005];

bool CMp(node a,node b)
{
	return a.x<b.x;
}

bool CMp1(node a,node b)
{
	return a.y<b.y;
}

signed main()
{
	n=read();ans=0x3f3f3f3f3f3f3f3f;
	for (int i=1;i<=n;i++) 
	{
		sum+=read();
		a[i].x=i,a[i].y=sum;
	}
	sort(a+1,a+n+1,CMp);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=min(n-i,100ll);j++)
		  ans=min(ans,(a[i+j].x-a[i].x)*(a[i+j].x-a[i].x)+(a[i+j].y-a[i].y)*(a[i+j].y-a[i].y));
	}
	sort(a+1,a+n+1,CMp1);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=min(n-i,100ll);j++)
		  ans=min(ans,(a[i+j].x-a[i].x)*(a[i+j].x-a[i].x)+(a[i+j].y-a[i].y)*(a[i+j].y-a[i].y));
	}
	writeln(ans);
}