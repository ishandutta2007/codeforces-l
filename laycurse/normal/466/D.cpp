#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

#define ll long long
#define ull unsigned ll

#define MD 1000000007

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}

int N, H, A[2222];
ll res;

int main(){
  int i, j, k;

  reader(&N,&H);
  N += 2;
  REP(i,1,N-1) reader(A+i);
  A[0] = A[N-1] = H;

  res = 1;
  REP(i,1,N){
    if(A[i] > H){
      res = 0;
      break;
    }
    
    if(A[i-1] == A[i]){
      res = res * (1 + H - A[i-1]) % MD;
    } else if(A[i-1]+1 == A[i]){
      res = res * (H - A[i-1]) % MD;
    } else if(A[i-1]-1 == A[i]){
      continue;
    } else {
      res = 0;
      break;
    }
  }

  writer((int)res, '\n');

  myed;
  return 0;
}