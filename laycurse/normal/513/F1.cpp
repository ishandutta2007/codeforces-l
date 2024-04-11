#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(double *x){scanf("%lf",x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(double x, char c){printf("%.15f",x);mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

template<class T, class S>
struct maxflow{
  int node, st, ed, *es, *emem, **edge, **rev, *level, *queue;
  T **flow, eps;

  void malloc(int N){int i;es=(int*)std::malloc(N*sizeof(int));emem=(int*)std::malloc(N*sizeof(int));level=(int*)std::malloc(N*sizeof(int));queue=(int*)std::malloc(N*sizeof(int));edge=(int**)std::malloc(N*sizeof(int*));rev=(int**)std::malloc(N*sizeof(int*));flow=(T**)std::malloc(N*sizeof(T*));rep(i,N)emem[i]=0,edge[i]=rev[i]=NULL,flow[i]=NULL;}
  void* malloc(int N, void* mem){int i;es=(int*)mem;emem=es+N;level=emem+N;queue=level+N;edge=(int**)(queue+N);rev=edge+N;flow=(T**)(rev+N);rep(i,N)emem[i]=0,edge[i]=rev[i]=NULL,flow[i]=NULL;return(void*)(flow+N);}
  void levelize(void){int i,j,k,t,s=0,e=1;rep(i,node)level[i]=-1;level[st]=0;queue[0]=st;while(s!=e){i=queue[s++];t=level[i]+1;rep(j,es[i])if(flow[i][j]>eps){k=edge[i][j];if(level[k]!=-1)continue;level[k]=t;queue[e++]=k;if(k==ed)return;}}}
  S pushflow(int i, S lim){int j,k,l;S s,t,r=0;if(i==ed)return lim;rep(j,es[i])if(flow[i][j]>eps){k=edge[i][j];if(level[k]!=level[i]+1) continue;s=min(lim,(S)flow[i][j]);t=pushflow(k,s);if(!t) continue;r+=t;lim-=t;l=rev[i][j];flow[i][j]-=t;flow[k][l]+=t;if(!lim)break;}if(lim)level[i]=-1;return r;}
  S solve(int st_, int ed_){S r=0;st=st_;ed=ed_;for(;;){levelize();if(level[ed]==-1)break;r+=pushflow(st,numeric_limits<S>::max());}return r;}
  void init(int N){int i;node=N;rep(i,N)es[i]=0;eps=(T)1e-9;}
  void memoryExpand(int i, int sz){if(sz<=emem[i])return;sz=max(sz,max(3,emem[i]*2));emem[i]=sz;edge[i]=(int*)realloc(edge[i],sz*sizeof(int));rev[i]=(int*)realloc(rev[i],sz*sizeof(int));flow[i]=(T*)realloc(flow[i],sz*sizeof(T));}
  void addEdge(int n1, int n2, T f1, T f2){int s1=es[n1]++,s2=es[n2]++;if(s1>=emem[n1])memoryExpand(n1,es[n1]);if(s2>=emem[n2])memoryExpand(n2,es[n2]);edge[n1][s1]=n2;edge[n2][s2]=n1;flow[n1][s1]=f1;flow[n2][s2]=f2;rev[n1][s1]=s2;rev[n2][s2]=s1;}
  void addEdgeAdv(int n1, int n2, T f1, T f2){int s1=es[n1]++,s2=es[n2]++;edge[n1][s1]=n2;edge[n2][s2]=n1;flow[n1][s1]=f1;flow[n2][s2]=f2;rev[n1][s1]=s2;rev[n2][s2]=s1;}
  void setGraph(int N, int M, int n1[], int n2[], int f1[], int f2[]){int i;node=N;rep(i,N)es[i]=0;rep(i,M)es[n1[i]]++,es[n2[i]]++;rep(i,N)memoryExpand(i,es[i]);rep(i,N)es[i]=0;rep(i,M)addEdgeAdv(n1[i],n2[i],f1[i],f2[i]);eps=(T)1e-9;}
  void* setGraph(int N, int M, int n1[], int n2[], T f1[], T f2[], void *mem){int i,j,k;node=N;rep(i,N)es[i]=emem[i]=0;rep(i,M)es[n1[i]]++,es[n2[i]]++;edge[0]=(int*)mem;REP(i,1,N)edge[i]=edge[i-1]+es[i-1];rev[0]=edge[N-1]+es[N-1];REP(i,1,N)rev[i]=rev[i-1]+es[i-1];flow[0]=(T*)(rev[N-1]+es[N-1]);REP(i,1,N)flow[i]=flow[i-1]+es[i-1];mem=(void*)(flow[N-1]+es[N-1]);rep(i,N)es[i]=0;rep(i,M)addEdgeAdv(n1[i],n2[i],f1[i],f2[i]);eps=(T)1e-9;return mem;}
};

