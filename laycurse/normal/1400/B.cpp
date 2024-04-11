#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
long long P;
long long F;
int C[2];
long long W[2];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    long long res = 0;
    long long a;
    long long b;
    long long c;
    long long d;
    rd(P);
    rd(F);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(2);cTE1_r3A++){
        rd(C[cTE1_r3A]);
      }
    }
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(2);xr20shxY++){
        rd(W[xr20shxY]);
      }
    }
    if(W[0] > W[1]){
      swap(C[0], C[1]);
      swap(W[0], W[1]);
    }
    for(a=(0);a<(C[0]+1);a++){
      if(a * W[0] > P){
        break;
      }
      b = (P - a * W[0]) / W[1];
      c =min_L(C[0] - a, F / W[0]);
      d =min_L(C[1] - b, (F - c * W[0]) / W[1]);
      chmax(res, a + b + c + d);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// ll P, F;
// int C[2]; ll W[2];
// {
//   REP(rd_int()){
//     ll res = 0, a, b, c, d;
//     rd(P, F, C(2), W(2));
//     if(W[0] > W[1]) swap(C[0], C[1]), swap(W[0], W[1]);
//     rep(a,C[0]+1){
//       if(a * W[0] > P) break;
//       b = (P - a * W[0]) / W[1];
//       c = min(C[0] - a, F / W[0]);
//       d = min(C[1] - b, (F - c * W[0]) / W[1]);
//       res >?= a + b + c + d;
//     }
//     wt(res);
//   }
// }