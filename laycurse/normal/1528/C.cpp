#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
template <class S, class T> struct cLtraits_common_type{
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS,tT>::type;
}
;
void*wmem;
char memarr[96000000];
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> struct fenwick{
  int size;
  int memory;
  T*data;
  void malloc(int mem);
  void malloc(int mem, int fg);
  void walloc(int mem, void **workMemory = &wmem);
  void walloc(int mem, int fg, void **workMemory = &wmem);
  void free(void);
  void init(int N);
  void add(int k, T val);
  T get(int k);
  T range(int a, int b);
  int kth(T k);
}
;
template<class T> struct segtree{
  int N;
  int logN;
  T*sum;
  T*mn;
  int*mnind;
  T*fixval;
  char*fixed;
  T*addval;
  void malloc(int maxN, int once = 0){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    sum = new T[2*i];
    mn = new T[2*i];
    mnind = new int[2*i];
    fixval = new T[i];
    addval = new T[i];
    fixed = new char[i];
    if(once){
      setN(maxN);
    }
  }
  void walloc(int maxN, int once = 0, void **mem = &wmem){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    walloc1d(&sum, 2*i, mem);
    walloc1d(&mn, 2*i, mem);
    walloc1d(&mnind, 2*i, mem);
    walloc1d(&fixval, i, mem);
    walloc1d(&addval, i, mem);
    walloc1d(&fixed, i, mem);
    if(once){
      setN(maxN);
    }
  }
  void free(void){
    delete [] sum;
    delete [] mn;
    delete [] mnind;
    delete [] fixval;
    delete [] addval;
    delete [] fixed;
  }
  T& operator[](int i){
    return sum[N+i];
  }
  void setN(int n, int zerofill = 1, int dobuild = 1){
    int i;
    for(i=1,logN=0;i<n;i*=2,logN++){
      ;
    }
    N = i;
    if(zerofill){
      for(i=(0);i<(N);i++){
        sum[N+i] = 0;
      }
    }
    if(dobuild){
      build();
    }
  }
  void build(void){
    int i;
    for(i=(0);i<(N);i++){
      mn[N+i] = sum[N+i];
      mnind[N+i] = i;
    }
    for(i=N-1;i;i--){
      sum[i] = sum[2*i] + sum[2*i+1];
      if(mn[2*i] <= mn[2*i+1]){
        mn[i] = mn[2*i];
        mnind[i] = mnind[2*i];
      }
      else{
        mn[i] = mn[2*i+1];
        mnind[i] = mnind[2*i+1];
      }
    }
    int O3U4gd88 = N;
    for(i=(1);i<(O3U4gd88);i++){
      fixed[i] = 0;
    }
    int OC5CYxKD = N;
    for(i=(1);i<(OC5CYxKD);i++){
      addval[i] = 0;
    }
  }
  inline void push_one(int a, int sz, int st){
    if(fixed[a]){
      if(sz > 1){
        fixed[a*2] = fixed[a*2+1] = 1;
        fixval[a*2] = fixval[a*2+1] = fixval[a];
        sum[a*2] = sum[a*2+1] = sz * fixval[a];
        mn[a*2] = mn[a*2+1] = fixval[a];
        mnind[a*2] = st;
        mnind[a*2+1] = st + sz;
      }
      else{
        sum[a*2] = sum[a*2+1] = sz * fixval[a];
        mn[a*2] = mn[a*2+1] = fixval[a];
        mnind[a*2] = st;
        mnind[a*2+1] = st + sz;
      }
      fixed[a] = 0;
      addval[a] = 0;
      return;
    }
    if(addval[a] != 0){
      if(sz > 1){
        if(fixed[a*2]){
          fixval[a*2] += addval[a];
        }
        else{
          addval[a*2] += addval[a];
        }
        if(fixed[a*2+1]){
          fixval[a*2+1] += addval[a];
        }
        else{
          addval[a*2+1] += addval[a];
        }
        sum[a*2] += sz * addval[a];
        sum[a*2+1] += sz * addval[a];
        mn[a*2] += addval[a];
        mn[a*2+1] += addval[a];
      }
      else{
        sum[a*2] += sz * addval[a];
        sum[a*2+1] += sz * addval[a];
        mn[a*2] += addval[a];
        mn[a*2+1] += addval[a];
      }
      addval[a] = 0;
      return;
    }
  }
  inline void push(int a){
    int i;
    int aa = a - N;
    int nd;
    int sz;
    int st;
    for(i=logN;i;i--){
      nd = a>>i;
      sz = 1<<(i-1);
      st = 2 * sz * (aa>>i);
      push_one(nd, sz, st);
    }
  }
  inline void build(int a){
    int sz = 1;
    int st = a - N;
    while(a > 1){
      if(a%2){
        st += sz;
      }
      a /= 2;
      sz *= 2;
      if(fixed[a]){
        sum[a] = sz * fixval[a];
        mn[a] = fixval[a];
      }
      else{
        sum[a] = sum[a*2] + sum[a*2+1];
        if(mn[a*2] <= mn[a*2+1]){
          mn[a] = mn[a*2];
          mnind[a] = mnind[a*2];
        }
        else{
          mn[a] = mn[a*2+1];
          mnind[a] = mnind[a*2+1];
        }
        if(addval[a] != 0){
          mn[a] += addval[a];
          sum[a] += sz * addval[a];
        }
      }
    }
  }
  inline void change(int a, int b, T val){
    int sz = 1;
    int aa;
    int bb;
    int st_a = a;
    int st_b = b;
    if(a >= b){
      return;
    }
    aa = (a += N);
    bb = (b += N);
    push(a);
    push(b-1);
    if(a%2){
      sum[a] = mn[a] = val;
      a++;
      st_a += sz;
    }
    if(b%2){
      b--;
      st_b -= sz;
      sum[b] = mn[b] = val;
    }
    a /= 2;
    b /= 2;
    while(a < b){
      sz *= 2;
      if(a%2){
        fixed[a]=1;
        fixval[a]=val;
        sum[a] = sz * val;
        mn[a] = val;
        mnind[a] = st_a;
        a++;
        st_a += sz;
      }
      if(b%2){
        b--;
        st_b -= sz;
        fixed[b]=1;
        fixval[b]=val;
        sum[b] = sz * val;
        mn[b] = val;
        mnind[b] = st_b;
      }
      a /= 2;
      b /= 2;
    }
    build(aa);
    build(bb-1);
  }
  inline void add(int a, int b, T val){
    int sz = 1;
    int aa;
    int bb;
    if(a >= b){
      return;
    }
    aa = (a += N);
    bb = (b += N);
    push(a);
    push(b-1);
    if(a%2){
      sum[a] += val;
      mn[a] += val;
      a++;
    }
    if(b%2){
      b--;
      sum[b] += val;
      mn[b] += val;
    }
    a /= 2;
    b /= 2;
    while(a < b){
      sz *= 2;
      if(a%2){
        if(fixed[a]){
          fixval[a] += val;
        }
        else{
          addval[a] += val;
        }
        sum[a] += sz * val;
        mn[a] += val;
        a++;
      }
      if(b%2){
        b--;
        if(fixed[b]){
          fixval[b] += val;
        }
        else{
          addval[b] += val;
        }
        sum[b] += sz * val;
        mn[b] += val;
      }
      a /= 2;
      b /= 2;
    }
    build(aa);
    build(bb-1);
  }
  inline pair<T,int> getMin(int a, int b){
    pair<T,int> res;
    pair<T,int> tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    push(a);
    push(b-1);
    while(a < b){
      if(a%2){
        if(fga){
          res =min_L(res, make_pair(mn[a], mnind[a]));
        }
        else{
          res = make_pair(mn[a], mnind[a]);
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp =min_L(make_pair(mn[b], mnind[b]), tmp);
        }
        else{
          tmp = make_pair(mn[b], mnind[b]);
          fgb = 1;
        }
      }
      a /= 2;
      b /= 2;
    }
    if(fga==1 && fgb==0){
      return res;
    }
    if(fga==0 && fgb==1){
      return tmp;
    }
    if(fga==1 && fgb==1){
      res =min_L(res, tmp);
      return res;
    }
    return res;
  }
  inline T getMinVal(int a, int b){
    T res;
    T tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    push(a);
    push(b-1);
    while(a < b){
      if(a%2){
        if(fga){
          res =min_L(res, mn[a]);
        }
        else{
          res = mn[a];
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp =min_L(mn[b], tmp);
        }
        else{
          tmp = mn[b];
          fgb = 1;
        }
      }
      a /= 2;
      b /= 2;
    }
    if(fga==1 && fgb==0){
      return res;
    }
    if(fga==0 && fgb==1){
      return tmp;
    }
    if(fga==1 && fgb==1){
      res =min_L(res, tmp);
      return res;
    }
    return res;
  }
  inline int getMinInd(int a, int b){
    return getMin(a,b).second;
  }
  inline T getSum(int a, int b){
    T res;
    T tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    push(a);
    push(b-1);
    while(a < b){
      if(a%2){
        if(fga){
          res = res + sum[a];
        }
        else{
          res = sum[a];
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp = sum[b] + tmp;
        }
        else{
          tmp = sum[b];
          fgb = 1;
        }
      }
      a /= 2;
      b /= 2;
    }
    if(fga==1 && fgb==0){
      return res;
    }
    if(fga==0 && fgb==1){
      return tmp;
    }
    if(fga==1 && fgb==1){
      res = res + tmp;
      return res;
    }
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
  void setEdgeRootedTree(int N__, int M, int A[], int B[], int root=0, int reorder=0, int cnv[] = NULL, void **mem = &wmem){
    int i;
    int j;
    int k;
    int*dist;
    int*q;
    int qs;
    int qe;
    int*ind;
    void*tmem;
    N = N__;
    tmem = ((char*)(*mem)) + (sizeof(int) * N + 15) + (sizeof(int*) * N + 15) + (sizeof(int) * M + 15 * N);
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
      walloc1d(&edge[i], es[i], &tmem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
    walloc1d(&dist, N, &tmem);
    walloc1d(&q, N, &tmem);
    walloc1d(&ind, N, &tmem);
    if(cnv==NULL){
      walloc1d(&cnv, N, &tmem);
    }
    for(i=(0);i<(N);i++){
      dist[i] = -1;
    }
    dist[root] = 0;
    qs = qe = 0;
    q[qe++] = root;
    while(qs < qe){
      i = q[qs++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(dist[k]==-1){
          dist[k] = dist[i] + 1;
          q[qe++] = k;
        }
      }
    }
    if(reorder == 0){
      for(i=(0);i<(N);i++){
        cnv[i] = i;
      }
      for(i=(0);i<(N);i++){
        ind[i] = i;
      }
    }
    else{
      for(i=(0);i<(N);i++){
        cnv[i] = q[i];
      }
      for(i=(0);i<(N);i++){
        ind[cnv[i]] = i;
      }
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i];
      k = B[i];
      if(dist[j] > dist[k]){
        swap(j, k);
      }
      es[ind[j]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i];
      k = B[i];
      if(dist[j] > dist[k]){
        swap(j, k);
      }
      j = ind[j];
      k = ind[k];
      edge[j][es[j]++] = k;
    }
  }
}
;
struct HLD{
  int N;
  int*es;
  int**edge;
  int*group;
  int*groupind;
  int groupNum;
  int*groupSize;
  int**groupNode;
  int*groupUpNode;
  int*groupDepth;
  void init(graph g, void **mem = &wmem){
    init(g.N, g.es, g.edge, mem);
  }
  void init(int N__, int *es__, int **edge__, void **mem = &wmem){
    int i;
    int j;
    int k;
    int x;
    int y;
    int mx;
    int*q;
    int q_st;
    int q_ed;
    int*sz;
    char*vis;
    void*tmpmem;
    N = N__;
    es = es__;
    edge = edge__;
    walloc1d(&group, N, mem);
    walloc1d(&groupind, N, mem);
    tmpmem = *mem;
    walloc1d(&q, N, &tmpmem);
    walloc1d(&sz, N, &tmpmem);
    walloc1d(&vis, N, &tmpmem);
    for(i=(0);i<(N);i++){
      vis[i] = 0;
    }
    q_st = 0;
    q_ed = 1;
    q[0] = 0;
    vis[0] = 1;
    while(q_st < q_ed){
      i = q[q_st++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(!vis[k]){
          vis[k] = 1;
          q[q_ed++] = k;
        }
      }
    }
    for(i=(0);i<(N);i++){
      sz[i] = 0;
    }
    for(j=N-1;j>=0;j--){
      i = q[j];
      sz[i] = 1;
      for(k=(0);k<(es[i]);k++){
        sz[i] += sz[edge[i][k]];
      }
    }
    for(i=(0);i<(N);i++){
      group[i] = -1;
    }
    groupNum = 0;
    for(j=(0);j<(N);j++){
      i = q[j];
      if(group[i]>=0){
        continue;
      }
      group[i] = groupNum++;
      groupind[i] = 0;
      for(;;){
        mx = -1;
        for(k=(0);k<(es[i]);k++){
          if(group[edge[i][k]] != -1){
            continue;
          }
          if(mx==-1){
            mx = k;
          }
          else if(sz[edge[i][k]] > sz[edge[i][mx]]){
            mx = k;
          }
        }
        if(mx==-1){
          break;
        }
        group[edge[i][mx]] = group[i];
        groupind[edge[i][mx]] = groupind[i]+1;
        i = edge[i][mx];
      }
    }
    walloc1d(&groupSize, groupNum, mem);
    walloc1d(&groupUpNode, groupNum, mem);
    walloc1d(&groupDepth, groupNum, mem);
    for(i=(0);i<(groupNum);i++){
      groupSize[i] = 0;
    }
    for(i=(0);i<(N);i++){
      groupSize[group[i]]++;
    }
    walloc1d(&groupNode, groupNum, mem);
    for(i=(0);i<(groupNum);i++){
      walloc1d(&groupNode[i], groupSize[i], mem);
    }
    for(i=(0);i<(N);i++){
      groupNode[group[i]][groupind[i]] = i;
    }
    for(i=(0);i<(groupNum);i++){
      groupDepth[i] = -1;
    }
    groupUpNode[0] = -1;
    groupDepth[0] = 0;
    for(x=(0);x<(groupNum);x++){
      for(y=(0);y<(groupSize[x]);y++){
        i = groupNode[x][y];
        for(j=(0);j<(es[i]);j++){
          k = edge[i][j];
          if(x != group[k] && groupDepth[group[k]]==-1){
            groupUpNode[group[k]] = i;
            groupDepth[group[k]] = groupDepth[x] + 1;
          }
        }
      }
    }
  }
  int lca(int x, int y){
    int x1;
    int y1;
    int x2;
    int y2;
    x1 = group[x];
    x2 = groupind[x];
    y1 = group[y];
    y2 = groupind[y];
    while(groupDepth[x1] > groupDepth[y1]){
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
    }
    while(groupDepth[x1] < groupDepth[y1]){
      y = groupUpNode[y1];
      y1 = group[y];
      y2 = groupind[y];
    }
    while(x1 != y1){
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
      y = groupUpNode[y1];
      y1 = group[y];
      y2 = groupind[y];
    }
    if(x2 <= y2){
      return x;
    }
    return y;
  }
  int depth(int x){
    int x1;
    int x2;
    int res = 0;
    x1 = group[x];
    x2 = groupind[x];
    while(groupUpNode[x1] != -1){
      res += x2 + 1;
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
    }
    return res + x2;
  }
  int dist(int x, int y){
    int x1;
    int y1;
    int x2;
    int y2;
    int res = 0;
    x1 = group[x];
    x2 = groupind[x];
    y1 = group[y];
    y2 = groupind[y];
    while(groupDepth[x1] > groupDepth[y1]){
      res += x2 + 1;
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
    }
    while(groupDepth[x1] < groupDepth[y1]){
      res += y2 + 1;
      y = groupUpNode[y1];
      y1 = group[y];
      y2 = groupind[y];
    }
    while(x1 != y1){
      res += x2 + y2 + 2;
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
      y = groupUpNode[y1];
      y1 = group[y];
      y2 = groupind[y];
    }
    if(x2 <= y2){
      return res + y2 - x2;
    }
    return res + x2 - y2;
  }
  int up(int x){
    int x1 = group[x];
    int x2 = groupind[x];
    if(x2==0){
      return groupUpNode[x1];
    }
    return groupNode[x1][x2-1];
  }
  int up(int x, int d){
    int x1 = group[x];
    int x2 = groupind[x];
    while(d > x2){
      if(groupUpNode[x1]==-1){
        return -1;
      }
      d -= x2 + 1;
      x = groupUpNode[x1];
      x1 = group[x];
      x2 = groupind[x];
    }
    return groupNode[x1][x2-d];
  }
}
;
template<class T> struct HLD_fenwick{
  HLD*hld;
  fenwick<T>*fen;
  void init(HLD *hld__, void **mem = &wmem){
    int i;
    int j;
    hld = hld__;
    walloc1d(&fen, hld->groupNum, mem);
    for(i=(0);i<(hld->groupNum);i++){
      fen[i].walloc(hld->groupSize[i], mem);
      fen[i].init(hld->groupSize[i]);
    }
  }
  inline void add(int u, T val){
    int ug;
    int ui;
    ug = hld->group[u];
    ui = hld->groupind[u];
    fen[ug].add(ui, val);
  }
  inline T get(int u, int v){
    T res;
    int ug;
    int vg;
    int ui;
    int vi;
    ug = hld->group[u];
    vg = hld->group[v];
    res = 0;
    while(ug != vg){
      if(hld->groupDepth[ug] < hld->groupDepth[vg]){
        swap(u, v);
        swap(ug, vg);
      }
      res += fen[ug].get(hld->groupind[u]);
      u = hld->groupUpNode[ug];
      ug = hld->group[u];
    }
    ui = hld->groupind[u];
    vi = hld->groupind[v];
    res += fen[ug].range(min_L(ui, vi),max_L(ui, vi));
    return res;
  }
}
;
template<class T> struct HLD_segtree{
  HLD*hld;
  segtree<T>*seg;
  void init(HLD *hld__, T initval[], void **mem = &wmem){
    int i;
    int j;
    hld = hld__;
    walloc1d(&seg, hld->groupNum, mem);
    for(i=(0);i<(hld->groupNum);i++){
      seg[i].walloc(hld->groupSize[i], 0, mem);
      seg[i].setN(hld->groupSize[i], 0, 0);
      if(initval!=NULL){
        for(j=(0);j<(hld->groupSize[i]);j++){
          seg[i][j] = initval[ hld->groupNode[i][j] ];
        }
      }
      else{
        for(j=(0);j<(hld->groupSize[i]);j++){
          seg[i][j] = 0;
        }
      }
      seg[i].build();
    }
  }
  inline void change(int u, int v, T val){
    int ug;
    int vg;
    int ui;
    int vi;
    ug = hld->group[u];
    vg = hld->group[v];
    while(ug != vg){
      if(hld->groupDepth[ug] < hld->groupDepth[vg]){
        swap(u, v);
        swap(ug, vg);
      }
      seg[ug].change(0, hld->groupind[u]+1, val);
      u = hld->groupUpNode[ug];
      ug = hld->group[u];
    }
    ui = hld->groupind[u];
    vi = hld->groupind[v];
    seg[ug].change(min_L(ui, vi),max_L(ui, vi)+1, val);
  }
  inline void add(int u, int v, T val){
    int ug;
    int vg;
    int ui;
    int vi;
    ug = hld->group[u];
    vg = hld->group[v];
    while(ug != vg){
      if(hld->groupDepth[ug] < hld->groupDepth[vg]){
        swap(u, v);
        swap(ug, vg);
      }
      seg[ug].add(0, hld->groupind[u]+1, val);
      u = hld->groupUpNode[ug];
      ug = hld->group[u];
    }
    ui = hld->groupind[u];
    vi = hld->groupind[v];
    seg[ug].add(min_L(ui, vi),max_L(ui, vi)+1, val);
  }
  inline pair<T,int> getMin(int u, int v){
    pair<T,int> res;
    pair<T,int> tmp;
    int ug;
    int vg;
    int ui;
    int vi;
    ug = hld->group[u];
    vg = hld->group[v];
    res.first = numeric_limits<T>::max();
    res.second = -1;
    while(ug != vg){
      if(hld->groupDepth[ug] < hld->groupDepth[vg]){
        swap(u, v);
        swap(ug, vg);
      }
      tmp = seg[ug].getMin(0, hld->groupind[u]+1);
      tmp.second = hld->groupNode[ug][tmp.second];
      chmin(res, tmp);
      u = hld->groupUpNode[ug];
      ug = hld->group[u];
    }
    ui = hld->groupind[u];
    vi = hld->groupind[v];
    tmp = seg[ug].getMin(min_L(ui, vi),max_L(ui, vi)+1);
    tmp.second = hld->groupNode[ug][tmp.second];
    chmin(res, tmp);
    return res;
  }
  inline T getMinVal(int u, int v){
    return getMin(u,v).first;
  }
  inline int getMinInd(int u, int v){
    return getMin(u,v).second;
  }
  inline T getSum(int u, int v){
    T res;
    int ug;
    int vg;
    int ui;
    int vi;
    ug = hld->group[u];
    vg = hld->group[v];
    res = 0;
    while(ug != vg){
      if(hld->groupDepth[ug] < hld->groupDepth[vg]){
        swap(u, v);
        swap(ug, vg);
      }
      res += seg[ug].getSum(0, hld->groupind[u]+1);
      u = hld->groupUpNode[ug];
      ug = hld->group[u];
    }
    ui = hld->groupind[u];
    vi = hld->groupind[v];
    res += seg[ug].getSum(min_L(ui, vi),max_L(ui, vi)+1);
    return res;
  }
  inline void change_edge(int u, int v, T val){
    int x;
    int z;
    int d;
    z = hld->lca(u, v);
    d = hld->depth(z);
    if(z != u){
      x = hld->up(u, hld->depth(u) - d - 1);
      change(u, x, val);
    }
    if(z != v){
      x = hld->up(v, hld->depth(v) - d - 1);
      change(v, x, val);
    }
  }
  inline void add_edge(int u, int v, T val){
    int x;
    int z;
    int d;
    z = hld->lca(u, v);
    d = hld->depth(z);
    if(z != u){
      x = hld->up(u, hld->depth(u) - d - 1);
      add(u, x, val);
    }
    if(z != v){
      x = hld->up(v, hld->depth(v) - d - 1);
      add(v, x, val);
    }
  }
  inline pair<T,int> getMin_edge(int u, int v){
    int x;
    int z;
    int d;
    pair<T,int> res;
    pair<T,int> tmp;
    res.first = numeric_limits<T>::max();
    res.second = -1;
    z = hld->lca(u, v);
    d = hld->depth(z);
    if(z != u){
      x = hld->up(u, hld->depth(u) - d - 1);
      tmp = getMin(u, x);
      chmin(res, tmp);
    }
    if(z != v){
      x = hld->up(v, hld->depth(v) - d - 1);
      tmp = getMin(v, x);
      chmin(res, tmp);
    }
    return res;
  }
  inline T getMinVal_edge(int u, int v){
    return getMin_edge(u,v).first;
  }
  inline int getMinInd_edge(int u, int v){
    return getMin_edge(u,v).second;
  }
  inline T getSum_edge(int u, int v){
    int x;
    int z;
    int d;
    T res;
    res = 0;
    z = hld->lca(u, v);
    d = hld->depth(z);
    if(z != u){
      x = hld->up(u, hld->depth(u) - d - 1);
      res += getSum(u, x);
    }
    if(z != v){
      x = hld->up(v, hld->depth(v) - d - 1);
      res += getSum(v, x);
    }
    return res;
  }
}
;
int N;
int a1[300000];
int b1[300000];
int a2[300000];
int b2[300000];
graph g;
graph g2;
HLD hld;
HLD_fenwick<int> f;
HLD_segtree<int> t;
int res;
void dfs(int n, int s){
  int RZTsC2BF;
  int ad = -1;
  int dl = -1;
  int x;
  int y;
  int d;
  if(t.getSum(n,n) == 0){
    ad = n;
    if(f.get(0,n) != 0){
      d = hld.depth(n);
      int Lj4PdHRW;
      int KL2GvlyY;
      int Q5VJL1cS;
      Lj4PdHRW = 0;
      KL2GvlyY = d;
      while(Lj4PdHRW < KL2GvlyY){
        if((Lj4PdHRW + KL2GvlyY)%2==0){
          Q5VJL1cS = (Lj4PdHRW + KL2GvlyY) / 2;
        }
        else{
          Q5VJL1cS = (Lj4PdHRW + KL2GvlyY - 1) / 2;
        }
        y = hld.up(n,Q5VJL1cS);
        if(f.get(y,n) != 0){
          KL2GvlyY = Q5VJL1cS;
        }
        else{
          Lj4PdHRW = Q5VJL1cS + 1;
        }
      }
      x =KL2GvlyY;
      dl = hld.up(n,x);
    }
  }
  if(ad >= 0){
    f.add(ad, 1);
    t.add(0, ad, 1);
    s++;
  }
  if(dl >= 0){
    f.add(dl, -1);
    t.add(0, dl, -1);
    s--;
  }
  chmax(res, s);
  for(RZTsC2BF=(0);RZTsC2BF<(g.es[n]);RZTsC2BF++){
    auto&i = g.edge[n][RZTsC2BF];
    dfs(i,s);
  }
  if(ad >= 0){
    f.add(ad, -1);
    t.add(0, ad, -1);
    s--;
  }
  if(dl >= 0){
    f.add(dl, 1);
    t.add(0, dl, 1);
    s++;
  }
}
int main(){
  int WYIGIcGE;
  wmem = memarr;
  int t_ynMSdg = rd_int();
  for(WYIGIcGE=(0);WYIGIcGE<(t_ynMSdg);WYIGIcGE++){
    int i;
    rd(N);
    for(i=(0);i<(N-1);i++){
      a1[i] = i+1;
      b1[i] = rd_int()-1;
    }
    for(i=(0);i<(N-1);i++){
      a2[i] = i+1;
      b2[i] = rd_int()-1;
    }
    g.setEdgeRootedTree(N,N-1,a1,b1);
    g2.setEdge(N,N-1,a2,b2);
    hld.init(g2);
    f.init(&hld);
    t.init(&hld, NULL);
    res = 0;
    dfs(0,0);
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
template<class T> void fenwick<T>::malloc(int mem){
  memory = mem;
  data = (T*)std::malloc(sizeof(T)*mem);
}
template<class T> void fenwick<T>::malloc(int mem, int fg){
  memory = mem;
  data = (T*)std::malloc(sizeof(T)*mem);
  if(fg){
    init(mem);
  }
}
template<class T> void fenwick<T>::walloc(int mem, void **workMemory /* = &wmem*/){
  memory = mem;
  walloc1d(&data, mem, workMemory);
}
template<class T> void fenwick<T>::walloc(int mem, int fg, void **workMemory /* = &wmem*/){
  memory = mem;
  walloc1d(&data, mem, workMemory);
  if(fg){
    init(mem);
  }
}
template<class T> void fenwick<T>::free(void){
  memory = 0;
  free(data);
}
template<class T> void fenwick<T>::init(int N){
  size = N;
  memset(data,0,sizeof(T)*N);
}
template<class T> void fenwick<T>::add(int k, T val){
  while(k < size){
    data[k] += val;
    k |= k+1;
  }
}
template<class T> T fenwick<T>::get(int k){
  T res = 0;
  while(k>=0){
    res += data[k];
    k = (k&(k+1))-1;
  }
  return res;
}
template<class T> T fenwick<T>::range(int a, int b){
  if(a < 0){
    a = 0;
  }
  if(b >= size){
    b = size - 1;
  }
  if(b < a){
    return 0;
  }
  return get(b) - get(a-1);
}
template<class T> int fenwick<T>::kth(T k){
  int i=0;
  int j=size;
  int c;
  T v;
  while(i<j){
    c = (i+j)/2;
    v = get(c);
    if(v <= k){
      i=c+1;
    }
    else{
      j=c;
    }
  }
  return i==size?-1:i;
}
// cLay version 20210524-1

// --- original code ---
// //no-unlocked
// int N, a1[3d5], b1[], a2[], b2[];
// graph g, g2;
// HLD hld;
// HLD_fenwick<int> f;
// HLD_segtree<int> t;
// int res;
// 
// void dfs(int n, int s){
//   int ad = -1, dl = -1, x, y, d;
// 
//   if(t.getSum(n,n) == 0){
//     ad = n;
//     if(f.get(0,n) != 0){
//       d = hld.depth(n);
//       x = bsearch_min[int,x,0,d][
//         y = hld.up(n,x);
//       ](f.get(y,n) != 0);
//       dl = hld.up(n,x);
//     }
//   }
// 
//   if(ad >= 0){
//     f.add(ad, 1);
//     t.add(0, ad, 1);
//     s++;
//   }
//   if(dl >= 0){
//     f.add(dl, -1);
//     t.add(0, dl, -1);
//     s--;
//   }
// 
//   // wt(n,s);
//   // rep(i,N) wt("--", i, f.get(i,i), t.getSum(i,i)); 
// 
//   res >?= s;
//   rep[g.edge[n]](i,g.es[n]) dfs(i,s);
// 
//   if(ad >= 0){
//     f.add(ad, -1);
//     t.add(0, ad, -1);
//     s--;
//   }
//   if(dl >= 0){
//     f.add(dl, 1);
//     t.add(0, dl, 1);
//     s++;
//   }
// 
// }
// 
// {
//   REP(rd_int()){
//     rd(N);
//     rep(i,N-1) a1[i] = i+1, b1[i] = rd_int()-1;
//     rep(i,N-1) a2[i] = i+1, b2[i] = rd_int()-1;
//     g.setEdgeRootedTree(N,N-1,a1,b1);
//     g2.setEdge(N,N-1,a2,b2);
//     hld.init(g2);
//     f.init(&hld);
//     t.init(&hld, NULL);
//     res = 0;
//     dfs(0,0);
//     wt(res);
//   }
// }