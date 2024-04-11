#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int k;
    int N;
    rd(N);
    char res[2*N+1] = {};
    for(k=(0);k<(N);k++){
      int FmcKpFmN, tU__gIr_, t_ynMSdg;
      int s = 0;
      for(FmcKpFmN=(0);FmcKpFmN<(N-k);FmcKpFmN++){
        res[s++] = '(';
      }
      res[s++] = ')';
      for(t_ynMSdg=(0);t_ynMSdg<(k);t_ynMSdg++){
        res[s++] = '(';
      }
      for(tU__gIr_=(0);tU__gIr_<(N-1);tU__gIr_++){
        res[s++] = ')';
      }
      wt_L(res);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210917-1

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @N;
//   char res[2*N+1] = {};
//   rep(k,N){
//     int s = 0;
//     rep(N-k) res[s++] = '(';
//     res[s++] = ')';
//     rep(k) res[s++] = '(';
//     rep(N-1) res[s++] = ')';
//     wt(res);
//   }
// }