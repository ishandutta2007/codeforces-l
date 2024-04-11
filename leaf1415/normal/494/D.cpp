#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#include <array>
#include <unordered_set>
#include <unordered_map>
#define rep(x, s, t) for(ll x = (s); (x) <= (t); (x)++)
#define per(x, s, t) for(ll x = (s); (x) >= (t); (x)--)
#define reps(x, s) for(ll x = 0; (x) < (ll)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define sz(x) ((ll)(x).size())
#define all(x) (x).begin(),(x).end()
#define outl(...) dump_func(__VA_ARGS__)
#define outf(x) cout << fixed << setprecision(16) << (x) << endl
#define pb push_back
#define fst first
#define snd second
#define inf 2e18
#define eps 1e-9
const double PI = 3.1415926535897932384626433;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){ to = a, cost = b;}
};
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

const int mod = 1000000007;
//const int mod = 998244353;

struct mint{
	int x;
	mint(ll y = 0){if(y < 0 || y >= mod) y = (y%mod+mod)%mod; x = y;}
	mint(const mint &ope) {x = ope.x;}
	mint operator-(){return mint(-x);}
	mint operator+(const mint &ope){return mint(x) += ope;}
	mint operator-(const mint &ope){return mint(x) -= ope;}
	mint operator*(const mint &ope){return mint(x) *= ope;}
	mint operator/(const mint &ope){return mint(x) /= ope;}
	mint& operator+=(const mint &ope){x += ope.x; if(x >= mod) x -= mod; return *this;}
	mint& operator-=(const mint &ope){x += mod - ope.x; if(x >= mod) x -= mod; return *this;}
	mint& operator*=(const mint &ope){ll tmp = x; tmp *= ope.x, tmp %= mod; x = tmp; return *this;}
	mint& operator/=(const mint &ope){
		ll n = mod-2; mint mul = ope;
		while(n){if(n & 1) *this *= mul; mul *= mul; n >>= 1;}
		return *this;
	}
	mint inverse(){return mint(1) / *this;}
	bool operator ==(const mint &ope){return x == ope.x;}
	bool operator !=(const mint &ope){return x != ope.x;}
	bool operator <(const mint &ope)const{return x < ope.x;}
};
mint modpow(mint a, ll n){
	if(n == 0) return mint(1);
	if(n % 2) return a * modpow(a, n-1);
	else return modpow(a*a, n/2);
}
istream& operator >>(istream &is, mint &ope){ll t; is >> t, ope.x = t; return is;}
ostream& operator <<(ostream &os, mint &ope){return os << ope.x;}
ostream& operator <<(ostream &os, const mint &ope){return os << ope.x;}

ll modpow(ll a, ll n, ll mod){
	if(n == 0) return 1;
	if(n % 2) return ((a%mod) * (modpow(a, n-1, mod)%mod)) % mod;
	else return modpow((a*a)%mod, n/2, mod) % mod;
}

vector<mint> fact, fact_inv;
void make_fact(int n){
	fact.resize(n+1), fact_inv.resize(n+1);
	fact[0] = mint(1); rep(i, 1, n) fact[i] = fact[i-1] * mint(i);
	fact_inv[n] = fact[n].inverse(); per(i, n-1, 0) fact_inv[i] = fact_inv[i+1] * mint(i+1);
}
mint comb(int n, int k){ if(n < 0 || k < 0 || n < k) return mint(0); return fact[n] * fact_inv[k] * fact_inv[n-k];}
mint perm(int n, int k){ return comb(n, k) * fact[k]; }

vector<int> prime, pvec, qrime;
void make_prime(int n){
	prime.resize(n+1);
	rep(i, 2, n){
		if(prime[i] == 0) pvec.push_back(i), prime[i] = i;
		for(auto p : pvec){ if(i*p > n || p > prime[i]) break; prime[i*p] = p;}
	}
}
void make_qrime(int n){
	qrime.resize(n+1);
	rep(i, 2, n){int ni = i / prime[i]; if(prime[i] == prime[ni]) qrime[i] = qrime[ni] * prime[i]; else qrime[i] = prime[i];}
}

