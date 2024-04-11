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

struct UnionFind{
	int size;
	vector<int> parent;
	vector<int> rank;
	vector<ll> v, e;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		rank.resize(size+1);
		v.resize(size+1);
		e.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++){
			parent[i] = i, rank[i] = 0;
			v[i] = 1, e[i] = 0;
		}
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	void merge(int i, int j){ // j will become new root
		parent[i] = j;
		v[j] += v[i];
		e[j] += e[i] + 1;
	}
	void unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j){
			e[root_i]++;
			return;
		}
		if(rank[root_i] < rank[root_j]) merge(root_i, root_j);
		else merge(root_j, root_i);
		if(rank[root_i] == rank[root_j]) rank[root_i]++;
	}
};

void bfs(vector<ll> G[], int n, int S, ll dist[], ll pre[])
{
	queue<int> Q;
	Q.push(S);
	
	for(int i = 0; i <= n; i++) dist[i] = inf, pre[i] = -1;
	dist[S] = 0;
	
	while(Q.size()){
		int v = Q.front();
		Q.pop();
		for(auto u : G[v]){
			if(dist[u] < inf/2) continue;
			Q.push(u);
			dist[u] = dist[v] + 1, pre[u] = v;
		}
	}
}


ll T;
ll n, m;
vector<P> evec;
vector<ll> G[1000005];
ll dist[1000005], pre[1000005];
ll color[1000005];
vector<ll> vec[1000005];
ll dif[2000005];

bool dfs(int v, int p, int c)
{
	color[v] = c;
	for(auto u : G[v]){
		if(u == p) continue;
		if(color[u] == -c) continue;
		if(color[u] == c) return false;
		if(!dfs(u, v, -c)) return false;
	}
	return true;
}

void add(ll l, ll r, ll c)
{
	l = modulo(l, c), r = modulo(r, c);
	if(l > r) r += c;
	dif[l]++, dif[r]--;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m;
		evec.clear();
		ll u, v;
		rep(i, 1, m){
			cin >> u >> v;
			if(u > v) swap(u, v);
			evec.pb(P(u, v));
		}
		rep(i, 1, n) G[i].clear();
		for(auto p : evec){
			u = p.fi, v = p.se;
			G[u].pb(v), G[v].pb(u);
		}
		
		bfs(G, n, 1, dist, pre);
		
		u = v = -1;
		for(auto p : evec){
			if(dist[p.fi] % 2 == dist[p.se] % 2){
				u = p.fi, v = p.se;
				break;
			}
		}
		if(u == -1){
			rep(i, 1, n) color[i] = 0;
			dfs(1, -1, 1);
			yes();
			rep(i, 1, n){
				if(color[i] > 0) cout << 1;
				else cout << 0;
			}
			cout << endl;
			continue;
		}
		
		set<P> S;
		if(u > v) swap(u, v);
		S.insert(P(u, v));
		
		vector<ll> uvec, vvec;
		uvec.pb(u), vvec.pb(v);
		while(u != v){
			ll p, q;
			if(dist[u] > dist[v]){
				p = pre[u], q = u;
				u = p;
				uvec.pb(u);
			}
			else{
				p = pre[v], q = v;
				v = p;
				vvec.pb(v);
			}
			if(p > q) swap(p, q);
			S.insert(P(p, q));
		}
		vvec.pop_back();
		reverse(all(vvec));
		uvec.insert(uvec.end(), all(vvec));
		
		UnionFind uf(n);
		rep(i, 1, n) G[i].clear();
		for(auto p : evec){
			if(S.count(p)) continue;
			G[p.fi].pb(p.se), G[p.se].pb(p.fi);
			uf.unite(p.fi, p.se);
		}
		
		rep(i, 1, n) color[i] = 0;
		bool ans = true;
		rep(i, 1, n){
			if(color[i]) continue;
			if(!dfs(i, -1, 1)){
				ans = false;
				break;
			}
		}
		if(!ans){
			no();
			continue;
		}
		
		ll c = sz(uvec);
		rep(i, 1, n) vec[i].clear();
		rep(i, 0, c-1){
			ll v = uvec[i];
			vec[uf.root(v)].pb(i);
		}
		
		//outl(uvec);
		//for(auto u : uvec) cout << color[u] << " "; cout << endl;
		
		rep(i, 0, 2*c) dif[i] = 0;
		rep(i, 1, n){
			if(sz(vec[i]) <= 1) continue;
			//outl(vec[i]);
			vector<ll> pvec[2];
			for(auto x : vec[i]){
				rep(j, -2, 2){
					ll col = (color[uvec[x]]+1)/2, pos = x + j*c;
					pvec[abs(col+pos)%2].pb(pos);
				}
			}
			sort(all(pvec[0])), sort(all(pvec[1]));
			for(auto x : vec[i]){
				rep(j, 0, 1){
					ll pos = x + j*c, col = (color[uvec[x]]+1)/2;
					auto it = lower_bound(all(pvec[(pos+col+1)%2]), pos);
					add(pos, *it, c), add(*(it-1), pos, c);
				}
			}
		}
		
		rep(i, 1, 2*c-1) dif[i] += dif[i-1];
		rep(i, c, 2*c-1) dif[i-c] += dif[i];
		
		//outa(dif, 0, c-1);
		
		P mx = P(-inf, -inf);
		rep(i, 0, c-1) chmax(mx, P(dif[i], i));
		u = uvec[mx.se], v = uvec[(mx.se+1)%c];
		if(u > v) swap(u, v);
		
		rep(i, 1, n) G[i].clear();
		for(auto p : evec){
			if(p == P(u, v)) continue;
			G[p.fi].pb(p.se), G[p.se].pb(p.fi);
		}
		
		ans = true;
		rep(i, 1, n) color[i] = 0;
		if(!dfs(u, -1, 1)) ans = false;
		if(!color[v]){
			if(!dfs(v, -1, 1)) ans = false;
		}
		
		if(ans){
			yes();
			rep(i, 1, n){
				if(color[i] > 0) cout << 1;
				else cout << 0;
			}
			cout << endl;
		}
		else no();
	}
	
	return 0;
}