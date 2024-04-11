#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
  
char s[105];
int i,j,k,l,m,n;

int main()
{
    scanf("%d %d\n",&n,&m);
    gets(s+1);
    for(i=1;i<=n;i++)
    {
        if(s[i]=='G')k=i;
        if(s[i]=='T')l=i;
    }
    if(k==l)
    {
        printf("YES");
        return 0;
    }
    if(abs(k-l)%m!=0)
    {
        printf("NO");
        return 0;
    }
    if(l<k)
    {
        j=l;l=k;k=j;
    }
    for(i=k;i<l;i+=m)
    {
        if(s[i]=='#')
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}