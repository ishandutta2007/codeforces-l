#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}


const int MOD=998244353;

struct mint {
  unsigned x;
  inline int _norm(int x) {
    if (x<0) x+=MOD;
    return x;
  }
  mint() : x(0) {}
  mint(signed sig) {sig=_norm(sig); x=sig;}
  mint(signed long long sig) {sig=_norm(sig%MOD); x=sig;}
  int get() const { return (int)x; }
 
  mint &operator+=(mint that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
  mint &operator-=(mint that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  mint &operator*=(mint that) { x = ((unsigned long long)x * that.x) % MOD; return *this; }
  mint &operator/=(mint that) { return *this *= that.inverse(); }

  mint &operator+=(int that) {that=_norm(that); if((x += that) >= MOD) x -= MOD; return *this; }
  mint &operator-=(int that) {that=_norm(that); if((x += MOD - that) >= MOD) x -= MOD; return *this; }
  mint &operator*=(int that) {that=_norm(that); x = ((unsigned long long)x * that) % MOD; return *this; }
  mint &operator/=(int that) {that=_norm(that); return *this *= mint(that).inverse(); }

  mint operator+(mint that) const { return mint(*this) += that; }
  mint operator-(mint that) const { return mint(*this) -= that; }
  mint operator*(mint that) const { return mint(*this) *= that; }
  mint operator/(mint that) const { return mint(*this) /= that; }

  mint operator+(int that) const { return mint(*this) += that; }
  mint operator-(int that) const { return mint(*this) -= that; }
  mint operator*(int that) const { return mint(*this) *= that; }
  mint operator/(int that) const { return mint(*this) /= that; }


  mint inverse() const {
    signed a = x, b = MOD, u = 1, v = 0;
    while(b) {
      signed t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }
    if(u < 0) u += MOD;
    mint res; res.x = (unsigned)u;
    return res;
  }
 
  bool operator==(mint that) const { return x == that.x; }
  bool operator!=(mint that) const { return x != that.x; }
  mint operator-() const { mint t; t.x = x == 0 ? 0 : MOD - x; return t; }
  mint operator^(unsigned long long k) const {
    // 0^0 is 1. k must be taken modulo phi(MOD) (MOD-1 if prime) and NOT MOD itself
    mint a=(*this);
    mint r = 1;
    while(k) {
      if(k & 1) r *= a;
      a *= a;
      k >>= 1;
    }
    return r;
  }
};

void gauss(vector<vector<mint> > &A) {
  int rlim=A.size();
  int clim=A[0].size();
  int gaussR=0;
  for (int gaussC=0;gaussC<clim;gaussC++) {
    int rWithC=-1;
    for (int rCand=gaussR;rCand<rlim;rCand++) {
      if (A[rCand][gaussC].get() != 0){
        rWithC=rCand;
        break;
      }
    }
    if (rWithC != -1) {
      swap(A[gaussR], A[rWithC]);
      mint norm=A[gaussR][gaussC].inverse();
      for (int col=gaussC;col<clim;col++) {
        A[gaussR][col] *= norm;
      }
      for (int row=0;row<rlim;row++){
        if (row!=gaussR) {
          mint mul=A[row][gaussC];
          for (int col=0;col<clim;col++) {
            A[row][col] -= A[gaussR][col] * mul;
          }
        }
      }
      gaussR += 1;
    }
  } 
}

vector<mint> WalshHadamardTransformInverse(vector<mint> const & poly) {
  // O(n^3). poly must have size power of 2
  int n=poly.size();
  assert(__builtin_popcount(n)==1);
  vector<vector<mint> > A(n);
  for (int r=0;r<n;r++) {
    A[r].resize(n+1);
    for (int c=0;c<n;c++) {
      A[r][c]=poly[r^c];
    }
    A[r][n]=(r==0)?1:0; // Identity vector is {1,0,0,...}
  }
  gauss(A);
  vector<mint> res(n);
  for (int r=0;r<n;r++) res[r]=A[r][n];
  return res;
}

int mex(vi &a) {
  int n=a.size();
  for (int x=0;x<n;x++) {
    while(x!=a[x] && 0<=a[x] && a[x]<n && a[x]!=a[a[x]]) {
      swap(a[x],a[a[x]]);
    }
  }
  for (int x=0;x<n;x++) {
    if (a[x]!=x) return x;
  }
  return n;
}

vi dp;
vvi gr;
int dfs(int x) {
  if (dp[x]!=-1) return dp[x];
  vi v;
  for (auto &y:gr[x]) {
    v.PB(dfs(y));
  }
  int ans=mex(v);
  return dp[x]=ans;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int m=rint();
  gr.resize(n+1); dp.resize(n+1,-1);
  for (int i=0;i<m;i++) {
    int x=rint(); int y=rint();
    gr[x].PB(y);
  }
  for (int x=1;x<=n;x++) dfs(x);
  int hi=0;
  for (int x=1;x<=n;x++) chkmax(hi,dp[x]);
  int pn=1;
  while(pn<=hi) pn*=2;
  vector<mint> poly(pn);
  for (int x=1;x<=n;x++) poly[dp[x]]+=1;
  mint normalizer=-(mint(n+1).inverse());
  for (auto &w:poly) w*=normalizer;
  poly[0]+=1; // 1-P(x)
  //for (auto &w:poly) printf("%d ",w.get()); printf(" end P\n");
  auto inv=WalshHadamardTransformInverse(poly); // 1/(1-P(x))=1+P(x)+P^2(x)+...
  //for (auto &w:inv) printf("%d ",w.get()); printf(" end inv\n");
  mint Bwin=inv[0]/(n+1);
  mint Awin=mint(1)-Bwin;
  printf("%d\n",Awin.get());
}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}