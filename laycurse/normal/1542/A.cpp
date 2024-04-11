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
int N;
int A[200];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(2*N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(i=(0);i<(2*N);i++){
      A[i] %= 2;
    }
    int t_ynMSdg;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type KrdatlYV;
    if(2*N==0){
      KrdatlYV = 0;
    }
    else{
      KrdatlYV = A[0];
      for(t_ynMSdg=(1);t_ynMSdg<(2*N);t_ynMSdg++){
        KrdatlYV += A[t_ynMSdg];
      }
    }
    if(KrdatlYV==N){
      wt_L("Yes");
      wt_L('\n');
    }
    else{
      wt_L("No");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210703-1

// --- original code ---
// //no-unlocked
// int N, A[200];
// {
//   REP(rd_int()){
//     rd(N,A(2N));
//     rep(i,2N) A[i] %= 2;
//     wt(if[sum(A(2N))==N, "Yes", "No"]);
//   }
// }