bool exceed(ll x, ll y, ll m){return y > 0 && x >= m / y + 1;}
void mark(){ cout << "*" << endl; }
void yes(){ cout << "YES" << endl; }
void no(){ cout << "NO" << endl; }
ll floor(ll a, ll b){ if(b < 0) a *= -1, b *= -1; if(a >= 0) return a/b; else return -((-a+b-1)/b); }
ll ceil(ll a, ll b){ if(b < 0) a *= -1, b *= -1; if(a >= 0) return (a+b-1)/b; else return -((-a)/b); }
ll modulo(ll a, ll b){ b = abs(b); return a - floor(a, b) * b;}
ll sgn(ll x){ if(x > 0) return 1; if(x < 0) return -1; return 0;}
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){return a/gcd(a, b)*b;}
ll arith(ll x){return x*(x+1)/2;}
ll arith(ll l, ll r){return arith(r) - arith(l-1);}
ll digitnum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret++; return ret;}
ll digitsum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret += x % b; return ret;}
string lltos(ll x){string ret; for(;x;x/=10) ret += x % 10 + '0'; reverse(all(ret)); return ret;}
ll stoll(string &s){ll ret = 0; for(auto c : s) ret *= 10, ret += c - '0'; return ret;}
template<typename T> void uniq(T &vec){sort(all(vec)); vec.erase(unique(all(vec)), vec.end());}
int popcount(ull x){
	x -= ((x>>1)&0x5555555555555555ULL), x = (x & 0x3333333333333333ULL) + ((x>>2) & 0x3333333333333333ULL);
	return (((x + (x>>4)) & 0x0F0F0F0F0F0F0F0FULL) * 0x0101010101010101ULL) >> 56;
}

template<class S, class T> pair<S, T>& operator+=(pair<S, T> &s, const pair<S, T> &t){s.first += t.first, s.second += t.second; return s;}
template<class S, class T> pair<S, T>& operator-=(pair<S, T> &s, const pair<S, T> &t){s.first -= t.first, s.second -= t.second; return s;}
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t){return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t){return pair<S,T>(s.first-t.first, s.second-t.second);}
template<class T> T dot(const pair<T, T> &s, const pair<T, T> &t){return s.first*t.first + s.second*t.second;}
template<class T> T cross(const pair<T, T> &s, const pair<T, T> &t){return s.first*t.second - s.second*t.first;}

template<typename T> ostream& operator << (ostream& os, vector<T>& vec){reps(i, vec) os << vec[i] << " "; return os;}
template<typename T> ostream& operator << (ostream& os, const vector<T>& vec){reps(i, vec) os << vec[i] << " "; return os;}
template<typename T> ostream& operator << (ostream& os, deque<T>& deq){reps(i,  deq) os << deq[i] << " "; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, pair<T, U>& ope){ os << "(" << ope.first << ", " << ope.second << ")"; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& ope){ os << "(" << ope.first << ", " << ope.second << ")"; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, map<T, U>& ope){ for(auto p : ope) os << "(" << p.first << ", " << p.second << "),";return os;}
template<typename T> ostream& operator << (ostream& os, set<T>& ope){for(auto x : ope) os << x << " "; return os;}
template<typename T> ostream& operator << (ostream& os, multiset<T>& ope){for(auto x : ope) os << x << " "; return os;}
template<typename T, size_t N> ostream& operator << (ostream& os, array<T, N>& arr){reps(i, arr) os << arr[i] << " "; return os;}
template<typename T, size_t N> ostream& operator << (ostream& os, const array<T, N>& arr){reps(i, arr) os << arr[i] << " "; return os;}
template<typename T> void outa(T a[], ll s, ll t){rep(i, s, t){ cout << a[i]; if(i < t) cout << " ";} cout << endl;}
void dump_func(){cout << endl;}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail){cout << head; if(sizeof...(Tail) > 0) cout << " "; dump_func(std::move(tail)...);}

struct LCA{
	struct edge{
		int to; ll cost;
		edge(){}
		edge(int a, int b){to = a, cost = b;}
	};
	
	int n, logn;
	vector<vector<edge> > G;
	vector<vector<int> > prev;
	vector<int> depth;
	vector<ll> dist;
	
	LCA(){}
	LCA(int n){init(n);}
	void init(int n){ //1-index
		this->n = n;
		G.clear(), G.resize(n+1);
	}
	void add_edge(int u, int v, ll w = 1){
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
	}
	void predfs(int v, int p, int d, ll l)
	{
		prev[v][0] = p, depth[v] = d, dist[v] = l;
		for(auto e : G[v]){
			if(e.to == p) continue;
			predfs(e.to, v, d+1, l+e.cost);
		}
	}
	void calc(int root = 1){
		logn = 0;
		for(int i = 0; ; i++){
			if(n <= (1<<i)){
				logn = i;
				break;
			}
		}
		chmax(logn, 1);
		
		prev.resize(n+1);
		for(int i = 0; i < prev.size(); i++) prev[i].resize(logn);
		depth.resize(n+1), dist.resize(n+1);
		
		prev[0][0] = 0;
		predfs(root, 0, 0, 0);
		for(int i = 1; i < logn; i++){
			for(int j = 0; j <= n; j++){
				prev[j][i] = prev[prev[j][i-1]][i-1];
			}
		}
	}
	int getLCA(int u, int v){
		int x = u, y = v;
		if(depth[y] > depth[x]) swap(x, y);
		
		for(int i = logn-1; i >= 0; i--){
			if(depth[x] - (1<<i) >= depth[y]) x = prev[x][i];
		}
		if(x == y) return x;
		for(int i = logn-1; i >= 0; i--){
			if(prev[x][i] != prev[y][i]){
				x = prev[x][i], y = prev[y][i];
			}
		}
		x = prev[x][0];
		return x;
	}
	ll getDist(int u, int v){
		return dist[u]+dist[v]-dist[getLCA(u, v)]*2;
	}
	int getAncestor(int v, int k)
	{
		for(int i = 0; i < logn; i++){
			if(k & (1<<i)) v = prev[v][i];
		}
		return v;
	}
	int getNext(int u, int v){
		if(u == v) return -1;
		if(getLCA(u, v) == u) return getAncestor(v, depth[v]-depth[u]-1);
		else return prev[u][0];
	}
};

