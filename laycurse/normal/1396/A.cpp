#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
int N;
long long A[100000];
long long res[100000];
int main(){
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  if(N==1){
    wt_L(1);
    wt_L(' ');
    wt_L(1);
    wt_L('\n');
    wt_L(-A[0]);
    wt_L('\n');
    wt_L(1);
    wt_L(' ');
    wt_L(1);
    wt_L('\n');
    wt_L(0);
    wt_L('\n');
    wt_L(1);
    wt_L(' ');
    wt_L(1);
    wt_L('\n');
    wt_L(0);
    wt_L('\n');
  }
  else{
    int i;
    for(i=(0);i<(N);i++){
      res[i] = -((moddw_L(A[i],(N-1)))) * N;
    }
    for(i=(0);i<(N);i++){
      A[i] += res[i];
    }
    wt_L(1);
    wt_L(' ');
    wt_L(N);
    wt_L('\n');
    {
      int xr20shxY;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(xr20shxY=(0);xr20shxY<(N-1);xr20shxY++){
          wt_L(res[xr20shxY]);
          wt_L(' ');
        }
        wt_L(res[xr20shxY]);
        wt_L('\n');
      }
    }
    for(i=(0);i<(N-1);i++){
      res[i] = -A[i];
    }
    wt_L(1);
    wt_L(' ');
    wt_L(N-1);
    wt_L('\n');
    {
      int tU__gIr_;
      if(N-1==0){
        wt_L('\n');
      }
      else{
        for(tU__gIr_=(0);tU__gIr_<(N-1-1);tU__gIr_++){
          wt_L(res[tU__gIr_]);
          wt_L(' ');
        }
        wt_L(res[tU__gIr_]);
        wt_L('\n');
      }
    }
    wt_L(N);
    wt_L(' ');
    wt_L(N);
    wt_L('\n');
    wt_L(-A[N-1]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int N; ll A[1d5];
// ll res[1d5];
// {
//   rd(N,A(N));
//   if(N==1){
//     wt(1,1);
//     wt(-A[0]);
//     wt(1,1);
//     wt(0);
//     wt(1,1);
//     wt(0);
//   } else {
//     rep(i,N) res[i] = -(A[i] %% (N-1)) * N;
//     rep(i,N) A[i] += res[i];
//     wt(1,N);
//     wt(res(N));
// 
//     rep(i,N-1) res[i] = -A[i];
//     wt(1,N-1);
//     wt(res(N-1));
// 
//     wt(N,N);
//     wt(-A[N-1]);
//   }
// }