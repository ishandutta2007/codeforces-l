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

#ifdef ONLINE_JUDGE
#define whatis(x) ;
#endif
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
#define N 100001

vi adj[N];
set<int> cr;
bool v1[N];
bool kk;

/* void d1(int v){ */
/*     FORR(i,adj[v]){ */
/*     } */
/* } */

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    FOR(i,0,m){
        int f,s;
        sc(f,s);
        --f,--s;
        adj[f].pb(s);
        adj[s].pb(f);
    }
    FOR(i,0,n)
        sort(all(adj[i]));
    FOR(i,0,n){
        if(v1[i]) continue;
        cr.clear();
        kk = 1;
        FOR(x,0,n){
            if(!binary_search(all(adj[i]),x)){
                cr.insert(x);
                /* assert(!v1[x]); //correct all od razu */
                if(v1[x]) kk = 0; //to make it faster hopefully, though shuffle maybee?
                v1[x] = 1;
            }
        }
        if(!kk) continue;
        FORR(x,cr){
            if(adj[x] != adj[i]){
                kk = 0;
                break;
            }
            /* d1(x); */
        }
        if(kk){ //mamy grupe 1 yay
            bool v2[n];
            FOR(i,0,n)
                v2[i] = cr.count(i);
            bool kk2 = 1;
            set<int> cr2;
            FOR(x,0,n){
                /* if(cr.count(x)) continue; //mozna bool table */
                if(v2[x]) continue;
                cr2.clear();
                kk2 = 1;
                FOR(j,0,n){
                    if(!binary_search(all(adj[x]),j)){
                        cr2.insert(j);
                        /* assert(!v1[x]); //correct all od razu */
                        if(v2[j]) kk2 = 0; //to make it faster hopefully, though shuffle maybee?
                        v2[j] = 1;
                    }
                }
                if(!kk2) continue;
                FORR(j,cr2){
                    if(adj[j] != adj[x]){
                        kk2 = 0;
                        break;
                    }
                    /* d1(x); */
                }
                if(kk2){
                    int res[n];
                    FORR(i,res)
                        i = 3;
                    FORR(i,cr){
                        res[i] = 1;
                    }
                    FORR(i,cr2){
                        res[i] = 2;
                    }
                    vi cr3;;
                    FOR(i,0,n){
                        if(res[i] == 3){
                            cr3.push_back(i);
                        }
                    }
                    if(cr3.empty()) continue;
                    FORR(i,cr3){
                        if(adj[i] != adj[cr3[0]]) kk2 = 0;
                    }
                    if(!kk2) continue;
                    FORR(i,res)
                        cout << i << ' ';
                    return 0;
                }
            }
        }
    }
    REE(-1)
}