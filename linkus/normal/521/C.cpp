#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GET(arr) for(auto &i: (arr)) sc(i)
#define whatis(x) cerr << #x << " is " << (x) << endl;
#define e1 first
#define e2 second
#define INF 0x7f7f7f7f
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;
using namespace __gnu_pbds;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 110001

int n,k;
map<int,map<int,int>> il;
vector<pi> cr; //index,potega 10
void rec(int i, int wh){
    if(wh > k) return;
    if(i == n){
        if(wh != k) return;
        FORR(x,cr){
            ++il[x.e1][x.e2];
        }
        return;
    }
    for(int x = i; x < n; ++ x){
        int sz = x-i+1;
        int crr = 0;
        for(int j = x; j >= i; --j){
            cr.push_back({j,crr});
            ++crr;
        }
        rec(x+1,(x+1 == n ? wh : wh+1));
        FOR(i,0,sz)
            cr.pop_back();
    }
}

ll mod = 1e9+7;
inline int64_t fastpow(int64_t a, int64_t b){
    if(b == 0)
        return 1;
    if(b&1){
        return (a * fastpow(a,b^1)) % mod;
    }
    a = fastpow(a,b >> 1);
    return (a*a)%mod;
}
ll fact[N];
ll invf[N];
ll c(ll n, ll k){
    ll ret = fact[n];
    ret *= invf[k];
    ret %= mod;
    ret *= invf[n-k];
    ret %= mod;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n,k);
    /* rec(0,0); */
    /* whatis(il) */
    ll p10[n+1];
    p10[0] = 1;
    FORE(i,1,n)
        p10[i] = p10[i-1]*10%mod;
    string s;
    /* FOR(i,0,n) */
    /*     s += '0'+rand()%10; */
    getstr(s);
    FORR(i,s)
        i -= '0';
    if(!k){
        ll res = 0;
        FORR(i,s){
            res *= 10;
            res += i;
            res %= mod;
        }
        REE(res);
    }
    /* ll res2 = 0; */
    /* FOR(i,0,n){ */
    /*     FORR(x,il[i]){ */
    /*         res2 += p10[x.e1]*s[i]*x.e2; */
    /*         res2 %= mod; */
    /*     } */
    /* } */
    /* whatis(res2) */
    fact[0] = 1;
    FOR(i,1,N)
        fact[i] = fact[i-1]*i%mod;
    FOR(i,0,N){
        invf[i] = fastpow(fact[i],mod-2);
    }
    ll res = 0;
    ll mul = 0;
    ll now = n-k;
    FOR(x,0,n-k){
        ll lnow = c(k-2+now,k-1);
        /* whatis(k+now) */
        /* whatis(k-1) */
        mul += p10[x]*lnow;
        mul %= mod;
        --now;
    }
    FORE(i,0,k){
        res += s[i]*mul;
        res %= mod;
    }
    //wh -> jaki wywalamy
    ll wh =  n-k-1;
    now = 0; //acc
    ll xd = 1;
    /* whatis(mul) */
    /* whatis(res) */
    FOR(i,k+1,n){
        ll lxd = c(k-2+xd,k-1);
        now += lxd;
        now %= mod;
        /* whatis(now) */
        /* whatis(wh) */
        mul -= now*p10[wh];
        mul += now*p10[wh-1];
        mul = (mul%mod+mod)%mod;
        /* whatis(mul) */
        res += s[i]*mul;
        res %= mod;
        --wh;
        ++xd;
    }
    cout << res << '\n';
}