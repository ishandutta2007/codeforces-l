#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T, class S> int subsetSumSD(int n, T a[], S res[], void *mem = wmem){
  int i;
  int k;
  int sz = 1;
  int bf;
  int x;
  int y;
  S*arr;
  walloc1d(&arr, 1, &mem);
  res[0] = 0;
  for(k=(0);k<(n);k++){
    bf = sz;
    sz = x = y = 0;
    for(i=(0);i<(bf);i++){
      arr[i] = res[i];
    }
    for(i=(0);i<(bf);i++){
      arr[bf+i] = res[i] + a[k];
    }
    while(x < bf && y < bf){
      if(arr[x] < arr[bf+y]){
        if(sz==0 || res[sz-1]!=arr[x]){
          res[sz++] = arr[x];
        }
        x++;
      }
      else{
        if(sz==0 || res[sz-1]!=arr[bf+y]){
          res[sz++] = arr[bf+y];
        }
        y++;
      }
    }
    while(x < bf){
      if(sz==0 || res[sz-1]!=arr[x]){
        res[sz++] = arr[x];
      }
      x++;
    }
    while(y < bf){
      if(sz==0 || res[sz-1]!=arr[bf+y]){
        res[sz++] = arr[bf+y];
      }
      y++;
    }
  }
  return sz;
}
template<class T, class S, class U> int subsetSumSD(int n, T a[], S res[], U lim, void *mem = wmem){
  int i;
  int k;
  int sz = 1;
  int bf;
  int x;
  int y;
  S*arr;
  walloc1d(&arr, 1, &mem);
  res[0] = 0;
  for(k=(0);k<(n);k++){
    bf = sz;
    sz = x = y = 0;
    for(i=(0);i<(bf);i++){
      arr[i] = res[i];
    }
    for(i=(0);i<(bf);i++){
      arr[bf+i] = res[i] + a[k];
    }
    while(x < bf && y < bf){
      if(arr[x] < arr[bf+y]){
        if(sz==0 || res[sz-1]!=arr[x]){
          res[sz++] = arr[x];
        }
        x++;
      }
      else{
        if(sz==0 || res[sz-1]!=arr[bf+y]){
          res[sz++] = arr[bf+y];
        }
        y++;
      }
    }
    while(x < bf){
      if(sz==0 || res[sz-1]!=arr[x]){
        res[sz++] = arr[x];
      }
      x++;
    }
    while(y < bf){
      if(sz==0 || res[sz-1]!=arr[bf+y]){
        res[sz++] = arr[bf+y];
      }
      y++;
    }
    while(sz && res[sz-1] > lim){
      sz--;
    }
  }
  return sz;
}
int N;
int A[10];
int sz;
int arr[2000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      A[i] = abs(A[i]);
    }
    sz = subsetSumSD(N,A,arr);
    if(sz < (1<<N)){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[10];
// int sz, arr[2000];
// {
//   REP(rd_int()){
//     rd(N,A(N));
//     rep(i,N) A[i] = abs(A[i]);
//     sz = subsetSumSD(N,A,arr);
//     wt(if[sz < (1<<N), "YES", "NO"]);
//   }
// }