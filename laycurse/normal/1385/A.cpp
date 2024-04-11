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
    int X;
    int Y;
    int Z;
    int mx;
    rd(X);
    rd(Y);
    rd(Z);
    mx =max_L(max_L(X, Y), Z);
    if(X==mx && Y==mx){
      wt_L("YES");
      wt_L('\n');
      wt_L(mx);
      wt_L(' ');
      wt_L(Z);
      wt_L(' ');
      wt_L(Z);
      wt_L('\n');
      continue;
    }
    if(Y==mx && Z==mx){
      wt_L("YES");
      wt_L('\n');
      wt_L(X);
      wt_L(' ');
      wt_L(X);
      wt_L(' ');
      wt_L(mx);
      wt_L('\n');
      continue;
    }
    if(Z==mx && X==mx){
      wt_L("YES");
      wt_L('\n');
      wt_L(Y);
      wt_L(' ');
      wt_L(mx);
      wt_L(' ');
      wt_L(Y);
      wt_L('\n');
      continue;
    }
    wt_L("NO");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// {
//   REP(rd_int()){
//     int X, Y, Z, mx;
//     rd(X,Y,Z);
//     mx = max(X,Y,Z);
//     if(X==mx && Y==mx) wt("YES"), wt(mx, Z, Z), continue;
//     if(Y==mx && Z==mx) wt("YES"), wt(X, X, mx), continue;
//     if(Z==mx && X==mx) wt("YES"), wt(Y, mx, Y), continue;
//     wt("NO");
//   }
// }