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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
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
template<class T> int runLength(int N, T *arr, void *val_s = NULL, void *len_s = NULL){
  int i;
  int rN;
  T*val = (T*) val_s;
  int*len = (int*) len_s;
  if(N==0){
    return 0;
  }
  if(val==NULL || len==NULL){
    void*mem = wmem;
    if(val==NULL){
      walloc1d(&val, N, &mem);
    }
    if(len==NULL){
      walloc1d(&len, N, &mem);
    }
  }
  rN = 1;
  val[0] = arr[0];
  len[0] = 1;
  for(i=(1);i<(N);i++){
    if(val[rN-1] == arr[i]){
      len[rN-1]++;
    }
    else{
      val[rN] = arr[i];
      len[rN] = 1;
      rN++;
    }
  }
  return rN;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int main(){
  int R5MtCiij, i;
  wmem = memarr;
  static int cost[500000+1];
  for(i=(0);i<(500000+1);i++){
    cost[i] = 1073709056;
  }
  for(i=1;i<500000+1;i*=2){
    cost[i] = 0;
  }
  for(i=(500000+1)-1;i>=(1);i--){
    chmin(cost[i-1], cost[i] + 1);
  }
  int YGwFZBGH = rd_int();
  for(R5MtCiij=(0);R5MtCiij<(YGwFZBGH);R5MtCiij++){
    int x;
    int N;
    rd(N);
    int A[N];
    {
      int pyHJGNQc;
      for(pyHJGNQc=(0);pyHJGNQc<(N);pyHJGNQc++){
        rd(A[pyHJGNQc]);
      }
    }
    int s;
    int len[N];
    int res = 1073709056;
    int tmp;
    int mode;
    int rem;
    int trem;
    sortA_L(N,A);
    s = runLength(N,A,NULL,len);
    for(x=(0);x<(22);x++){
      int y;
      for(y=(0);y<(22);y++){
        tmp = mode = 0;
        rem = 1<<x;
        trem = N;
        for(i=(0);i<(s);i++){
          if(rem < len[i]){
            if(mode == 0){
              tmp += rem;
              mode++;
              rem = 1<<y;
              i--;
              continue;
            }
            break;
          }
          else{
            auto ClGtuHe4 = (len[i]);
            rem-=ClGtuHe4;
            trem-=ClGtuHe4;
          }
        }
        if(mode == 0){
          tmp += rem;
          mode++;
          rem = 1<<y;
        }
        chmin(res, tmp + rem + cost[trem]);
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20220116-1

// --- original code ---
// //no-unlocked
// static int cost[5d5+1];
// rep(i,5d5+1) cost[i] = int_inf;
// for(i=1;i<5d5+1;i*=2) cost[i] = 0;
// rrep(i,1,5d5+1) cost[i-1] <?= cost[i] + 1;
// 
// REP(rd_int()){
//   int @N, @A[N], s, len[N], res = int_inf, tmp, mode, rem, trem;
//   sortA(N,A);
//   s = runLength(N,A,NULL,len);
// 
//   rep(x,22) rep(y,22){
//     tmp = mode = 0;
//     rem = 1<<x;
//     trem = N;
//     rep(i,s){
//       if(rem < len[i]){
//         if(mode == 0) tmp += rem, mode++, rem = 1<<y, i--, continue;
//         break;
//       } else{
//         (rem, trem) -= len[i];
//       }
//     }
//     if(mode == 0) tmp += rem, mode++, rem = 1<<y;
//     res <?= tmp + rem + cost[trem];
//   }
// 
//   wt(res);
// }