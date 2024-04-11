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
#define fi first
#define se second
#define inf 2e18
#define eps 1e-16
const double PI = 3.1415926535897932384626433;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
#define double long double

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){ to = a, cost = b;}
};
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

const int mod = 1000000009;
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

struct Matrix{
	typedef double T;
	
	int h, w;
	vector<T> mat;
	Matrix(){h = w = 0;}
	Matrix(int h, int w){
		this->h = h, this->w = w;
		mat.resize(h*w);
	}
	
	T addope(T a, T b){ return a+b; } //
	static T addIdent(){ return 0;} //
	T mulope(T a, T b){ return a*b; } //
	static T mulIdent(){ return 1; } //
	
	T& at(int i, int j){ return mat[w*(i-1)+(j-1)];}
	static Matrix Ident(int size){
		Matrix ret(size, size);
		rep(i, 1, size) rep(j, 1, size){
			if(i == j) ret.at(i, j) = mulIdent();
			else ret.at(i, j) = addIdent();
		}
		return ret;
	}
	Matrix operator+(Matrix& ope){
		Matrix ret(h, w);
		rep(i, 1, h) rep(j, 1, w) ret.at(i, j) = at(i, j) + ope.at(i, j);
		return ret;
	}
	Matrix operator*(Matrix& ope){
		Matrix ret(h, ope.w);
		rep(i, 1, h) rep(j, 1, ope.w){
			ret.at(i, j) = addIdent();
			rep(k, 1, w) ret.at(i, j) = addope(ret.at(i, j), mulope(at(i, k), ope.at(k, j)));
		}
		return ret;
	}
	Matrix pow(ll n){
		if(n == 0) return Ident(h);
		if(n % 2) return pow(n-1) * (*this);
		else{
			Matrix tmp = pow(n/2);
			return tmp * tmp;
		}
	}
};
ostream& operator << (ostream& os, Matrix& mat) {
	rep(i, 1, mat.h){rep(j, 1, mat.w) os << mat.mat[mat.w*(i-1)+(j-1)] << " "; cout << endl;}
	return os;
}
ostream& operator << (ostream& os, const Matrix& mat) {
	rep(i, 1, mat.h){rep(j, 1, mat.w) os << mat.mat[mat.w*(i-1)+(j-1)] << " "; cout << endl;}
	return os;
}

void swapRows(double mat[505][1005], int i, int j, int n)
{
	for(int k = 1; k <= 2*n; k++) swap(mat[i][k], mat[j][k]);
}
void GaussianElimination(double mat[505][1005], int n)
{
	int r = 1; double div;
	for(int i = 1; i <= n && r <= n; i++){
		if(fabs(mat[r][i]) < eps){
			double max_val = 0; int max_j;
			for(int j = r+1; j <= n; j++){
				if(fabs(mat[j][i]) > max_val){
					max_val = fabs(mat[j][i]);
					max_j = j;
				}
			}
			assert(fabs(max_val) >= eps);
			swapRows(mat, r, max_j, n);
		}
		
		div = mat[r][i];
		for(int j = 1; j <= 2*n; j++) mat[r][j] /= div;
		
		for(int j = 1; j <= n; j++){
			double coe = mat[j][i];
			if(j == r || fabs(coe) < eps) continue;
			for(int k = 1; k <= 2*n; k++) mat[j][k] -= coe * mat[r][k];
		}
		r++;
		end:;
	}
}

ll n, m, k;
ll a[505];
vector<ll> G[505];
double mat[505][1005];

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m >> k;
	rep(i, 1, n) cin >> a[i];
	ll u, v;
	rep(i, 1, m){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	
	rep(i, 1, n){
		mat[i][i] = 1;
		double p = 1.0/sz(G[i]);
		for(auto u : G[i]){
			if(a[u]) mat[i][n+u] += p;
			else mat[i][u] -= p;
		}
	}
	GaussianElimination(mat, n);
	
	vector<ll> vec;
	rep(i, 1, n) if(a[i]) vec.pb(i);
	ll N = sz(vec);
	
	Matrix Mat = Matrix(N, N);
	rep(i, 0, N-1){
		rep(j, 0, N-1){
			u = vec[i], v = vec[j];
			Mat.at(j+1, i+1) = mat[u][n+v];
		}
	}
	Matrix pmat = Mat.pow(k-2);
	
	double ans = 0;
	rep(i, 0, N-1) ans += mat[1][n+vec[i]] * pmat.at(N, i+1);
	printf("%.30Lf", ans);
	
	return 0;
}