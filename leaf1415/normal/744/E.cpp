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

const ll mod = 1000000007;
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
mint modpow(mint a, ll n){
	if(n == 0) return mint(1);
	if(n % 2) return a * modpow(a, n-1);
	else return modpow(a*a, n/2);
}
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
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
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

void z_algorithm(string &s, int z[])
{
	z[0] = s.size();
	
	int x = 0, y = 0;
	for(int i = 1; i < s.size(); i++){
		if(i > y){
			z[i] = 0;
			for(int j = 0; j < s.size(); j++){
				if(i+j >= s.size() || s[i+j] != s[j]) break;
				z[i]++;
			}
			x = i, y = i + z[i] - 1;
		}
		else if(i + z[i-x] <= y) z[i] = z[i-x];
		else{
			z[i] = y-i+1;
			for(int j = y-i+1; j < s.size(); j++){
				if(i+j >= s.size() || s[i+j] != s[j]) break;
				z[i]++;
			}
			x = i, y = i + z[i] - 1;
		}
	}
}


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
	void compressSCC(bool simple = false){ //calcSCC()scc::compG
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

ll n;
string s[35];
P p[100005];
map<P, ll> mp;
vector<P> vec[35];
int z[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> s[i];
	
	ll id = 0;
	rep(i, 1, n){
		reps(j, s[i]) id++, p[id] = P(i, j), mp[p[id]] = id;
	}
	ll S = id;
	
	rep(i, 1, n) vec[i].push_back(P(0, mp[P(i, 0)]));
	rep(i, 1, n){
		rep(j, 1, n){
			string str = s[j] + "#" + s[i];
			z_algorithm(str, z);
			reps(k, s[i]){
				if(k == 0 && i == j) continue;
				ll I = sz(s[i]), J = sz(s[j]), v = mp[P(i, k)], nv;
				if(I-k < J) nv = mp[P(j, I-k)];
				if(I-k == J) nv = 0;
				if(I-k > J) nv = mp[P(i, k+J)];
				if(z[J+1+k] == min(I-k, J)) vec[j].push_back(P(v, nv));
			}
		}
	}
	
	/*rep(i, 1, n){
		for(auto e : vec[i]){
			P f = p[e.first], t = p[e.second];
			outl(s[f.first].substr(f.second), s[i], s[t.first].substr(t.second));
		}
	}*/
	
	ll ans = 0;
	rep(i, 1, n){
		SCC scc(S+1); set<string> S;
		rep(j, i, n){
			if(S.count(s[j])){
				ans++;
				continue;
			}
			
			S.insert(s[j]);
			for(auto p : vec[j]) scc.add_edge(p.first+1, p.second+1);
			scc.tpsort();
			if(scc.checkDAG()) ans++;
			else break;
		}
	}
	outl(ans);
	
	return 0;
}