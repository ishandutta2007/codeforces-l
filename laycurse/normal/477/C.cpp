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

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}

int N, M;
char S[2100], P[555];

int dp[2333][2333];
int golen[2333];

int solve(int place, int rest){
  int i, j, k;
  int res = -1000000000;

  if(dp[place][rest] != -1) return dp[place][rest];
  if(place==N){
    if(rest) return dp[place][rest] = res;
    return dp[place][rest] = 0;
  }

  k = solve(place+1, rest);
  res = max(res, k);
  
  if(rest){
    k = solve(place+1, rest-1);
    res = max(res, k);
  }

  if(golen[place] != -1){
    j = golen[place] - place - M;
    if(rest >= j){
      k = solve(golen[place], rest-j) + 1;
      res = max(res, k);
    }
  }

  return dp[place][rest] = res;
}

int main(){
  int i, j, k, x;

  N = reader(S);
  M = reader(P);

  rep(i,N){
    j = 0;
    REP(k,i,N){
      if(S[k]==P[j]) j++;
      if(j==M) break;
    }
    if(j==M) golen[i] = k+1; else golen[i] = -1;
  }

  rep(i,N+1) rep(j,N+1) dp[i][j] = -1;
  rep(i,N+1){
    k = solve(0, i);
    writer(k, i==N?'\n':' ');
  }

  myed;
  return 0;
}