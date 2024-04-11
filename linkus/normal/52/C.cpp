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
#define INF 0x7F7F7F7F //2139062143 | 127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
#define umap unordered_map
#define uset unordered_set
using namespace std;
using namespace __gnu_pbds;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return c == 10 ? 0 : 1;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define N 200000
ll t[N << 2];
ll lazy[N << 2];

void build(ll v, ll tl, ll tr, ll arr[]){
    if(tl == tr){
        t[v] = arr[tl];
        return;
    }
    ll tm = (tl+tr)>>1;
    build(v<<1,tl,tm,arr);
    build(v<<1|1,tm+1,tr,arr);
    t[v] = min(t[v<<1],t[v<<1|1]);
}

void push(ll v){
    if(lazy[v]){
        t[v<<1] += lazy[v];
        t[v<<1|1] += lazy[v];
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1] += lazy[v];
        lazy[v] = 0;
    }
}

void modify(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r) return;
    if(tl == l && tr == r){
        t[v] += val;
        lazy[v] += val;
        return;
    }
    push(v);
    ll tm = (tl+tr)>>1;
    modify(v<<1,tl,tm,l,min(tm,r),val);
    modify(v<<1|1,tm+1,tr,max(l,tm+1),r,val);
    t[v] = min(t[v<<1],t[v<<1|1]);
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r) return 0x7f7f7f7f;
    if(tl == l && tr == r){
        return t[v];
    }
    push(v);
    ll tm = (tl+tr)>>1;
    return min(
        query(v<<1,tl,tm,l,min(tm,r)),
        query(v<<1|1,tm+1,tr,max(l,tm+1),r));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    sc(n);
    ll arr[n];
    GET(arr);
    build(1,0,n-1,arr);
    ll q,f,s,val;
    sc(q);
    while(q--){
        sc(f);
        if(sc(s)){
            sc(val);
            if(s >= f)
                modify(1,0,n-1,f,s,val);
            else
                modify(1,0,n-1,0,s,val),
                modify(1,0,n-1,f,n-1,val);
        }
        else{
            if(s >= f)
                cout << query(1,0,n-1,f,s) << '\n';
            else{
                cout << min(query(1,0,n-1,0,s),query(1,0,n-1,f,n-1)) << '\n';
            }
        }
    }
}