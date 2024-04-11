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
    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        int a[n];
        GET(a);
        // finally 0 inv cnt
        // 4 1 2 3
        // 4 2 3 4
        // 4 3 ..
        // 4 4 5 6
        /* int tot = n; */
        /* vector<array<int,3>> difs; */
        /* /1* REP(i,n){ *1/ */
        /* /1* for(int i = n - 1; i >= 0; --i){ *1/ */
        /* for(int i = 1; i < n; ++i){ */
        /*     if(!tot) break; */
        /*     if(!i) continue; */
        /*     /1* int df = a[i - 1] - a[i]; *1/ */
        /*     int df = a[i - 1] - i; */
        /*     if(df > 0){ */
        /*         difs.push_back({-a[i - 1], df, i + 1}); */
        /*         /1* difs.push_back({a[i], df, i + 1}); *1/ */
        /*     } */
        /*     /1* REP(x,a[i - 1] - a[i]){ *1/ */
        /*     /1* REP(x,a[i - 1] - i){ *1/ */
        /*     /1*     cout << i + 1 << ' '; *1/ */
        /*     /1*     /2* ++tot; *2/ *1/ */
        /*     /1*     if(!--tot) break; *1/ */
        /*     /1* } *1/ */
        /*     if(!tot) break; */
        /* } */
        /* sort(all(difs)); */
        /* FORR(x,difs){ */
        /*     if(!tot) break; */
        /*     REP(j,x[1]){ */
        /*         if(!tot) break; */
        /*         --tot; */
        /*         cout << x[2] << ' '; */
        /*     } */
        /* } */
        vector<pair<int,int>> diffs;
        FOR(i,1,n-1){
            if(a[i] < a[i - 1]){
                diffs.push_back({a[i - 1] - a[i], i});
            }
        }
        sort(all(diffs));
        REP(i,n - diffs.size())
            cout << "1 ";
        FORR(i,diffs){
            cout << i.e2 + 1 << ' ';
        }
        cout << '\n';
    }
}