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
#define N 1000001

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        string s,t;
        getstr(s);
        getstr(t);
        string cps = s;
        sort(all(cps));
        if(cps >= t){
            cout << "-1\n";
            continue;
        }
        ordered_set<pair<int, char>> st;
        FORR(i,s)
            i -= 'a';
        FORR(i,t)
            i -= 'a';
        /* vector<int> pos[26]; */
        deque<int> pos[26];
        FOR(i,0,n){
            pos[s[i]].push_back(i);
            st.insert({i, s[i]});
        }
        ll res = LONG_LONG_MAX;
        ll cr = 0;
        FOR(i,0,n){
            char crchr = st.begin()->e2;
            /* whatis(i) */
            /* whatis(crchr + 'a') */
            /* whatis(cr) */
            /* whatis(t[i] + 'a') */
            if(crchr < t[i]){
                /* res = cr; */ // to byo fest le?
                // -> chyba git, bo byby break wczeniej inaczej.
                res = min(res, cr);
                break;
            }
            /* else if(cr == t[i]){ */
            /* } */
            else{
                // 1. <
                pair<int, char> bs{INF,INF};
                // btw, opt, nie musz tutaj patrze na order_of_key for
                // selection, lecz na e1, a dopiero potem order_of_key zgarn.
                FOR(x,0,t[i]){
                    /* if(pos[x].size()){ */
                    /*     int wh = st.order_of_key({pos[x][0], x}); */
                    /*     assert(wh != st.size()); */
                    /*     bs = min(bs, pair<int,char>{wh, x}); */
                    /* } */
                    if(pos[x].size()){
                        bs = min(bs, pair<int,char>{pos[x][0], x});
                    }
                }
                if(bs.e1 != INF){
                    int wh = st.order_of_key(bs);
                    /* assert(wh != st.size()); */
                    bs.e1 = wh;
                    res = min(res, cr + bs.e1); // 0 -> begin -> no need; 1 -> 1 swap indeed.
                }
                /* if(bs.e1 != INF){ */
                /*     res = min(res, cr + bs.e1); // 0 -> begin -> no need; 1 -> 1 swap indeed. */
                /* } */
                // 2. =
                if(pos[t[i]].size()){
                    int wh = st.order_of_key({pos[t[i]][0], t[i]});
                    /* assert(wh != st.size()); */
                    /* if(wh >= bs.e1){ // opt */
                    /*     break; */
                    /* } */
                    cr += wh;
                    st.erase({pos[t[i]][0], t[i]});
                    pos[t[i]].pop_front();
                }
                else{ // za forgot the else xdd.
                    break;
                }

            }
            // better opt
            if(cr >= res)
                break;
        }
        assert(res != LONG_LONG_MAX);
        cout << res << '\n';
    }
}