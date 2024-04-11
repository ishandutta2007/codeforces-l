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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int main(){
  int Lj4PdHRW;
  int X;
  int Y;
  int N;
  char S[1000000+2];
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    int dx = 0;
    int dy = 0;
    rd(X);
    rd(Y);
    N = rd(S);
    for(i=(0);i<(N);i++){
      if(S[i]=='U' && x2 - (dx-1) < X){
        dx--;
        chmin(x1, dx);
        continue;
      }
      if(S[i]=='D' && (dx+1) - x1 < X){
        dx++;
        chmax(x2, dx);
        continue;
      }
      if(S[i]=='L' && y2 - (dy-1) < Y){
        dy--;
        chmin(y1, dy);
        continue;
      }
      if(S[i]=='R' && (dy+1) - y1 < Y){
        dy++;
        chmax(y2, dy);
        continue;
      }
      break;
    }
    wt_L(-x1+1);
    wt_L(' ');
    wt_L(-y1+1);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20211024-1

// --- original code ---
// //no-unlocked
// int X, Y, N;
// char S[1d6+2];
// REP(rd_int()){
//   int x1 = 0, x2 = 0, y1 = 0, y2 = 0, dx = 0, dy = 0;
//   rd(X,Y,S@N);
//   rep(i,N){
//     if(S[i]=='U' && x2 - (dx-1) < X) dx--, x1 <?= dx, continue;
//     if(S[i]=='D' && (dx+1) - x1 < X) dx++, x2 >?= dx, continue;
//     if(S[i]=='L' && y2 - (dy-1) < Y) dy--, y1 <?= dy, continue;
//     if(S[i]=='R' && (dy+1) - y1 < Y) dy++, y2 >?= dy, continue;
//     break;
//   }
//   wt(-x1+1, -y1+1);
// }