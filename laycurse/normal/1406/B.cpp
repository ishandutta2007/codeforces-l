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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int ps;
int ms;
long long p[100000];
long long m[100000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int cTE1_r3A, xr20shxY;
    int i;
    int k;
    long long res = -4611686016279904256LL;
    long long tmp;
    rd(N);
    ps = ms = 0;
    for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
      rd(k);
      if(k >= 0){
        p[ps++]= k;
      }
      else{
        m[ms++]= k;
      }
    }
    rsortA_L(ps, p);
    sortA_L(ms, m);
    for(xr20shxY=(0);xr20shxY<(2);xr20shxY++){
      for(k=(0);k<(6);k++){
        if(k <= ps && 5-k <= ms){
          tmp = 1;
          for(i=(0);i<(k);i++){
            tmp *= p[i];
          }
          for(i=(0);i<(5-k);i++){
            tmp *= m[i];
          }
          chmax(res, tmp);
        }
      }
      reverse(p, p+ps);
      reverse(m, m+ms);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200913-1

// --- original code ---
// //no-unlocked
// int N;
// int ps, ms;
// ll p[1d5], m[1d5];
// {
//   REP(rd_int()){
//     int i, k;
//     ll res = -ll_inf, tmp;
//     rd(N);
//     ps = ms = 0;
//     rep(N){
//       rd(k);
//       if[k >= 0, p[ps++], m[ms++]] = k;
//     }
//     rsortA(ps, p);
//     sortA(ms, m);
//     rep(2){
//       rep(k,6) if(k <= ps && 5-k <= ms){
//         tmp = 1;
//         rep(i,k) tmp *= p[i];
//         rep(i,5-k) tmp *= m[i];
//         res >?= tmp;
//       }
//       reverse(p, p+ps);
//       reverse(m, m+ms);
//     }
//     wt(res);
//   }
// }