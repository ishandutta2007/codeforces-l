#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void rd(long long &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template <class T> struct DijkstraHeap{
  int*hp;
  int*place;
  int size;
  char*visited;
  T*val;
  void malloc(int N){
    hp = (int*)std::malloc(N*sizeof(int));
    place = (int*)std::malloc(N*sizeof(int));
    visited = (char*)std::malloc(N*sizeof(char));
    val = (T*)std::malloc(N*sizeof(T));
  }
  void free(){
    std::free(hp);
    std::free(place);
    std::free(visited);
    std::free(val);
  }
  void walloc(int N, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&visited, N, mem);
    walloc1d(&val, N, mem);
  }
  void init(int N){
    int i;
    size = 0;
    for(i=(0);i<(N);i++){
      place[i]=-1;
    }
    for(i=(0);i<(N);i++){
      visited[i]=0;
    }
  }
  void up(int n){
    int m;
    while(n){
      m=(n-1)/2;
      if(val[hp[m]]<=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void down(int n){
    int m;
    for(;;){
      m=2*n+1;
      if(m>=size){
        break;
      }
      if(m+1<size&&val[hp[m]]>val[hp[m+1]]){
        m++;
      }
      if(val[hp[m]]>=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void change(int n, T v){
    if(visited[n]||(place[n]>=0&&val[n]<=v)){
      return;
    }
    val[n]=v;
    if(place[n]==-1){
      place[n]=size;
      hp[size++]=n;
      up(place[n]);
    }
    else{
      up(place[n]);
    }
  }
  int pop(void){
    int res=hp[0];
    place[res]=-1;
    size--;
    if(size){
      hp[0]=hp[size];
      place[hp[0]]=0;
      down(0);
    }
    visited[res]=1;
    return res;
  }
}
;
struct graph{
  int N;
  int*es;
  int**edge;
  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
  }
}
;
template<class T> struct wgraph{
  int N;
  int*es;
  int**edge;
  T**cost;
  graph g;
  void setEdge(int N__, int M, int A[], int B[], T C[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    walloc1d(&cost, N, mem);
    for(i=(0);i<(N);i++){
      walloc1d(&cost[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]] = B[i];
      edge[B[i]][es[B[i]]] = A[i];
      cost[A[i]][es[A[i]]++] = C[i];
      cost[B[i]][es[B[i]]++] = C[i];
    }
    g.N = N;
    g.es = es;
    g.edge = edge;
  }
}
;
struct dimcomp3{
  int B;
  int C;
  dimcomp3(){
  }
  ;
  dimcomp3(int b, int c){
    B = b;
    C = c;
  }
  dimcomp3(int a, int b, int c){
    B = b;
    C = c;
  }
  inline void set(int b, int c){
    B = b;
    C = c;
  }
  inline void set(int a, int b, int c){
    B = b;
    C = c;
  }
  inline int mask(int a, int b, int c){
    return (a * B + b) * C + c;
  }
  inline int operator()(int a, int b, int c){
    return (a * B + b) * C + c;
  }
  inline void para(int mask, int &a, int &b, int &c){
    a = mask / (B*C);
    b = mask % (B*C) / C;
    c = mask % C;
  }
  inline void operator()(int mask, int &a, int &b, int &c){
    a = mask / (B*C);
    b = mask % (B*C) / C;
    c = mask % C;
  }
}
;
int N;
int M;
int A[200000];
int B[200000];
long long C[200000];
wgraph<long long> g;
long long res[200000];
int main(){
  wmem = memarr;
  int f1;
  int f2;
  int i;
  int j;
  int k;
  int mask;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
      rd(B[Lj4PdHRW]);B[Lj4PdHRW] += (-1);
      rd(C[Lj4PdHRW]);
    }
  }
  g.setEdge(N,M,A,B,C);
  dimcomp3 dm(2,2,N);
  DijkstraHeap<long long> hp;
  hp.walloc(4*N);
  hp.init(4*N);
  for(i=(0);i<(N);i++){
    res[i] = 4611686016279904256LL;
  }
  hp.change(0,0);
  while(hp.size){
    mask = hp.pop();
    dm(mask, f1, f2, i);
    if(f1==f2 && i > 0){
      chmin(res[i-1], hp.val[mask]);
    }
    for(j=(0);j<(g.es[i]);j++){
      k = g.edge[i][j];
      hp.change(dm(f1,f2,k), hp.val[mask]+g.cost[i][j]);
      if(f1==0){
        hp.change(dm(1,f2,k), hp.val[mask]);
      }
      if(f2==0){
        hp.change(dm(f1,1,k), hp.val[mask]+2*g.cost[i][j]);
      }
    }
  }
  {
    int t_ynMSdg;
    if(N-1==0){
      wt_L('\n');
    }
    else{
      for(t_ynMSdg=(0);t_ynMSdg<(N-1-1);t_ynMSdg++){
        wt_L(res[t_ynMSdg]);
        wt_L(' ');
      }
      wt_L(res[t_ynMSdg]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int N, M, A[2d5], B[]; ll C[];
// wgraph<ll> g;
// ll res[];
// {
//   int f1, f2, i, j, k, mask;
//   rd(N,M,(A--,B--,C)(M));
//   g.setEdge(N,M,A,B,C);
// 
//   dimcomp3 dm(2,2,N);
//   DijkstraHeap<ll> hp;
// 
//   hp.walloc(4*N);
//   hp.init(4*N);
//   rep(i,N) res[i] = ll_inf;
// 
//   hp.change(0,0);
//   while(hp.size){
//     mask = hp.pop();
//     dm(mask, f1, f2, i);
//     if(f1==f2 && i > 0) res[i-1] <?= hp.val[mask];
//     rep(j,g.es[i]){
//       k = g.edge[i][j];
//       hp.change(dm(f1,f2,k), hp.val[mask]+g.cost[i][j]);
//       if(f1==0) hp.change(dm(1,f2,k), hp.val[mask]);
//       if(f2==0) hp.change(dm(f1,1,k), hp.val[mask]+2*g.cost[i][j]);
//     }
//   }
// 
//   wt(res(N-1));
// }