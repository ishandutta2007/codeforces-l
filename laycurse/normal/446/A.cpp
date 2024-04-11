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

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int N, A[110000];

int lef[110000], rig[1100000];

int main(){
  int i, j, k;
  int res;

  reader(&N);
  rep(i,N) reader(A+i);

  rep(i,N){
    lef[i] = 1;
    if(i && A[i-1] < A[i]) lef[i] = lef[i-1] + 1;
  }
  for(i=N-1;i>=0;i--){
    rig[i] = 1;
    if(i+1 < N && A[i] < A[i+1]) rig[i] = rig[i+1] + 1;
  }

  res = 0;
  rep(i,N){
    k = 0;
    if(i - lef[i] >= 0) k++;
    res = max(res, lef[i]+k);

    k = 0;
    if(i + rig[i] < N) k++;
    res = max(res, rig[i]+k);
  }

  REP(i,1,N-1) if(A[i-1] < A[i+1]-1){
    res = max(res, lef[i-1] + rig[i+1] + 1);
  }

  writer(res,'\n');

  myed;
  return 0;
}