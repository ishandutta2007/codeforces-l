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


//ax+by = gcd(a, b)(x, y)gcd(a, b)
llint extgcd(llint a, llint b, llint &x, llint &y)
{
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	llint xx, yy;
	llint d = extgcd(b, a%b, xx, yy);
	x = yy, y = xx-(a/b)*yy;
	return d;
}

//a^{-1} (mod m)(gcd(a, m)!=1)-1
llint mod_inverse(llint a, llint m)
{
	llint x, y;
	if(extgcd(a, m, x, y) != 1) return -1;
	return (x%m + m) % m;
}

llint mul(llint a, llint n, llint mod){
	if(n == 0) return 0;
	if(n % 2) return (mul(a, n-1, mod) + a) % mod;
	else return mul(a, n/2, mod) * 2 % mod;
}
//ax = b (mod m)x(mod m/gcd(a, m))(b%gcd(a, m)!=0)(0, -1)
P congruence(llint a, llint b, llint m)
{
	llint d = gcd(a, m);
	if(b % d) return make_pair(0, -1);
	a /= d, b /= d, m /= d;
	return P(mul(b%m, mod_inverse(a, m)%m, m), m);
}

//a_i*x = b_i (mod m_i)(i = 1, 2, ..., n)(x, M)(0, -1)
P SimultaneousCongruence(llint a[], llint b[], llint m[], llint n)
{
	llint x = 0, M = 1;
	for(int i = 1; i <= n; i++){
		P res = congruence(a[i]*M, (b[i]-a[i]*x%m[i]+m[i])%m[i], m[i]);
		if(res.second == -1) return res;
		x += M*res.first, M *= res.second;
	}
	return make_pair(x, M);
}


struct SWAG{
	typedef P T;
	
	llint size;
	stack<T> head, tail;
	T rsum;
	
	SWAG(){init();}
	
	T Ident(){ //e
		return P(0, 1);
	}
	T ope(T x, T y){  //(x * y)
		if(x.second == -1 || y.second == -1) return P(0, -1);
		ll a[] = {0, 1, 1}, b[] = {0, x.first, y.first}, m[] = {0, x.second, y.second};
		return SimultaneousCongruence(a, b, m, 2);
	}
	void init(){
		size = 0;
		while(head.size()) head.pop();
		while(tail.size()) tail.pop();
		rsum = Ident();
	}
	void push(T x){
		size++;
		rsum = ope(rsum, x);
		tail.push(x);
	}
	void pop(){
		if(size == 0) return;
		if(head.size() == 0){
			T sum = Ident();
			while(tail.size()){
				T x = tail.top();
				sum = ope(x, sum);
				head.push(sum);
				tail.pop();
			}
			rsum = Ident();
		}
		head.pop();
		size--;
	}
	T query(){
		T ret = rsum;
		if(head.size()) ret = ope(head.top(), ret);
		return ret;
	}
};

ll n, m;
ll k[100005];
vector<P> vec[100005];
SWAG swag;

ll calc(vector<P> &vec)
{
	if(sz(vec) < 0) return -inf;
	swag.init();
	
	//outl(vec);
	
	ll n = sz(vec), r = -1, ret = 0;
	rep(i, 0, n-1){
		while(r+1 < n){
			r++;
			swag.push(vec[r]);
			//outl(i, r, swag.query());
			if(swag.query().second != -1) chmax(ret, r-i+1);
			else break;
		}
		swag.pop();
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll x;
	rep(i, 1, n){
		cin >> k[i];
		rep(j, 0, k[i]-1) cin >> x, vec[x].push_back(P(i, j));
	}
	
	rep(i, 1, m){
		vector<P> tmp; ll ans = 0;
		reps(j, vec[i]){
			if(j > 0 && vec[i][j].first > vec[i][j-1].first+1){
				chmax(ans, calc(tmp));
				tmp.clear();
			}
			tmp.push_back(P(vec[i][j].second, k[vec[i][j].first]));
		}
		chmax(ans, calc(tmp));
		cout << ans << "\n";
	}
	
	return 0;
}