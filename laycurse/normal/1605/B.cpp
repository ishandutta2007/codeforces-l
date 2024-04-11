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
int main(){
  int Lj4PdHRW;
  int N;
  char S[1002];
  int arr[1002];
  int ress;
  int res[1002];
  int x;
  int y;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    rd(S);
    for(i=(0);i<(N);i++){
      arr[i] = 0;
    }
    auto FmcKpFmN = ((0));
    auto xr20shxY = (( N-1));
    x=FmcKpFmN;
    y=xr20shxY;
    while(x < y){
      if(S[x] > S[y]){
        arr[x] = arr[y] = 1;
        x++;
        y--;
        continue;
      }
      if(S[x]=='0'){
        x++;
      }
      if(S[y]=='1'){
        y--;
      }
    }
    ress = 0;
    for(i=(0);i<(N);i++){
      if(arr[i]){
        res[ress++] = i;
      }
    }
    if(!ress){
      wt_L(0);
      wt_L('\n');
      continue;
    }
    wt_L(1);
    wt_L('\n');
    wt_L(ress);
    wt_L(' ');
    {
      int tU__gIr_;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(tU__gIr_=(0);tU__gIr_<(ress-1);tU__gIr_++){
          wt_L(res[tU__gIr_]+1);
          wt_L(' ');
        }
        wt_L(res[tU__gIr_]+1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20211024-1

// --- original code ---
// //no-unlocked
// int N; char S[1002]; int arr[], ress, res[], x, y;
// REP(rd_int()){
//   rd(N,S);
//   rep(i,N) arr[i] = 0;
//   (x, y) = (0, N-1);
//   while(x < y){
//     if(S[x] > S[y]) arr[x] = arr[y] = 1, x++, y--, continue;
//     if(S[x]=='0') x++;
//     if(S[y]=='1') y--;
//   }
//   ress = 0;
//   rep(i,N) if(arr[i]) res[ress++] = i;
//   if(!ress) wt(0), continue;
//   wt(1);
//   wt(ress, res(ress)+1);
// }