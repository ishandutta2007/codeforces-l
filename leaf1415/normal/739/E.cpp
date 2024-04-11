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
string tostr(ll x){string ret; for(;x;x/=10) ret += x % 10 + '0'; reverse(ret.begin(), ret.end()); return ret;}
ll toint(string &s){ll ret = 0; for(auto c : s) ret *= 10, ret += c - '0'; return ret;}
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



struct MinCostFlow{
	typedef llint CAP;
	typedef double COST; //doubledijkstra
	
	struct edge{
		int to, rev;
		CAP cap;
		COST cost;
		edge(){}
		edge(int a, CAP b, COST c, int d){
			to = a, cap = b, cost = c, rev = d;
		}
	};
	int n;
	vector<vector<edge> > G;
	vector<COST> dist;
	vector<int> prevv, preve;
	vector<COST> h;
	
	MinCostFlow(){}
	MinCostFlow(int n){
		this->n = n;
		G.resize(n+1);
		dist.resize(n+1);
		prevv.resize(n+1);
		preve.resize(n+1);
		h.resize(n+1);
	}
	void BellmanFord(int s)
	{
		for(int i = 0; i <= n; i++) dist[i] = inf;
		dist[s] = 0, prevv[s] = -1;
		
		bool update = true;
		while(update){
			update = false;
			for(int i = 0; i <= n; i++){
				for(int j = 0; j < G[i].size(); j++){
					if(G[i][j].cap == 0) continue;
					if(dist[G[i][j].to] > dist[i] + G[i][j].cost){
						dist[G[i][j].to] = dist[i] + G[i][j].cost;
						prevv[G[i][j].to] = i;
						preve[G[i][j].to] = j;
						update = true;
					}
				}
			}
		}
	}
	void Dijkstra(int s)
	{
		for(int i = 0; i <= n; i++) dist[i] = inf;
		dist[s] = 0, prevv[s] = -1;
		
		typedef pair<COST, int> P;
		priority_queue< P, vector<P>, greater<P> > Q;
		Q.push( make_pair(0, s) );
		
		int v; COST d;
		while(Q.size()){
			d = Q.top().first;
			v = Q.top().second;
			Q.pop();
			if(dist[v] < d) continue;
			for(int i = 0; i < G[v].size(); i++){
				if(G[v][i].cap == 0) continue;
				int u = G[v][i].to; COST c = h[v] - h[u] + G[v][i].cost;
				if(dist[u] > d + c + 1e-9){ //COSTdouble
					dist[u] = d + c;
					prevv[u] = v;
					preve[u] = i;
					Q.push( P(dist[u], u) );
				}
			}
		}
	}
	void add_edge(int from, int to, CAP cap, COST cost)
	{
		G[from].push_back( edge(to, cap, cost, G[to].size()) );
		G[to].push_back( edge(from, 0, -cost, G[from].size()-1) );
	}
	COST calc(int s, int t, CAP f)
	{
		BellmanFord(s);
		for(int i = 0; i <= n; i++) h[i] = dist[i];
		
		COST ret = 0;
		while(f > 0){
			Dijkstra(s);
			if(dist[t] >= inf) break;
			
			int p = t; CAP flow = f;
			while(prevv[p] != -1){
				flow = min(flow, G[prevv[p]][preve[p]].cap);
				p = prevv[p];
			}
			
			p = t;
			while(prevv[p] != -1){
				G[prevv[p]][preve[p]].cap -= flow;
				G[p][G[prevv[p]][preve[p]].rev].cap += flow;
				p = prevv[p];
			}
			f -= flow;
			ret += (dist[t] + h[t] - h[s]) * flow;
			
			for(int i = 0; i <= n; i++) h[i] += dist[i]; //(?)
		}
		if(f > 0) return -1;
		return ret;
	}
};

MinCostFlow mcf(2505);
ll n, a, b;
double p[2005], u[2005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b;
	rep(i, 1, n) cin >> p[i];
	rep(i, 1, n) cin >> u[i];

	ll S = n+1, T = n+2, A = n+3, B = n+4;
	mcf.add_edge(S, A, a, 0);
	rep(i, 1, n) mcf.add_edge(A, i, 1, -p[i]);
	mcf.add_edge(S, B, b, 0);
	rep(i, 1, n) mcf.add_edge(B, i, 1, -u[i]);
	rep(i, 1, n){
		mcf.add_edge(i, T, 1, 0);
		mcf.add_edge(i, T, 1, -(1-(1-p[i])*(1-u[i]) - (p[i]+u[i])));
	}
	mcf.add_edge(S, T, inf, 0);
	printf("%.11f\n", -mcf.calc(S, T, a+b));

	return 0;
}