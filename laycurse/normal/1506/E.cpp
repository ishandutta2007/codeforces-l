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
int N;
int P[200000];
int res[200000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int loop;
    int i;
    int k;
    set<int> s;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(P[cTE1_r3A]);P[cTE1_r3A] += (-1);
      }
    }
    for(loop=(0);loop<(2);loop++){
      k = 0;
      for(i=(0);i<(N);i++){
        if(i && P[i] == P[i-1]){
          if(loop==0){
            res[i] = *s.begin();
          }
          if(loop==1){
            res[i] = *s.rbegin();
          }
          s.erase(res[i]);
        }
        else{
          res[i] = P[i];
          while(k < P[i]){
            s.insert(k++);
          }
          k++;
        }
      }
      {
        int a2conNHc;
        if(N==0){
          wt_L('\n');
        }
        else{
          for(a2conNHc=(0);a2conNHc<(N-1);a2conNHc++){
            wt_L(res[a2conNHc]+1);
            wt_L(' ');
          }
          wt_L(res[a2conNHc]+1);
          wt_L('\n');
        }
      }
    }
  }
  return 0;
}
// cLay version 20210321-1 [beta]

// --- original code ---
// //no-unlocked
// int N, P[2d5];
// int res[2d5];
// {
//   REP(rd_int()){
//     int i, k;
//     set<int> s;
//     rd(N,(P--)(N));
// 
//     rep(loop,2){
//       k = 0;
//       rep(i,N){
//         if(i && P[i] == P[i-1]){
//           if(loop==0) res[i] = *s.begin();
//           if(loop==1) res[i] = *s.rbegin();
//           s.erase(res[i]);
//         } else {
//           res[i] = P[i];
//           while(k < P[i]) s.insert(k++);
//           k++;
//         }
//       }
//       wt(res(N)+1);
//     }
//   }
// }