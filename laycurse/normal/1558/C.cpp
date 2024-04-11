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
int A[20000];
int ress;
int res[20000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int x;
    int y;
    int lim;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    lim = N * 5 / 2;
    ress = 0;
    while(N > 1){
      for(i=(0);i<(N);i++){
        if(A[i]==N-2){
          x = i;
        }
        if(A[i]==N-1){
          y = i;
        }
      }
      if(x == N-2 && y == N-1){
        N -= 2;
        continue;
      }
      if(x%2!=1 || y%2!=0){
        wt_L(-1);
        wt_L('\n');
        goto Q5VJL1cS;
      }
      if(x==1 && y==0){
        res[ress++] = N;
        reverse(A, A+res[ress-1]);
        continue;
      }
      if(x%2==1 && y==x+1){
        res[ress++] = y+1;
        reverse(A, A+res[ress-1]);
        continue;
      }
      if(x%2==1 && y==x-1){
        res[ress++] = y+3;
        reverse(A, A+res[ress-1]);
        continue;
      }
      if(x%2==1 && y==0){
        res[ress++] = x;
        reverse(A, A+res[ress-1]);
        continue;
      }
      if(x%2==1){
        res[ress++] = y+1;
        reverse(A, A+res[ress-1]);
        continue;
      }
      wt_L(-1);
      wt_L('\n');
      goto Q5VJL1cS;
    }
    assert(ress <= lim);
    wt_L(ress);
    wt_L('\n');
    {
      int ao_dF3pO;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(ao_dF3pO=(0);ao_dF3pO<(ress-1);ao_dF3pO++){
          wt_L(res[ao_dF3pO]);
          wt_L(' ');
        }
        wt_L(res[ao_dF3pO]);
        wt_L('\n');
      }
    }
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210819-1 [beta]

// --- original code ---
// //no-unlocked
// int N, A[2d4];
// int ress, res[];
// {
//   REP(rd_int()){
//   // rep(100000){
//     int i, x, y, lim;
//     rd(N,(A--)(N));
//     lim = N * 5 / 2;
//     // N = 13; lim = N * 5 / 2;
//     // rep(i,N) A[i] = i;
//     // rep(300){
//     //   x = rand()%N+1;
//     //   if(x%2==1) reverse(A,A+x);
//     // }
//     // puts("");
//     ress = 0;
//     while(N > 1){
//       // wt(A(N),":",x,y);
// 
//       rep(i,N){
//         if(A[i]==N-2) x = i;
//         if(A[i]==N-1) y = i;
//       }
//       if(x == N-2 && y == N-1) N -= 2, continue;
// 
// 
//       if(x%2!=1 || y%2!=0) wt(-1), break_continue;
// 
//       if(x==1 && y==0){
//         res[ress++] = N;
//         reverse(A, A+res[ress-1]);
//         continue;
//       }
// 
//       if(x%2==1 && y==x+1){
//         res[ress++] = y+1;
//         reverse(A, A+res[ress-1]);
//         continue;
//       }
// 
//       if(x%2==1 && y==x-1){
//         res[ress++] = y+3;
//         reverse(A, A+res[ress-1]);
//         continue;
//       }
// 
//       if(x%2==1 && y==0){
//         res[ress++] = x;
//         reverse(A, A+res[ress-1]);
//         continue;
//       }
// 
//       if(x%2==1){
//         res[ress++] = y+1;
//         reverse(A, A+res[ress-1]);
//         continue;
//       }
// 
//       wt(-1);
//       break_continue;
//     }
//     assert(ress <= lim);
//     wt(ress);
//     wt(res(ress));
//   }
// }