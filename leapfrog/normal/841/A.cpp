//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int n,K,tn[105];char a[105];
int main()
{
	read(n,K),scanf("%s",a+1);
	for(int i=1;i<=n;i++) tn[a[i]-'a']++;
	int mx=0;for(int i=0;i<26;i++) mx=max(mx,tn[i]);
	if(mx>K) return puts("NO"),0;else return puts("YES"),0;
}