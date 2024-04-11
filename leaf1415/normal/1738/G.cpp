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
template<class T> T mdist(pair<T, T> s, pair<T, T> t){return abs(s.first-t.first) + abs(s.second-t.second);}
template<class T> T cdist(pair<T, T> s, pair<T, T> t){return max(abs(s.first-t.first), abs(s.second-t.second));}
template<class T> T edist2(pair<T, T> s, pair<T, T> t){return (s.first-t.first)*(s.first-t.first) + (s.second-t.second)*(s.second-t.second);}

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

struct SegTree{
	typedef P SEG;
	
	int size;
	vector<SEG> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	SEG id(){  //identity element
		return P(-inf, -inf);
	}
	SEG ope(SEG a, SEG b){ //operator
		return max(a, b);
	}
	bool comp(SEG a, SEG b){
		return a >= b;
	}
	
	void init(){
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = id();
	}
	void set(int i, SEG x){
		seg[i+(1<<size)] = x;
	}
	void setup(){
		for(int i = (1<<size)-1; i >= 1; i--) seg[i] = ope(seg[i*2], seg[i*2+1]);
	}
	void update(int i, SEG val){
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = ope(seg[i*2], seg[i*2+1]);
		}
	}
	SEG query(int a, int b, int k, int l, int r){
		if(b < l || r < a) return id();
		if(a <= l && r <= b) return seg[k];
		SEG lval = query(a, b, k*2, l, (l+r)/2);
		SEG rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return ope(lval, rval);
	}
	SEG query(int a, int b){
		if(a > b) return id();
		return query(a, b, 1, 0, (1<<size)-1);
	}
	int left_find(int r, SEG x){ //return largest l s.t. comp(query(l, r), x) = true
		int k = r + (1<<size);
		if(comp(seg[k], x)) return r;
		
		SEG sum = seg[k];
		while(1){
			if((k&(k-1)) == 0) return -1;
			if(comp(ope(seg[k-1], sum), x)) break;
			if(k % 2) sum = ope(seg[k-1], sum);
			k /= 2;
		}
		k--;
		while(k < (1<<size)){
			if(comp(ope(seg[k*2+1], sum), x)) k = k*2+1;
			else sum = ope(seg[k*2+1], sum), k = k*2;
		}
		return k - (1<<size);
	}
	int right_find(int l, SEG x){ //return smallest r s.t. comp(query(l, r), x) = true
		int k = l + (1<<size);
		if(comp(seg[k], x)) return l;
		
		SEG sum = seg[k];
		while(1){
			if((k&(k+1)) == 0) return 1<<(size+1);
			if(comp(ope(sum, seg[k+1]), x)) break;
			if(k % 2 == 0) sum = ope(sum, seg[k+1]);
			k /= 2;
		}
		k++;
		while(k < (1<<size)){
			if(comp(ope(sum, seg[k*2]), x)) k = k*2;
			else sum = ope(sum, seg[k*2]), k = k*2+1;
		}
		return k - (1<<size);
	}
};

ll T;
ll n, k;
char c[1005][1005];
vector<ll> vec[1005];
ll ans[1005][1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(y, 1, n) rep(x, 1, n) cin >> c[x][y];
		
		rep(x, 1, n) vec[x].clear();
		rep(y, 1, n) rep(x, 1, n) ans[x][y] = 0;
		
		k--;
		rep(i, 1, k) c[n][i] = c[i][n] = '0';
		rep(y, 1, n) rep(x, 1, n){
			if(c[x][y] == '0') vec[x].pb(y);
		}
		rep(x, 1, n) vec[x].pb(-inf), sort(all(vec[x]));
		
		SegTree seg(digitnum(n+5, 2));
		seg.init();
		rep(x, 1, n) seg.set(x, P(vec[x].back(), -x));
		seg.setup();
		
		per(i, k, 1){
			ll x = i, y = n, tx = i, ty = n;
			while(x != n || y != i){
				ans[x][y] = 1;
				if(tx == x && ty == y){
					vec[x].pop_back();
					seg.update(x, P(vec[x].back(), -x));
					P res = seg.query(x, n);
					tx = -res.se, ty = res.fi;
				}
				if(tx == x) y--;
				else{
					if(ans[x+1][y]) y--;
					else x++;
				}
			}
			ans[x][y] = 1;
			vec[x].pop_back();
			seg.update(x, P(vec[x].back(), -x));
		}
		
		bool flag = true;
		rep(y, 1, n) rep(x, 1, n){
			if(c[x][y] == '0' && ans[x][y] == 0) flag = false;
		}
		
		if(flag){
			cout << "YES" << "\n";
			rep(y, 1, n){
				rep(x, 1, n) cout << ans[x][y];
				cout << "\n";
			}
		}
		else cout << "NO" << "\n";
		
	}
	
	return 0;
}