struct Rerooting{
	typedef array<mint, 3> T;
	struct edge{
		int to, cost;
		edge(){}
		edge(int a, int b){to = a, cost = b;}
	};
	
	int n;
	vector<vector<edge> > G;
	vector<int> parent;
	vector<T> dp, dp2, ans;
	vector<T> lsum, rsum;
	
	Rerooting(){};
	Rerooting(int n){
		this->n = n;
		init();
	}
	void init(){
		G.clear(), G.resize(n+1);
		parent.resize(n+1);
		dp.resize(n+1), dp2.resize(n+1);
		lsum.resize(n+1), rsum.resize(n+1);
		ans.resize(n+1);
	}
	void add_edge(int u, int v, int w){
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
	}
	
	T Ident(){ //
		return array<mint, 3>();
	}
	T ope(T a, int w){ //
		a[2] = a[2] + a[1]*2*w + a[0]*w*w;
		a[1] = a[1] + a[0]*w;
		return a;
	}
	T ope2(T a, T b){ //
		rep(i, 0, 2) a[i] += b[i];
		return a;
	}
	T ope3(int v, T sum){ //
		sum[0] += 1;
		return sum;
	}
	
	T& get(int u, int v){
		if(parent[u] == v) return dp2[u];
		else return dp[v];
	}
	
	void dfs(int v, int p)
	{
		parent[v] = p;
		for(auto e : G[v]) if(e.to != p) dfs(e.to, v);
		
		T sum = Ident();
		for(auto e : G[v]) if(e.to != p) sum = ope2(sum, ope(get(v, e.to), e.cost));
		dp[v] = ope3(v, sum);
	}
	void dfs2(int v, int p)
	{
		ll m = sz(G[v]); T sum;
		
		sum = lsum[0] = Ident();
		rep(i, 0, m-1){
			sum = ope2(sum, ope(get(v, G[v][i].to), G[v][i].cost));
			lsum[i+1] = sum;
		}
		sum = rsum[m+1] = Ident();
		per(i, m-1, 0){
			sum = ope2(sum, ope(get(v, G[v][i].to), G[v][i].cost));
			rsum[i+1] = sum;
		}
		reps(i, G[v]){
			int u = G[v][i].to;
			if(u == p) continue;
			T sum = ope2(lsum[i], rsum[i+2]);
			dp2[u] = ope3(v, sum);
		}
		for(auto e : G[v]) if(e.to != p) dfs2(e.to, v);
	}
	
	void calc(){
		dfs(1, -1), dfs2(1, -1);
		rep(i, 1, n){
			T sum = Ident();
			for(auto e : G[i]) sum = ope2(sum, ope(get(i, e.to), e.cost));
			ans[i] = ope3(i, sum);
		}
	}
	void print(){
		rep(i, 1, n) for(auto e : G[i]) outl(i, "->", e.to, ":", get(i, e.to));
	}
};

ll n, Q;
vector<ll> G[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	Rerooting rt(n);
	LCA lca(n);
	
	ll u, v, w;
	rep(i, 1, n-1){
		cin >> u >> v >> w;
		rt.add_edge(u, v, w);
		lca.add_edge(u, v, w);
	}
	
	rt.calc();
	lca.calc();
	
	cin >> Q;
	rep(i, 1, Q){
		cin >> u >> v;
		mint ans;
		if(lca.getLCA(u, v) == v){
			ans = rt.ans[u][2];
			if(v != 1){
				ll p = lca.prev[v][0], d = lca.getDist(u, p);
				ans -= (rt.get(v, p)[0]*d*d + rt.get(v, p)[1]*2*d + rt.get(v, p)[2])*2;
			}
		}
		else{
			ll d = lca.getDist(u, v), w = lca.getNext(v, u);
			ans = (rt.get(w, v)[0]*d*d + rt.get(w, v)[1]*2*d + rt.get(w, v)[2])*2;
			ans -= rt.ans[u][2];
		}
		cout << ans << "\n";
	}
	return 0;
}