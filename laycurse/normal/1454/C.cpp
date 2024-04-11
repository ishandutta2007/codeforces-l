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
int N;
int A[200000];
int hist[200000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int res = 1073709056;
    int k = 0;
    int tmp;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    for(i=(0);i<(N);i++){
      if(k==0 || A[k-1] != A[i]){
        A[k++] = A[i];
      }
    }
    for(i=(0);i<(N);i++){
      hist[i] = 0;
    }
    for(i=(0);i<(k);i++){
      hist[A[i]]++;
    }
    for(i=(0);i<(N);i++){
      if(hist[i]){
        tmp = hist[i] + 1;
        if(A[0]==i){
          tmp--;
        }
        if(A[k-1]==i){
          tmp--;
        }
        chmin(res, tmp);
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20201205-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], hist[2d5];
// {
//   REP(rd_int()){
//     int res = int_inf, k = 0, tmp;
//     rd(N,(A--)(N));
//     rep(i,N) if(k==0 || A[k-1] != A[i]) A[k++] = A[i];
//     rep(i,N) hist[i] = 0;
//     rep(i,k) hist[A[i]]++;
//     rep(i,N) if(hist[i]){
//       tmp = hist[i] + 1;
//       if(A[0]==i) tmp--;
//       if(A[k-1]==i) tmp--;
//       res <?= tmp;
//     }
//     wt(res);
//   }
// }