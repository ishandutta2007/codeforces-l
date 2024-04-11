#include <iostream>
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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define per(x, s, t) for(llint (x) = (s); (x) >= (t); (x)--)
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define sz(x) ((ll)(x).size())
#define ceil(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(...) dump_func(__VA_ARGS__)
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<ll, ll> P;

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){ to = a, cost = b;}
};
const ll dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

ll mod;
//const ll mod = 1000000007;
//const ll mod = 998244353;

struct mint{
	ll x = 0;
	mint(ll y = 0){x = y; if(x < 0 || x >= mod) x = (x%mod+mod)%mod;}
	mint(const mint &ope) {x = ope.x;}
	
	mint operator-(){return mint(-x);}
	mint operator+(const mint &ope){return mint(x) += ope;}
	mint operator-(const mint &ope){return mint(x) -= ope;}
	mint operator*(const mint &ope){return mint(x) *= ope;}
	mint operator/(const mint &ope){return mint(x) /= ope;}
	mint& operator+=(const mint &ope){
		x += ope.x;
		if(x >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint &ope){
		x += mod - ope.x;
		if(x >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint &ope){
		x *= ope.x, x %= mod;
		return *this;
	}
	mint& operator/=(const mint &ope){
		ll n = mod-2; mint mul = ope;
		while(n){
			if(n & 1) *this *= mul;
			mul *= mul;
			n >>= 1;
		}
		return *this;
	}
	mint inverse(){return mint(1) / *this;}
	bool operator ==(const mint &ope){return x == ope.x;}
	bool operator !=(const mint &ope){return x != ope.x;}
};
/*mint modpow(mint a, ll n){
	if(n == 0) return mint(1);
	if(n % 2) return a * modpow(a, n-1);
	else return modpow(a*a, n/2);
}*/
istream& operator >>(istream &is, mint &ope){
	ll t; is >> t, ope.x = t;
	return is;
}
ostream& operator <<(ostream &os, mint &ope){return os << ope.x;}
ostream& operator <<(ostream &os, const mint &ope){return os << ope.x;}

bool exceed(ll x, ll y, ll m){return x >= m / y + 1;}
void mark(){ cout << "*" << endl; }
void yes(){ cout << "YES" << endl; }
void no(){ cout << "NO" << endl; }
ll sgn(ll x){ if(x > 0) return 1; if(x < 0) return -1; return 0;}
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){return a/gcd(a, b)*b;}
ll digitnum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret++; return ret;}
ll digitsum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret += x % b; return ret;}
string lltos(ll x){string ret; for(;x;x/=10) ret += x % 10 + '0'; reverse(ret.begin(), ret.end()); return ret;}
ll stoll(string &s){ll ret = 0; for(auto c : s) ret *= 10, ret += c - '0'; return ret;}
template<typename T>
void uniq(T &vec){ sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}

template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for(int i = 0; i < vec.size(); i++) os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	return os;
}
template<typename T>
ostream& operator << (ostream& os, deque<T>& deq) {
	for(int i = 0; i < deq.size(); i++) os << deq[i] << (i + 1 == deq.size() ? "" : " ");
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, pair<T, U>& pair_var) {
	os << "(" << pair_var.first << ", " << pair_var.second << ")";
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& pair_var) {
	os << "(" << pair_var.first << ", " << pair_var.second << ")";
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, map<T, U>& map_var) {
	for(typename map<T, U>::iterator itr = map_var.begin(); itr != map_var.end(); itr++) {
		os << "(" << itr->first << ", " << itr->second << ")";
		itr++; if(itr != map_var.end()) os << ","; itr--;
	}
	return os;
}
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
	for(typename set<T>::iterator itr = set_var.begin(); itr != set_var.end(); itr++) {
		os << *itr; ++itr; if(itr != set_var.end()) os << " "; itr--;
	}
	return os;
}
template<typename T>
ostream& operator << (ostream& os, multiset<T>& set_var) {
	for(typename multiset<T>::iterator itr = set_var.begin(); itr != set_var.end(); itr++) {
		os << *itr; ++itr; if(itr != set_var.end()) os << " "; itr--;
	}
	return os;
}
template<typename T>
void outa(T a[], ll s, ll t){
	for(ll i = s; i <= t; i++){ cout << a[i]; if(i < t) cout << " ";}
	cout << endl;
}
void dump_func() {cout << endl;}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
	cout << head;
	if(sizeof...(Tail) > 0) cout << " ";
	dump_func(std::move(tail)...);
}

