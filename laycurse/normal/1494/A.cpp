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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
char S[52];
char tmp[52];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int mask;
    int i;
    int k;
    N = rd(S);
    for(i=(0);i<(N);i++){
      S[i] -= 'A';
    }
    for(mask=(0);mask<(1<<3);mask++){
      for(i=(0);i<(N);i++){
        if(((mask) &(1<<(S[i])))){
          tmp[i] =1;
        }
        else{
          tmp[i] =-1;
        }
      }
      k = 0;
      for(i=(0);i<(N);i++){
        k += tmp[i];
        if(k < 0){
          goto FmcKpFmN;
        }
      }
      if(k){
        continue;
      }
      wt_L("YES");
      wt_L('\n');
      goto Q5VJL1cS;
      FmcKpFmN:;
    }
    wt_L("NO");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int N; char S[52], tmp[52];
// {
//   REP(rd_int()){
//     int i, k;
//     rd(S@N);
//     rep(i,N) S[i] -= 'A';
//     rep(mask,1<<3){
//       rep(i,N) tmp[i] = if[BIT_ith(mask,S[i]), 1, -1];
//       k = 0;
//       rep(i,N){
//         k += tmp[i];
//         if(k < 0) break_continue;
//       }
//       if(k) continue;
//       wt("YES"); break_continue;
//     }
//     wt("NO");
//   }
// }