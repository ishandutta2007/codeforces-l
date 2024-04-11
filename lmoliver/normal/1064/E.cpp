#include<bits/stdc++.h>
using namespace std;
/* loops */
#define F(p) for(int (p)=0;p<n;p++)
#define Fm(p) for(int (p)=0;p<m;p++)
#define Fd(p) for(int (p)=n-1;p>=0;p--)
#define Fdm(p) for(int (p)=m-1;p>=0;p--)
#define FI(p) for(int (p)=1;p<=n;p++)
#define FIm(p) for(int (p)=1;p<=m;p++)
#define FId(p) for(int (p)=n;p>=1;p--)
#define FIdm(p) for(int (p)=m;p>=1;p--)
/* LL & INF */
typedef long long LL;
const int INF=(1<<30)-(1<<6);
const LL LINF=((LL)1<<62)-(1<<6);
/* read template */
template<int L,int R,class T=int>struct Parray{T arr[R-L+1];inline int& operator[] (int i){return arr[i-L];}};void inline _read(int &x){scanf("%d",&x);}void inline _read(char *x){scanf("%s",x);}void inline _read(string &x){cin>>x;}void inline readln(string &x){getline(cin,x);}void inline _read(const char *x){scanf(x);}template<typename T1>inline void read(T1 &x1){_read(x1);}template<typename T1,typename T2>inline void read(T1 &x1,T2 &x2){_read(x1);read(x2);}template<typename T1,typename T2,typename T3>inline void read(T1 &x1,T2 &x2,T3 &x3){_read(x1);read(x2,x3);}template<typename T1,typename T2,typename T3,typename T4>inline void read(T1 &x1,T2 &x2,T3 &x3,T4 &x4){_read(x1);read(x2,x3,x4);}
inline void qaq(int x,int y){
	cout<<x<<" "<<y<<endl;
    fflush(stdout);
}
const int E=1000000000;
inline void q(int id){
	if(id>E)qaq(id-E-1,0);
	else qaq(0,E-id);
}
int main(){
	int n;
	read(n);
	int l=1,r=2*E+1;
	F(i){
		if(l>=r){
			cerr<<"GG"<<endl;
//			return 0;
		}
		int mid=((LL)l+r)/2;
		q(mid);
		string s;
		cin>>s;
		if(s=="black"){
			l=mid;
		}else{//(s=="white")
			r=mid;
		}
//		cerr<<'#'<<i<<endl;
	}
	if(l==1){
		printf("%d %d %d %d\n",2,E-1,5,E-2);
	}else if(r==2*E+1){
		printf("%d %d %d %d\n",E-1,2,E-2,5);
	}else if(l<=E){
		printf("%d %d %d %d\n",2,E-l,5,E-l+1);
	}else if(l>E){
		printf("%d %d %d %d\n",l-E,2,l-E+1,5);
	}else{
		cerr<<"qwq?"<<endl;
	}
    return 0;
}