ll n;
vector<edge> G[100005];
bool prime[100005];
ll beki[100005], beki2[100005];
ll ans;
int Size[200005];
bool used[200005];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

int sizedfs(int v, int pre)
{
	int ret = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == pre) continue;
		if(used[G[v][i].to]) continue;
		ret += sizedfs(G[v][i].to, v);
	}
	return Size[v] = ret;
}

int centdfs(int v, int pre, int sz)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == pre) continue;
		if(used[G[v][i].to]) continue;
		if(Size[G[v][i].to] > sz/2) return centdfs(G[v][i].to, v, sz);
	}
	return v;
}

vector<P> vec[100005];
map<ll, ll> mp[100005];

void dfs(int v, int p, int d, ll x, ll y, ll s)
{
	vec[s].push_back(P(x, d));
	mp[s][y]++;
	for(auto e : G[v]){
		ll u = e.to, c = e.cost;
		if(u == p) continue;
		if(used[u]) continue;
		dfs(u, v, d+1, (x*10+c)%mod, (y+beki[d]*c)%mod, s);
	}
}

void solve(int v)
{
	sizedfs(v, -1);
	v = centdfs(v, -1, Size[v]);
	
	for(auto e : G[v]){
		ll u = e.to, c = e.cost;
		if(used[u]) continue;
		vec[u].clear(), mp[u].clear();
		dfs(u, v, 1, c%mod, c%mod, u);
	}
	
	map<ll, ll> tmp;
	for(auto e : G[v]){
		ll u = e.to; if(used[u]) continue;
		for(auto p : vec[u]){
			//outl(v, u, p, (mod-p.first)*beki2[p.second]%mod);
			ans += tmp[(mod-p.first)*beki2[p.second]%mod];
			if(p.first == 0) ans++;
		}
		for(auto p : mp[u]){
			tmp[p.first] += p.second;
			if(p.first == 0) ans += p.second;
		}
	}
	
	//outl(ans);
	
	tmp.clear(); reverse(all(G[v]));
	for(auto e : G[v]){
		ll u = e.to; if(used[u]) continue;
		for(auto p : vec[u]){
			ans += tmp[(mod-p.first)*beki2[p.second]%mod];
		}
		for(auto p : mp[u]) tmp[p.first] += p.second;
	}
	
	//outl(v, ans);
	
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i].to]) continue;
		solve(G[v][i].to);
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 2, 1005){
		if(prime[i]) continue;
		for(int j = 2*i; j < 100005; j += i) prime[j] = true;
	}
	
	cin >> n >> mod;
	ll u, v, w;
	rep(i, 1, n-1){
		cin >> u >> v >> w;
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
	}
	
	map<ll, ll> mp;
	ll t = mod;
	rep(i, 2, 100000){
		if(prime[i]) continue;
		while(t % i == 0){
			mp[i]++;
			t /= i;
		}
	}
	if(t > 1) mp[t] = 1;
	
	ll eu = 1;
	for(auto p : mp){
		rep(j, 1, p.second-1) eu *= p.first;
		eu *= p.first-1;
	}
	eu--;
	ll inv = modpow(10, eu);
	
	beki[0] = beki2[0] = 1;
	rep(i, 1, n) beki[i] = beki[i-1] * 10 % mod;
	rep(i, 1, n) beki2[i] = beki2[i-1] * inv % mod;
	
	solve(1);
	outl(ans);
	
	return 0;
}