// LUOGU_RID: 90691859
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e6+10,p=1e9+7;
inline int inv(int a,int b=p-2){
	a%=p;
	int x=1;while(b){
		if(b&1)(x*=a)%=p;
		(a*=a)%=p,b>>=1;
	}return x;
}
int n,a[N],V,s,f[N],g[N];
signed main(){
	For(i,1,n=read())(s+=a[i]=read())%=p,V=max(V,a[i]);
	g[0]=f[1]=(s-1)%p*((s-1)%p)%p*inv(s)%p;int now=0;
	For(i,1,V-1){
		g[i]=(g[i-1]-(s-1)%p*inv(s-i)%p+p)%p;
		f[i+1]=(f[i]+g[i])%p;
	}
	int ans=0;For(i,1,n)(ans+=f[a[i]])%=p;cout<<ans<<endl;
	return 0;
}