char memarr[17000000]; void *mem = memarr;
#define MD 1000000007

int X, Y, XY;
char mp[32][32];
int dist[544][544];

int M, F;
int mx[1000], my[1000], mt[1000], mxy[1000];
int fx[1000], fy[1000], ft[1000], fxy[1000];

template<class T> void unique(T arr[], int &sz, int sorted=0){int i,k=0;if(!sorted)sort(arr,arr+sz);rep(i,sz)if(!k||arr[k-1]!=arr[i])arr[k++]=arr[i];sz=k;}

ll val[11000000]; int sz;

int main(){
  int i, j, k;
  int bx, by, bt;
  int node, st, ed;
  ll A, B, C, CC;
  maxflow<int,int> flow;

  reader(&X,&Y,&M,&F); XY = X*Y;
  if(!(M+1==F || M==F+1)){ writerLn(-1); return 0; }

  rep(i,X) reader(mp[i]);

  reader(&bx, &by, &bt);
  rep(i,M) reader(mx+i,my+i,mt+i);
  rep(i,F) reader(fx+i,fy+i,ft+i);
  if(M<F) mx[M]=bx, my[M]=by, mt[M]=bt, M++;
  else    fx[F]=bx, fy[F]=by, ft[F]=bt, F++;

  rep(i,XY) rep(j,XY) dist[i][j] = 1000000000;
  rep(i,XY) dist[i][i] = 0;
  rep(i,X) rep(j,Y) if(mp[i][j]=='.'){
    if(i && mp[i-1][j]=='.'){
      dist[i*Y+j][(i-1)*Y+j] = 1;
      dist[(i-1)*Y+j][i*Y+j] = 1;
    }
    if(j && mp[i][j-1]=='.'){
      dist[i*Y+j][i*Y+(j-1)] = 1;
      dist[i*Y+(j-1)][i*Y+j] = 1;
    }
  }
  rep(k,XY) rep(i,XY) REP(j,i,XY) dist[j][i] = dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

  node = M+F+XY+XY;
  st = node++;
  ed = node++;
  flow.malloc(node);

  rep(i,M) mxy[i] = (mx[i]-1)*Y+(my[i]-1);
  rep(i,F) fxy[i] = (fx[i]-1)*Y+(fy[i]-1);

  sz = 0;
  rep(i,M) rep(j,XY){
    k = dist[mxy[i]][j];
    if(k==1000000000) continue;
    val[sz++] = (ll)k * mt[i];
  }
  rep(i,M) rep(j,XY){
    k = dist[fxy[i]][j];
    if(k==1000000000) continue;
    val[sz++] = (ll)k * ft[i];
  }
  val[sz++] = 100000000000000000LL;
  unique(val, sz);

  A = 0;
  B = sz-1;
  while(A < B){
    C = (A+B) / 2;
    CC = val[C];
    
    flow.init(node);
    rep(i,M) flow.addEdge(st,i,1,0);
    rep(i,M) flow.addEdge(M+XY+XY+i,ed,1,0);
    rep(i,XY) flow.addEdge(M+i,M+XY+i,1,0);
    rep(i,M) rep(j,XY){
      k = dist[mxy[i]][j];
      if(k==1000000000) continue;
      if((ll)k*mt[i] > CC) continue;
      flow.addEdge(i,M+j,1,0);
    }
    rep(i,M) rep(j,XY){
      k = dist[fxy[i]][j];
      if(k==1000000000) continue;
      if((ll)k*ft[i] > CC) continue;
      flow.addEdge(M+XY+j,M+XY+XY+i,1,0);
    }
    k = flow.solve(st,ed);
    if(k==M) B=C; else A=C+1;
  }

  A = val[A];
  if(A >= 100000000000000000LL) A = -1;
  writerLn(A);

  return 0;
}