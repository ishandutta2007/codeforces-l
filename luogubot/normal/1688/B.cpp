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
const int N=2e5+10;
int n,a[N],m,k,ok[100];
signed main(){
	int TTT=read();while(TTT--){
		int fl=0;For(i,1,50)ok[i]=0;
		For(i,1,n=read())a[i]=read(),fl|=(a[i]&1);
		if(!fl){
			int ans=n-1,res=50;For(i,1,n){
				int c=0;while(!(a[i]&1))a[i]>>=1,c++;
				res=min(res,c);
			}
			cout<<ans+res<<endl;
		}else{
			int ans=0;For(i,1,n)ans+=!(a[i]&1);cout<<ans<<endl;
		}
	}
	return 0;
}