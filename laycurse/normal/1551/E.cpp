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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int K;
int A[2002];
int dp[2002];
int nx[2002];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, k;
    rd(N);
    rd(K);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    dp[0] = 0;
    for(i=(1);i<(N+1);i++){
      dp[i] = -1073709056;
    }
    for(k=(0);k<(N);k++){
      for(i=(0);i<(N+1);i++){
        nx[i] = -1073709056;
      }
      for(i=(0);i<(N+1);i++){
        if(dp[i] >= 0){
          if(A[k] == k - i){
            chmax(nx[i], dp[i] +1);
          }
          else{
            chmax(nx[i], dp[i] +0);
          }
          chmax(nx[i+1], dp[i]);
        }
      }
      for(i=(0);i<(N+1);i++){
        dp[i] = nx[i];
      }
    }
    for(i=(0);i<(N+1);i++){
      if(dp[i] >= K){
        wt_L(i);
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    wt_L(-1);
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int N, K, A[2002], dp[], nx[];
// {
//   REP(rd_int()){
//     rd(N,K,(A--)(N));
// 
//     dp[0] = 0;
//     rep(i,1,N+1) dp[i] = -int_inf;
//     rep(k,N){
//       rep(i,N+1) nx[i] = -int_inf;
//       rep(i,N+1) if(dp[i] >= 0){
//         nx[i] >?= dp[i] + if[A[k] == k - i, 1, 0];
//         nx[i+1] >?= dp[i];
//       }
//       rep(i,N+1) dp[i] = nx[i];
//     }
//     rep(i,N+1) if(dp[i] >= K) wt(i), break_continue;
//     wt(-1);
//   }
// }