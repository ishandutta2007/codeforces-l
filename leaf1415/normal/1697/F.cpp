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
#define rall(x) (x).rbegin(),(x).rend()
#define outl(...) dump_func(__VA_ARGS__)
#define outf(x) cout << fixed << setprecision(16) << (x) << endl
#define pb push_back
#define fi first
#define se second
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

//const int mod = 1000000007;
const int mod = 998244353;

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
template<typename T> T comb2(ll n, ll k){ T ret = 1; rep(i, 1, k) ret *= n-k+i, ret /= i; return ret;}

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
string lltos(ll x, ll b = 10){string ret; for(;x;x/=b) ret += x % b + '0'; reverse(all(ret)); return ret;}
ll stoll(string &s, ll b = 10){ll ret = 0; for(auto c : s) ret *= b, ret += c - '0'; return ret;}
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
template<typename T> ostream& operator << (ostream& os, list<T>& ls){for(auto x : ls) os << x << " "; return os;}
template<typename T> ostream& operator << (ostream& os, const list<T>& ls){for(auto x : ls) os << x << " "; return os;}
template<typename T> ostream& operator << (ostream& os, deque<T>& deq){reps(i,  deq) os << deq[i] << " "; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, pair<T, U>& ope){ os << "(" << ope.first << ", " << ope.second << ")"; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& ope){ os << "(" << ope.first << ", " << ope.second << ")"; return os;}
template<typename T, typename U> ostream& operator << (ostream& os, map<T, U>& ope){ for(auto p : ope) os << "(" << p.first << ", " << p.second << "),";return os;}
template<typename T> ostream& operator << (ostream& os, set<T>& ope){for(auto x : ope) os << x << " "; return os;}
template<typename T> ostream& operator << (ostream& os, multiset<T>& ope){for(auto x : ope) os << x << " "; return os;}
template<typename T> void outa(T a[], ll s, ll t){rep(i, s, t){ cout << a[i]; if(i < t) cout << " ";} cout << endl;}
template<typename T, size_t N> ostream& operator << (ostream& os, array<T, N>& arr){reps(i, arr) os << arr[i] << " "; return os;}
template<typename T, size_t N> ostream& operator << (ostream& os, const array<T, N>& arr){reps(i, arr) os << arr[i] << " "; return os;}
void dump_func(){cout << endl;}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail){cout << head; if(sizeof...(Tail) > 0) cout << " "; dump_func(std::move(tail)...);}


struct SCC{
	int n;
	vector<vector<int> > G, revG, compG;
	vector<int> used, scc, topo;
	int sccid, sccnum;
	
	void tpdfs(int v)
	{
		used[v] = 1;
		for(int i = 0; i < G[v].size(); i++){
			if(!used[G[v][i]]) tpdfs(G[v][i]);
		}
		topo.push_back(v);
	}
	void sccdfs(int v, int id)
	{
		used[v] = 1;
		scc[v] = id;
		for(int i = 0; i < revG[v].size(); i++){
			if(!used[revG[v][i]]) sccdfs(revG[v][i], id);
		}
	}
	
	SCC(){}
	SCC(int n){  //V(G) = {1, 2, ..., n}, n
		this->n = n;
		G.resize(n+1);
		revG.resize(n+1);
		used.resize(n+1);
	}
	void init(){
		for(int i = 1; i <= n; i++){
			G[i].clear(), revG[i].clear();
			used[i] = 0;
		}
		topo.clear();
	}
	void add_edge(int u, int v)
	{
		G[u].push_back(v);
	}
	void tpsort()
	{
		topo.clear();
		for(int i = 1; i <= n; i++) used[i] = 0;
		for(int i = 1; i <= n; i++) if(!used[i]) tpdfs(i);
		reverse(topo.begin(), topo.end());
	}
	bool checkDAG(){ //tpsort()DAGtrue
		for(int i = 1; i <= n; i++) used[i] = 0;
		for(int i = 0; i < topo.size(); i++){
			int v = topo[i];
			used[v] = 1;
			for(int j = 0; j < G[v].size(); j++){
				if(used[G[v][j]]) return false;
			}
		}
		return true;
	}
	int calcSCC(){  //tpsort()SCCSCC-ID1-indexed
		scc.resize(n+1);
		for(int i = 1; i <= n; i++) revG[i].clear();
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < G[i].size(); j++){
				revG[G[i][j]].push_back(i);
			}
		}
		sccid = 1;
		for(int i = 1; i <= n; i++) used[i] = 0;
		for(int i = 0; i < topo.size(); i++) if(!used[topo[i]]) sccdfs(topo[i], sccid++);
		return sccnum = sccid-1;
	}
	void compressSCC(bool simple = false){ //calcSCC()SCC::compG
		compG.resize(sccnum+1);
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < G[i].size(); j++){
				int u = G[i][j];
				if(scc[i] != scc[u]) compG[scc[i]].push_back(scc[u]);
			}
		}
		if(simple){
			for(int i = 1; i <= sccnum; i++){
				sort(compG[i].begin(), compG[i].end());
				compG[i].erase(unique(compG[i].begin(), compG[i].end()), compG[i].end());
			}
		}
	}
	
};

struct TwoSat
{
	int n;
	SCC scc;
	vector<int> assign;
	
	TwoSat(){}
	TwoSat(int n)
	{
		this->n = n;
		scc = SCC(2*n+1);
	}
	void addClause(int a, int b) //(A or B)-1
	{
		scc.add_edge(-a+n+1, b+n+1);
		scc.add_edge(-b+n+1, a+n+1);
	}
	bool calc() //assign 1 or -1 
	{
		scc.tpsort(), scc.calcSCC();
		assign.resize(n+1);
		for(int i = 1; i <= n; i++){
			if(scc.scc[i+n+1] == scc.scc[-i+n+1]) return false;
			if(scc.scc[i+n+1] > scc.scc[-i+n+1]) assign[i] = 1;
			else assign[i] = -1;
		}
		return true;
	}
};

ll T;
ll n, m, k;

ll get(ll i, ll j){
	return (i-1)*k+j;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m >> k;

		TwoSat ts(n*k);
		rep(i, 1, n){
			ts.addClause(get(i, 1), get(i, 1));
			rep(j, 2, k) ts.addClause(-get(i, j), get(i, j-1));
		}
		rep(i, 1, n-1) rep(j, 1, k) ts.addClause(-get(i, j), get(i+1, j));
		
		ll t, p, q, x;
		rep(i, 1, m){
			cin >> t;
			if(t == 1){
				cin >> p >> x;
				if(x == k) ts.addClause(-get(p, x), -get(p, x));
				else ts.addClause(-get(p, x), get(p, x+1));
			}
			if(t == 2){
				cin >> p >> q >> x;
				rep(j, 1, k){
					if(x-j >= k) continue;
					if(x-j >= 1) ts.addClause(-get(p, j), -get(q, x-j+1));
					else ts.addClause(-get(p, j), -get(p, j));
				}
			}
			if(t == 3){
				cin >> p >> q >> x;
				rep(j, 1, k){
					if(x-j <= 0) continue;
					if(x-j <= k) ts.addClause(get(p, j+1), get(q, x-j));
					else ts.addClause(get(p, j+1), get(p, j+1));
				}
			}
		}
		
		if(!ts.calc()){
			outl(-1);
			continue;
		}
		
		rep(i, 1, n){
			per(j, k, 1) if(ts.assign[get(i, j)] > 0){
				cout << j << " ";
				break;
			}
		}
		cout << endl;
	}
	
	return 0;
}