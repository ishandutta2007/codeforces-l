#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ssize(x) int(x.size())
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define FORR(x,arr) for(auto &x: arr)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GET(arr) for(auto &i: (arr)) sc(i)
#define e1 first
#define e2 second
#define INF 0x7f7f7f7f
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "),...); }(x), cerr << '\n'
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;
using namespace std;
using namespace __gnu_pbds;

#ifdef ONLINE_JUDGE
#define debug(...) {}
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) { return o << '(' << p.first << ", " << p.second << ')'; }
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) { o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}'; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// 1 << 19 if segtree where merges matter.
#define N 1000001

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    /* int n = 5; */
    /* /1* vi v = {0,-1,-1,2,-1}; *1/ */
    /* vi v = {0,-1,-1,2,-1}; // 30, damn */
    /* /1* vi v = {0,1,2,3,4}; *1/ */
    /* /1* vi v = {-1,1,2,0,0}; *1/ */
    /* /1* vi v = {0,1,2,3,4}; *1/ */
    /* int a[n]; */
    /* iota(a,a+5,0); */
    /* int res = 0; */
    /* do{ */
    /*     bool kk = 1; */
    /*     REP(i,n){ */
    /*         int cr = 0; */
    /*         REP(x,i){ */
    /*             cr += a[x] > a[i]; */
    /*         } */
    /*         kk &= v[i] == -1 || v[i] == cr; */
    /*     } */
    /*     res += kk; */
    /* }while(next_permutation(a,a+n)); */
    /* cout << res << '\n'; */
    int t;
    sc(t);
    while(t--){
        int n,k;
        sc(n,k);
        int a[n];
        GET(a);
        constexpr ll mod = 998244353;
        ll res = 1;
        // imo dla i > n - k moe mi sens.
        REP(i,n){
            if(a[i] > i){
                res = 0;
            }
            else if(a[i] == -1){
                res *= i + 1;
                res %= mod;
            }
        }
        FOR(i,n-k,n-1){
            if(a[i] > 0)
                res = 0;
        }
        if(!res){
            res = 0;
        }
        else{
            res = 1; // nc xd.
            ll cr = 1;
            REP(i,n){
                int othind = i - k;
                if(othind < 0){
                    /* cr *= i; // cokolwiek. */
                    cr *= i + 1; // cokolwiek.
                    cr %= mod;
                }
                else{
                    if(a[othind] == 0){
                        // v[i] <= k
                        /* cr *= min(k, i); */
                        cr *= min(k + 1, i + 1);
                        cr %= mod;
                    }
                    // -1 case jeszcze xd.
                    else if(a[othind] == -1){
                        cr *= i + 1;
                        cr %= mod;
                    }
                    else{
                        // v[i] = a[othind] + k
                    }
                }
            }
            res *= cr;
            res %= mod;
        }
        cout << res << '\n';
    }
    /* int cas = 0; */
    /* /1* for(;;){ *1/ */
    /*     if(++cas%50 == 0) */
    /*         debug(cas); */
    /*     int n,k; */
    /*     k = 0, n = 8; */
    /*     int a[n]; */
    /*     REP(i,n){ */
    /*         int sth = rand()%(i+2); */
    /*         if(sth == i + 1) */
    /*             sth = -1; */
    /*         a[i] = sth; */
    /*     } */
    /*     int b[n]; */
    /*     iota(b,b+n,0); */
    /*     int resgood = 0; */
    /*     do{ */
    /*         bool kk = 1; */
    /*         int c[n]; */
    /*         memcpy(c,b,sizeof b); */
    /*         REP(_,k){ */
    /*             FOR(i,1,n-1){ */
    /*                 if(c[i-1]>c[i]) */
    /*                     swap(c[i-1],c[i]); */
    /*             } */
    /*         } */
    /*         REP(i,n){ */
    /*             int cr = 0; */
    /*             REP(x,i){ */
    /*                 cr += c[x] > c[i]; */
    /*             } */
    /*             kk &= a[i] == -1 || a[i] == cr; */
    /*         } */
    /*         resgood += kk; */
    /*     }while(next_permutation(b,b+n)); */
    /*     constexpr ll mod = 998244353; */
    /*     ll res = 1; */
    /*     // imo dla i > n - k moe mi sens. */
    /*     REP(i,n){ */
    /*         if(a[i] > i){ */
    /*             res = 0; */
    /*         } */
    /*         else if(a[i] == -1){ */
    /*             res *= i + 1; */
    /*             res %= mod; */
    /*         } */
    /*     } */
    /*     FOR(i,n-k,n-1){ */
    /*         if(a[i] > 0) */
    /*             res = 0; */
    /*     } */
    /*     if(!res){ */
    /*         res = 0; */
    /*     } */
    /*     else{ */
    /*         res = 1; // nc xd. */
    /*         ll cr = 1; */
    /*         REP(i,n){ */
    /*             int othind = i - k; */
    /*             if(othind < 0){ */
    /*                 /1* cr *= i; // cokolwiek. *1/ */
    /*                 cr *= i + 1; // cokolwiek. */
    /*                 cr %= mod; */
    /*             } */
    /*             else{ */
    /*                 if(a[othind] == 0){ */
    /*                     // v[i] <= k */
    /*                     /1* cr *= min(k, i); *1/ */
    /*                     cr *= min(k + 1, i + 1); */
    /*                     cr %= mod; */
    /*                 } */
    /*                 // -1 case jeszcze xd. */
    /*                 else if(a[othind] == -1){ */
    /*                     cr *= i + 1; */
    /*                     cr %= mod; */
    /*                 } */
    /*                 else{ */
    /*                     // v[i] = a[othind] + k */
    /*                 } */
    /*             } */
    /*         } */
    /*         res *= cr; */
    /*         res %= mod; */
    /*     } */
    /*     if(res != resgood){ */
    /*         REP(i,n){ */
    /*             cout << a[i] << ' '; */
    /*         } */
    /*         cout << '\n'; */
    /*         cout << res << ' ' << resgood << endl; */
    /*         assert(res == resgood); */
    /*     } */
    /* } */
}