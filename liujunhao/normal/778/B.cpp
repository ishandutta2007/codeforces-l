#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<string>
#include<iostream>
#include<ext/pb_ds/priority_queue.hpp>  
#include<queue>
#include<stack>
#define pb push_back
#define all(a) a.begin(),a.end()
#define pointtype double
#define pointtype_INT 0
using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
typedef unsigned uint;
typedef unsigned long long uLL;
const double pi=acos(-1);
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
struct point{
	pointtype x,y;
	inline point(){
	}
	inline point(pointtype x,pointtype y=0):x(x),y(y){
	}
	inline point operator+(const point &a)const{
		return point(x+a.x,y+a.y);
	}
	inline point operator+=(const point &a){
		return *this=*this+a;
	}
	inline point operator-(const point &a)const{
		return point(x-a.x,y-a.y);
	}
	inline point operator-=(const point &a){
		return *this=*this-a;
	}
	inline bool operator<(const point &b)const{
		if(x==b.x)
			return y<b.y;
		return x<b.x;
	}
	inline bool operator==(const point &b)const{
		return x==b.x&&y==b.y;
	}
	#if pointtype_INT==1
		inline point operator*(const point &a)const{
			return point(1ll*x*a.x-1ll*y*a.y,1ll*x*a.y+1ll*y*a.x);
		}
		inline friend LL cross(const point &a,const point &b){
			return 1ll*a.x*b.y-1ll*a.y*b.x;
		}
		inline friend LL dot(const point &a,const point &b){
			return 1ll*a.x*b.x+1ll*a.y*b.y;
		}
	#else
		inline point operator*(const point &a)const{
			return point(x*a.x-y*a.y,x*a.y+y*a.x);
		}
		inline friend pointtype cross(const point &a,const point &b){
			return a.x*b.y-a.y*b.x;
		}
		inline friend pointtype dot(const point &a,const point &b){
			return a.x*b.x+a.y*b.y;
		}
	#endif
};
template<class T,class T2>
struct hashnode{
	T val;
	T2 v;
	hashnode *next;
};
template<class T,class T2>
inline int& addhash(int u,const T &val,T2 *&ecnt,T2 **adj){
	T2 *p=++ecnt;
	p->val=val;
	p->v=0;
	p->next=adj[u];
	adj[u]=p;
	return p->v;
}
template<class T,class T2,int MOD,int ss>
class hash_table{
	hashnode<T,T2>*adj[MOD],edge[ss+10],*ecnt;
	int sz;
	public:
	inline int Get_val(int x){
		return x%MOD;
	}
	#if pointtype_INT==1
		inline int Get_val(point x){
			return (x.x*998244353ll+x.y)%MOD;
		}
	#endif
	inline hash_table():ecnt(edge),sz(0){
		for(int i=0;i<MOD;i++)
			adj[i]=0;
	}
	inline int size(){
		return sz;
	}
	inline hashnode<T,T2>* hash(const T &x){
		int t=Get_val(x);
		for(hashnode<T,T2> *p=adj[t];p;p=p->next)
			if(p->val==x)
				return p;
		return 0;
	}
	inline int &operator[](const T &x){
		hashnode<T,T2> *p=hash(x);
		if(p)
			return p->v;
		return ++sz,addhash(Get_val(x)%MOD,x,ecnt,adj);
	}
	inline bool count(const T &x){
		return hash(x);
	}
	inline void clear(){
		ecnt=edge;
		int t=MOD>>2<<2,i;
		for(i=0;i<t;i+=4){
			adj[i]=0;
			adj[i+1]=0;
			adj[i+2]=0;
			adj[i+3]=0;
		}
		for(;i<MOD;i++)
			adj[i]=0;
		sz=0;
	}
};
template<int sz,int MOD>
struct Matrix{
	int a[sz][sz];
	inline Matrix(){
		memset(a,0,sizeof a);
	}
	inline Matrix(int){
		memset(a,0,sizeof a);
		for(int i=0;i<sz;i++)
			a[i][i]=1;
	}
	inline Matrix operator *(const Matrix &b)const{
		static Matrix c;
		int i,j,k;
		for(i=0;i<sz;i++)
			for(j=0;j<sz;j++)
				if(a[i][j])
					for(k=0;k<sz;k++)
						c.a[i][k]=(c.a[i][k]+1ll*a[i][j]*b.a[j][k])%MOD;
	}
	inline Matrix &operator *=(const Matrix &b){
		return *this=*this*b;
	}
	friend Matrix quick_pow(Matrix a,int b){
		Matrix ret(1);
		while(b){
			if(b&1)
				ret*=a;
			a*=a;
			b>>=1;
		}
		return ret;
	}
};
struct cpx{
	double r,i;
	inline cpx(){
	}
	inline cpx(double r,double i):r(r),i(i){
	}
	inline cpx operator+(const cpx &a)const{
		return cpx(r+a.r,i+a.i);
	}
	inline cpx operator-(const cpx &a)const{
		return cpx(r-a.r,i-a.i);
	}
	inline cpx operator*(const cpx &a)const{
		return cpx(r*a.r-i*a.i,r*a.i+i*a.r);
	}
	inline cpx operator/(const double &a)const{
		return cpx(r/a,i/a);
	}
	inline cpx operator/(const cpx&a)const{
		return *this*cpx(a.r,-a.i)/(a.r*a.r+a.i*a.i);
	}
	inline cpx operator+=(const cpx &a){
		return *this=*this+a;
	}
	inline cpx operator-=(const cpx &a){
		return *this=*this-a;
	}
	inline cpx operator*=(const cpx &a){
		return *this=*this*a;
	}
	inline cpx operator/=(const cpx &a){
		return *this=*this/a;
	}
};
template<class T,int len>
struct polynomial{
	T a[len];
	inline void clear(){
		int t=len>>2<<2,i;
		for(i=0;i<t;i+=4){
			a[i]=0;
			a[i+1]=0;
			a[i+2]=0;
			a[i+3]=0;
		}
		for(;i<len;i++)
			a[i]=0;
	}
	inline polynomial operator+(const polynomial &b)const{
		static polynomial c;
		int t=len>>2<<2,i;
		for(i=0;i<t;i+=4){
			c.a[i]=a[i]+b.a[i];
			c.a[i+1]=a[i+1]+b.a[i+1];
			c.a[i+2]=a[i+2]+b.a[i+2];
			c.a[i+3]=a[i+3]+b.a[i+3];
		}
		for(;i<len;i++)
			c.a[i]=a[i]+b.a[i];
		return c;
	}
	inline polynomial operator+=(const polynomial &b){
		return *this=*this+b;
	}
	inline polynomial operator-(const polynomial &b)const{
		static polynomial c;
		int t=len>>2<<2,i;
		for(i=0;i<t;i+=4){
			c.a[i]=a[i]-b.a[i];
			c.a[i+1]=a[i+1]-b.a[i+1];
			c.a[i+2]=a[i+2]-b.a[i+2];
			c.a[i+3]=a[i+3]-b.a[i+3];
		}
		for(;i<len;i++)
			c.a[i]=a[i]-b.a[i];
		return c;
	}
	inline polynomial operator-=(const polynomial &b){
		return *this=*this-b;	 
	}
	friend void fft(polynomial &a,int N,int f){
		int i,j,t,k;
		for(i=1,j=0;i<N-1;i++){
			for(t=N;j^=t>>=1,~j&t;);
			if(i<j)
				swap(a[i],a[j]);
		}
		for(i=1;i<N;i<<=1){
			t=i<<1;
			cpx wn(cos(pi/i),f*sin(pi/i));
			for(j=0;j<N;j+=t){
				cpx w(1);
				for(k=0;k<i;k++,w*=wn){
					cpx x(a[j+k]),y(a[j+k+i]*w);
					a[j+k]=x+y,a[j+k+i]=x-y;
				}
			}
		}
		if(f==-1)
			for(i=0;i<N;i++)
				a[i]/=N;
	}
	inline polynomial operator*(const polynomial &b)const{
		static polynomial c;
		fft(*this,len,1);
		fft(b,len,1);
		int i;
		for(i=0;i<len;i++)
			c[i]=a[i]*b[i];
		fft(c,len,-1);
		return c;
	}
};
//template
#include<unordered_map>
unordered_map<string,int>val;
#define MAXN 5000
struct OP{
	string now;
	int tp;
	string a,b;
}a[MAXN+10];
int n,m;
string mx,mi;
char s[MAXN+10];
void read(){
	Read(n),Read(m);
	int i;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		a[i].now=s;
		scanf("%s",s);
		scanf("%s",s);
		a[i].a=s;
		if(getchar()=='\n'){
			a[i].tp=-1;
			continue;
		}
		scanf("%s",s);
		if(*s=='A'){
			a[i].tp=0;
		}
		else if(*s=='O')
			a[i].tp=1;
		else
			a[i].tp=2;
		scanf("%s",s);
		a[i].b=s;
	}
}
int fun(int tp,int a,int b){
	if(!tp)
		return a&b;
	else if(tp==1)
		return a|b;
	else
		return a^b;
}
int cal(int i,int x){
	val.clear();
	int sum=0,j;
	for(j=1;j<=n;j++){
		if(a[j].tp==-1){
			if(a[j].a[0]=='0'||a[j].a[0]=='1'){
				int t=a[j].a[i]-'0';
				val[a[j].now]=t;
				sum+=t;
			}
			else{
				int t=val[a[j].a];
				sum+=t;
				val[a[j].now]=t;
			}
		}
		else{
			int t1,t2;
			if(a[j].a[0]=='?')
				t1=x;
			else
				t1=val[a[j].a];
			if(a[j].b[0]=='?')
				t2=x;
			else
				t2=val[a[j].b];
			t1=fun(a[j].tp,t1,t2);
			sum+=t1;
			val[a[j].now]=t1;
		}
	}
	return sum;
}
void solve(){
	int sum0,sum1,i;
	for(i=0;i<m;i++){
		
		sum0=cal(i,0),sum1=cal(i,1);
		if(sum0>=sum1)
			mx+='0';
		else
			mx+='1';
		if(sum0<=sum1)
			mi+='0';
		else
			mi+='1';
	}
}
int main()
{
	read();
	solve();
	cout<<mi<<endl<<mx<<endl;
}