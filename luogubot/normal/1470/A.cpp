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
const int N=3e5+10;
int c[N],k[N],n,m;
signed main(){
	int T=read();while(T--){
		n=read(),m=read();int ans=0;
		For(i,1,n)k[i]=read();sort(k+1,k+1+n);
		For(i,1,m)c[i]=read();
		int now=1;
		Rof(i,n,1){
			int x=k[i];
			if(now<x)ans+=c[now++];
			else ans+=c[x];
		}cout<<ans<<endl;
	}
	return 0;
}