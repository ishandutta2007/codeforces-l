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
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
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
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int N;
    rd(N);
    int A[N];
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    int dp[2001];
    int nx[2001];
    int res;
    int mx;
    int s;
    int xr20shxY;
    cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type WYIGIcGE;
    if(N==0){
      WYIGIcGE = 0;
    }
    else{
      WYIGIcGE = A[0];
      for(xr20shxY=(1);xr20shxY<(N);xr20shxY++){
        WYIGIcGE = max_L(WYIGIcGE, A[xr20shxY]);
      }
    }
    mx =WYIGIcGE;
    int ao_dF3pO;
    int tU__gIr_;
    int a2conNHc;
    ao_dF3pO = mx;
    tU__gIr_ = 2*mx;
    while(ao_dF3pO < tU__gIr_){
      int i, k;
      if((ao_dF3pO + tU__gIr_)%2==0){
        a2conNHc = (ao_dF3pO + tU__gIr_) / 2;
      }
      else{
        a2conNHc = (ao_dF3pO + tU__gIr_ - 1) / 2;
      }
      for(i=(0);i<(a2conNHc+1);i++){
        dp[i] = 1;
      }
      for(k=(0);k<(N);k++){
        for(i=(0);i<(a2conNHc+1);i++){
          nx[i] = dp[i];
          dp[i] = 0;
        }
        for(i=(0);i<(a2conNHc+1);i++){
          if(nx[i]){
            if(i-A[k] >= 0){
              dp[i-A[k]] = 1;
            }
            if(i+A[k] <= a2conNHc){
              dp[i+A[k]] = 1;
            }
          }
        }
      }
      int jPV_0s1p;
      cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type BUotOFBp;
      if(a2conNHc+1==0){
        BUotOFBp = 0;
      }
      else{
        BUotOFBp = dp[0];
        for(jPV_0s1p=(1);jPV_0s1p<(a2conNHc+1);jPV_0s1p++){
          BUotOFBp += dp[jPV_0s1p];
        }
      }
      s =BUotOFBp;
      if(s){
        tU__gIr_ = a2conNHc;
      }
      else{
        ao_dF3pO = a2conNHc + 1;
      }
    }
    res =tU__gIr_;
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @N, @A[N], dp[2001], nx[2001], res, mx, s;
// 
//   mx = max(A(N));
//   res = bsearch_min[int,w,mx,2*mx][
//     rep(i,w+1) dp[i] = 1;
//     rep(k,N){
//       rep(i,w+1) nx[i] = dp[i], dp[i] = 0;
//       rep(i,w+1) if(nx[i]){
//         if(i-A[k] >= 0) dp[i-A[k]] = 1;
//         if(i+A[k] <= w) dp[i+A[k]] = 1;
//       }
//     }
//     s = sum(dp(w+1));
//   ](s);
//   wt(res);
// }