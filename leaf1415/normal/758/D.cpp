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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define sz(x) ((ll)(x).size())
#define ceil(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(...) dump_func(__VA_ARGS__)
#define inf 1.5e18

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

bool exceed(ll x, ll y, ll m){return y > 0 && x >= m / y + 1;}
void mark(){ cout << "*" << endl; }
void yes(){ cout << "Yes" << endl; }
void no(){ cout << "No" << endl; }
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
ll digitnum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret++; return ret;}
ll digitsum(ll x, ll b = 10){ll ret = 0; for(; x; x /= b) ret += x % b; return ret;}

template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for(int i = 0; i < vec.size(); i++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}
template<typename T>
ostream& operator << (ostream& os, deque<T>& deq) {
	for(int i = 0; i < deq.size(); i++) {
		os << deq[i] << (i + 1 == deq.size() ? "" : " ");
	}
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
		itr++;
		if(itr != map_var.end()) os << ",";
		itr--;
	}
	return os;
}
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
	for(typename set<T>::iterator itr = set_var.begin(); itr != set_var.end(); itr++) {
		os << *itr;
		++itr;
		if(itr != set_var.end()) os << " ";
		itr--;
	}
	return os;
}
template<typename T>
void outa(T a[], ll s, ll t)
{
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

ll b, n;
string s;
ll dp[75][75];
const ll L = 1000000000000000000;

ll get(ll l, ll r)
{
	string t = s.substr(l, r-l+1);
	ll ret = 0, mul = 1;
	for(auto c : t){
		c -= '0';
		ret += c * mul;
		if(ret > b) return b;
		if(exceed(mul, 10, L)) return b;
		mul *= 10;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> b >> s;
	if(s == "0"){
		outl(0);
		return 0;
	}
	reverse(all(s));
	
	n = sz(s);
	rep(i, 0, n) rep(j, 0, 70) dp[i][j] = inf;
	dp[0][0] = 0;
	
	rep(i, 0, n-1){
		ll mul = 1;
		rep(j, 0, 70){
			rep(k, i, n-1){
				if(i < k && s[k] == '0') continue;
				ll res = get(i, k);
				if(exceed(mul, res, L) || res >= b) break;
				chmin(dp[k+1][j+1], dp[i][j] + res * mul);
			}
			if(exceed(mul, b, L)) break;
			mul *= b;
		}
	}
	
	ll ans = inf;
	rep(i, 0, 70) chmin(ans, dp[n][i]);
	outl(ans);
	
	return 0;
}