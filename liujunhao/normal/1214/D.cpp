#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<cassert>
#include<map>
#include<string>
#include<iostream>
#include<ext/pb_ds/priority_queue.hpp>
#include<queue>
#include<stack>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
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
	inline Matrix(int x){
		memset(a,0,sizeof a);
		for(int i=0;i<sz;i++)
			a[i][i]=x;
	}
	inline void clear(){
		memset(a,0,sizeof a);
	}
	inline Matrix operator *(const Matrix &b)const{
		static Matrix c;
		c.clear();
		int i,j,k;
		for(i=0;i<sz;i++)
			for(j=0;j<sz;j++)
				if(a[i][j])
					for(k=0;k<sz;k++)
						c.a[i][k]=(c.a[i][k]+1ll*a[i][j]*b.a[j][k])%MOD;
		return c;
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
	inline cpx(double r,double i=0):r(r),i(i){
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
	inline cpx conj(){
		return cpx(r,-i);
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
	inline polynomial operator*(const polynomial &b){
		static polynomial ret;
		ret.clear();
		for(int i=0;i<len;i++)
			for(int j=0;j<=i;j++)
				ret.a[i]+=a[j]*b.a[i-j];
		return ret;
	}
	inline void Antiderivative(int c){
		int i;
		for(i=len-1;i;i--)
			a[i]=a[i-1]/i;
		a[0]=c;
	}
	inline T Get_val(T c){
		T ret(a[0]);
		for(int i=1;i<len;i++){
			ret+=c*a[i];
			c*=c;
		}
		return ret;
	}
};
void fft(cpx *a,int N,int f){
	int i,j=0,k,t;
	for(i=1;i<N-1;i++){
		for(t=N;j^=t>>=1,~j&t;);
		if(i<j)
			swap(a[i],a[j]);
	}
	for(i=1;i<N;i<<=1){
		cpx wn(cos(pi/i),f*sin(pi/i));
		t=i<<1;
		for(j=0;j<N;j+=t){
			cpx w(1,0);
			for(k=0;k<i;k++,w*=wn){
				cpx x(a[j+k]),y(w*a[j+k+i]);
				a[j+k]=x+y,a[j+k+i]=x-y;
			}
		}
	}
	if(f==-1)
		for(i=0;i<N;i++)
			a[i].r/=N;
}
void mul(cpx *a,cpx *b,cpx *c,cpx *t,int N){
	int i,j;
	for(i=0;i<N;i++)
		t[i]=cpx(a[i].r,b[i].r);
	fft(t,N,1);
	for(i=0;i<N;i++){
		j=(N-i)&(N-1);
		c[i]=(t[i]*t[i]-(t[j]*t[j]).conj())*cpx(0,-0.25);
	}
	fft(c,N,-1);
	// c refer t
	//a[i]=(c[i]+c[k-i])/2
	//b[i]=-i(c[i]-c[k-i])/2
	//a[i]*b[i]=(c[i]*c[i]-c[k-i]*c[k-i])*((-i)/4)
}
namespace mypq{
	template<class T,class Container=std::vector<T>,class cmp=std::less<typename Container::value_type> >
	struct priority_queue{
		std::priority_queue<T,Container,cmp>ins,del;
		inline void push(T a){
			ins.push(a);
		}
		inline void erase(T a){
			del.push(a);
		}
		inline void pop(){
			while(!del.empty()&&ins.top()==del.top())
				ins.pop(),del.pop();
			ins.pop();
		}
		inline T top(){
			while(!del.empty()&&ins.top()==del.top())
				ins.pop(),del.pop();
			return ins.top();
		}
		inline T second_top(){
			T tmp=top(),ret;
			pop();
			ret=top();
			push(tmp);
			return ret;
		}
		inline void clear(){
			while(!ins.empty())
				ins.pop();
			while(!del.empty())
				del.pop();
		}
		inline int size(){
			return ins.size()-del.size();
		}
		inline bool empty(){
			return !size();
		}
	};
}
void exgcd(long long a,long long b,long long &d,long long &x,long long &y){
    if(!b){
        d=a;
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,d,y,x);
    y-=a/b*x;
}
//template
#define MAXN 1000000
int n,m;
char s[MAXN+10];
vector<int>a[MAXN+10];
int fr[MAXN+10],cnt,dist[MAXN+10];
bool vis[MAXN+10];
queue<int>q;
int dir[8][2]={1,0,0,1};
void bfs(int st){
	int u,d;
	q.push(st);
	vis[st]=1;
	while(!q.empty()){
		u=q.front();
		q.pop();
		int x=u/m,y=u%m;
		for(d=0;d<2;d++){
			int tx=x+dir[d][0],ty=y+dir[d][1];
			if(tx<0||ty<0||tx>=n||ty>=m)
				continue;
			if(vis[tx*m+ty]||s[tx*m+ty]=='#')
				continue;
			vis[tx*m+ty]=1;
			q.push(tx*m+ty);
			fr[tx*m+ty]=u;
		}
	}
}
/*void bfs2(){
	int i;
	for(i=1;i<m;i++){
		if(s[i]=='.'){
			q.push(i);
			dist[i]=1;
		}
		else{
			if(!vis[bl[i]]){
				vis[bl[i]]=1;
				for(auto x:a[bl[i]])
					if(!dist[x])
						q.push(x),dist[x]=1;
			}
		}
	}
	for(i=2;i<n;i++){
		if(s[i*m-1]=='.'){
			q.push(i*m-1);
			dist[i*m-1]=1;
		}
		else{
			if(!vis[bl[i*m-1]]){
				vis[bl[i*m-1]]=1;
				for(auto x:a[bl[i*m-1]])
					if(!dist[x])	
						q.push(x),dist[x]=1;
			}
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int x=u/m,y=u%m;
		for(int d=0;d<8;d++){
			int tx=x+dir[d][0],ty=y+dir[d][1];
			if((tx==0&&tx==0)||(tx==n&&ty==m))
				continue;
				
			if(tx<0||ty<0||tx>=n||ty>=m)
				continue;
			int t=tx*m+ty;
			if(dist[t])
				continue;
			if(s[t]=='#'){
				if(!vis[bl[t]]){
					vis[bl[t]]=1;
					for(auto x:a[bl[t]])
						if(!dist[x]){
							q.push(x),dist[x]=dist[u]+1;
						}
				}
			}
			else{
				q.push(t);
				dist[t]=dist[u]+1;
			}
		}
	}
}*/
int main()
{
	Read(n),Read(m);
	int i;
	for(i=0;i<n;i++)
		scanf("%s",s+i*m);
	bfs(0);
	if(!vis[n*m-1]){
		puts("0");
		return 0;
	}
	int t=fr[n*m-1];
	do{
		s[t]='#';
		t=fr[t];
	}while(t);
	memset(vis,0,sizeof vis);
	bfs(0);
	if(!vis[n*m-1])
		puts("1");
	else
		puts("2");
}