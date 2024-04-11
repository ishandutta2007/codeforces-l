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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
long long T;
char S[100000+2];
int cnt[26];
int main(){
  int i;
  long long k;
  long long x;
  rd(N);
  rd(T);
  rd(S);
  for(i=(0);i<(N);i++){
    S[i] -= 'a';
  }
  if(N){
    T -= (1 << S[--N]);
  }
  if(N){
    T += (1 << S[--N]);
  }
  for(i=(0);i<(N);i++){
    cnt[S[i]]++;
  }
  for(i=(26)-1;i>=(0);i--){
    T = abs(T);
    x = (1 << i);
    k =min_L(T / x, cnt[i]);
    T -= x * k;
    cnt[i] = (cnt[i] - k) % 2;
    if(cnt[i]){
      T -= x;
    }
  }
  if(T==0){
    wt_L("Yes");
    wt_L('\n');
  }
  else{
    wt_L("No");
    wt_L('\n');
  }
  return 0;
}
// cLay version 20201229-1

// --- original code ---
// //no-unlocked
// int N; ll T; char S[1d5+2];
// int cnt[26];
// {
//   ll k, x;
//   rd(N,T,S);
//   rep(i,N) S[i] -= 'a';
// 
//   if(N) T -= (1 << S[--N]);
//   if(N) T += (1 << S[--N]);
// 
//   rep(i,N) cnt[S[i]]++;
//   rrep(i,26){
//     T = abs(T);
//     x = (1 << i);
//     k = min(T / x, cnt[i]);
//     T -= x * k;
//     cnt[i] = (cnt[i] - k) % 2;
//     if(cnt[i]) T -= x;
//   }
// 
//   wt(if[T==0, "Yes", "No"]);
// }