#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
int N;
int K;
char S[200000+2];
int cnt[26];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, p;
    rd(N);
    rd(K);
    rd(S);
    int res = N;
    for(i=(0);i<(N);i++){
      S[i] -= 'a';
    }
    int FmcKpFmN = (K+1)/2;
    for(p=(0);p<(FmcKpFmN);p++){
      for(i=(0);i<(26);i++){
        cnt[i] = 0;
      }
      for(i=(p);i<(N);i+=(K)){
        cnt[S[i]]++;
      }
      if(K-1-p > p){
        for(i=(K-1-p);i<(N);i+=(K)){
          cnt[S[i]]++;
        }
      }
      {
        int V9aVTaxx;
        int APIVbQlN;
        if(26==0){
          APIVbQlN = 0;
        }
        else{
          APIVbQlN = cnt[0];
          for(V9aVTaxx=(1);V9aVTaxx<(26);V9aVTaxx++){
            APIVbQlN = max_L(APIVbQlN, cnt[V9aVTaxx]);
          }
        }
        res -=APIVbQlN;
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200322-1 [beta]

// --- original code ---
// //no-unlocked
// int N, K;
// char S[2d5+2];
// int cnt[26];
// {
//   REP(rd_int()){
//     rd(N,K,S);
//     int res = N;
//     rep(i,N) S[i] -= 'a';
//     REP(p,(K+1)/2){
//       rep(i,26) cnt[i] = 0;
//       rep(i,p,N,K) cnt[S[i]]++;
//       if(K-1-p > p) rep(i,K-1-p,N,K) cnt[S[i]]++;
//       res -= max(cnt(26));
//     }
//     wt(res);
//   }
// }