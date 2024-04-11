#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define po pop_back
#define YES cout<<"YES\n" 	#define Yes cout<<"Yes\n"
#define NO cout<<"NO\n"		#define No cout<<"No\n"
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
#define cn change_number_tostring
#define cs change_string_tonumber
#define pri init_prime_distance
#define debug(x) cout<<":"<<x<<endl
using namespace std;

const int mod = 1e9+7;
const int sp = 1e9;
const int ma = 1e5+10;

int f[ma];
inline int find(int k) { return f[k]==k? k : f[k]=find(f[k]);} // f[find(j)] = find(k);

inline int digit(int i) { stringstream ss; ss<<i; return ss.str().size(); }
inline string change_number_tostring(int i) { stringstream ss; ss<<i; return ss.str(); }
inline int change_string_tonumber(string s) { int num; stringstream ss(s);  ss>>num; return num;}
inline int quick(int a, int b) { a%=mod; int res = 1;  while(b) { if(b & 1) res = res * a % mod; a = a * a % mod;  b >>= 1; } return res; }
inline int C(int n, int m) { int resdw1 = 1; for2(i, 1, n) resdw1 = resdw1 * i % mod; int resdw2 = 1; for2(i, 1, m - n) resdw2 = resdw2 * i % mod;  int resup = 1;  for2(i, 1, m) resup = resup * i % mod;     return resup * quick(resdw1, mod - 2) % mod * quick(resdw2, mod - 2) % mod; }

inline void read(int &x) {   int f = 1; x = 0; char op = getchar(); while(op < '0' || op > '9') {  if(op == '-') f = -1; op = getchar(); } while(op >= '0' && op <= '9') { x = x * 10 + op - '0'; op = getchar(); } x *= f;	}
inline void print(int x) {   if(x < 0) putchar('-'), x = -x; if(x > 9) print(x / 10); putchar(x % 10 + '0');  }

const int man=1e7+5;
bool vis[man]={0};
int prime[man];
inline void init_prime_distance()  {int cnt= 0; for (int i=2;i<=man;i++) { if (!vis[i])  prime[cnt++]=i; for(int j=0;j<cnt&&i*prime[j]<=man;j++) { vis[i*prime[j]] = 1; if (i%prime[j]== 0) break; } } }

// double time=clock();  printf("%lf\n",clock()-time);
const int N = 2e3+10;
int a[N],dp[N][N]; 
void solve()
{
	int n; cin>>n;
	for00;
	sort(a+1,a+n+1);
	for2(i,1,n) for2(j,1,n) dp[i][j]=0;
	for2(i,1,n-1) for2(j,1,n-i)
		dp[j][j+i] = min(dp[j][j+i-1] + a[j+i]-a[j],dp[j+1][j+i] + a[j+i]-a[j]);
	cout<<dp[1][n]<<endl;
}
signed main()
{
	ios;
	int tt = 1; 
	//cin>>tt;
	while(tt--)
	{
		solve();
	}
	//int a[6] = {104,943872923,6589,889921234 ,1000000000 ,69};


}