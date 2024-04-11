#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll powmod(ll a, ll p, ll modd) {
	if (p==0) return 1;
	if (p%2==0) {
		a=powmod(a, p/2, modd);
		return (a*a)%modd;
	}
	return (a*powmod(a, p-1, modd))%modd;
}

ll invp(ll a, ll p) {
	return powmod(a, p - 2, p);
}

vector<ll> solve(vector<ll> S, ll mod) {
	vector<ll> C = {1};
	vector<ll> B = {1};
	ll L = 0;
	ll m = 1;
	ll b = 1;
	ll N = S.size();
	for (ll i = 0; i < N; i++) {
		ll d = S[i];
		for (ll j = 1; j <= L; j++) {
			d += C[j]*S[i - j];
			d %= mod;
		}
		if (d == 0) {
			m++;
		} else if (2*L <= i) {
			vector<ll> T = C;
			ll a = (invp(b, mod)*d)%mod;
			for (int j=0;j<i+1-2*L;j++){
				C.push_back(0);
			}
			L=i+1-L;
			for (ll j = m; j <= L; j++) {
				C[j] -= a*B[j - m];
				C[j] %= mod;
			}
			B = T;
			b = d;
			m = 1;
		} else {
			ll a = (invp(b, mod)*d)%mod;
			for (ll j = m; j < m+(int)B.size(); j++) {
				C[j] -= a*B[j - m];
				C[j] %= mod;
			}
			m++;
		}
	}
	for (ll i = 0; i <= L; i++) {
		C[i] += mod;
		C[i] %= mod;
	}
	return C;
}

struct LinearRecurrence {
	vector<vector<ll> > mat;
	vector<ll> seq;
	ll mod;
	vector<vector<ll> > mul(vector<vector<ll> > a, vector<vector<ll> > b) {
		int n=a.size();
		vector<vector<ll> > ret(n);
		for (int i=0;i<n;i++){
			ret[i].resize(n);
			for (int j=0;j<n;j++){
				ret[i][j]=0;
				for (int k=0;k<n;k++){
					ret[i][j]+=a[i][k]*b[k][j];
					ret[i][j]%=mod;
				}
			}
		}
		return ret;
	}
	vector<vector<ll> > pot(vector<vector<ll> > m, ll p) {
		if (p==1) return m;
		if (p%2==0) {
			m=pot(m, p/2);
			return mul(m, m);
		}
		else{
			return mul(m, pot(m, p-1));
		}
	}
	ll get(ll i){
		if (i<(ll)mat.size()){
			return seq[i];
		}
		vector<vector<ll> > a=pot(mat, i-(ll)mat.size()+1);
		ll v=0;
		for (int i=0;i<(int)mat.size();i++){
			v+=a[0][i]*seq[(int)mat.size()-i-1];
			v%=mod;
		}
		return v;
	}
	LinearRecurrence(vector<ll> S, ll mod_) {
		seq=S;
		mod=mod_;
		vector<ll> C=solve(S, mod);
		int n=C.size()-1;
		mat.resize(n);
		for (int i=0;i<n;i++) {
			mat[i].resize(n);
		}
		for (int i=0;i<n;i++){
			mat[0][i]=(mod-C[i+1])%mod;
		}
		for (int i=1;i<n;i++){
			mat[i][i-1]=1;
		}
	}
};

ll mod=1e9+7;

ll dp[1111][111];
ll a[111];
int g[111][111];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll k;
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>a[i];
		dp[0][i]=1;
	}
	for (int i=0;i<n;i++){
		for (int ii=0;ii<n;ii++){
			if (__builtin_popcountll(a[i]^a[ii])%3==0){
				g[i][ii]=1;
			}
		}
	}
	vector<ll> dpp;
	for (int i=0;i<777;i++){
		ll su=0;
		for (int j=0;j<n;j++){
			dp[i][j]%=mod;
			su+=dp[i][j];
			su%=mod;
			for (int jj=0;jj<n;jj++){
				if (g[j][jj]){
					dp[i+1][jj]+=dp[i][j];
				}
			}
		}
		dpp.push_back(su);
	}
	LinearRecurrence lr(dpp, mod);
	cout<<lr.get(k-1)<<endl;
}