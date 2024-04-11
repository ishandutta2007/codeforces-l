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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
int WRITER_DOUBLE_DIGIT = 15;
inline int writerDigit_double(){
  return WRITER_DOUBLE_DIGIT;
}
inline void writerDigit_double(int d){
  WRITER_DOUBLE_DIGIT = d;
}
inline void wt_L(double x){
  const int d = WRITER_DOUBLE_DIGIT;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
  }
}
int N;
int Q;
int L;
int R;
char S[200000+2];
int c[6][200000+2];
int p[3];
int k;
int main(){
  int xr20shxY;
  rd(N);
  rd(Q);
  rd(S);
  int Lj4PdHRW;
  for(Lj4PdHRW=(0);Lj4PdHRW<(3);Lj4PdHRW++){
    p[Lj4PdHRW] = Lj4PdHRW;
  }
  do{
    {
      int i;
      for(i=(0);i<(N);i++){
        c[k][i+1] = c[k][i];
        if(S[i] != 'a' + p[i%3]){
          c[k][i+1]++;
        }
      }
      k++;
    }
  }
  while(next_permutation(p,p+3));
  for(xr20shxY=(0);xr20shxY<(Q);xr20shxY++){
    rd(L);L += (-1);
    rd(R);
    int KrdatlYV;
    remove_reference<decltype(c[KrdatlYV][R]-c[KrdatlYV][L])>::type ao_dF3pO;
    int tU__gIr_ = 0;
    if((0) > ((6)-1)){
      ao_dF3pO = numeric_limits<remove_reference<decltype(c[KrdatlYV][R]-c[KrdatlYV][L])>::type>::max();
    }
    else{
      for(KrdatlYV = 0; KrdatlYV <= (6)-1; KrdatlYV++){
        if(tU__gIr_ == 0){
          ao_dF3pO = c[KrdatlYV][R]-c[KrdatlYV][L];
          tU__gIr_ = 1;
          continue;
        }
        const auto hCmBdyQB = c[KrdatlYV][R]-c[KrdatlYV][L];
        if(ao_dF3pO > hCmBdyQB){
          ao_dF3pO = hCmBdyQB;
        }
      }
      if(tU__gIr_==0){
        ao_dF3pO = numeric_limits<remove_reference<decltype(c[KrdatlYV][R]-c[KrdatlYV][L])>::type>::max();
      }
    }
    wt_L(ao_dF3pO);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int N, Q, L, R;
// char S[2d5+2];
// int c[6][2d5+2], p[3], k;
// {
//   rd(N,Q,S);
//   rep_perm(p,3){
//     rep(i,N){
//       c[k][i+1] = c[k][i];
//       if(S[i] != 'a' + p[i%3]) c[k][i+1]++;
//     }
//     k++;
//   }
//   rep(Q){
//     rd(L--,R);
//     wt(min[i,0,6](c[i][R]-c[i][L]));
//   }
// }