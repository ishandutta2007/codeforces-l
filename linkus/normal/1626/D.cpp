/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC optimize("Ofast,unroll-loops") */
/* #pragma GCC target("avx2,popcnt") */
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
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
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
#define debug(x...) ;
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) { return o << '(' << p.first << ", " << p.second << ')'; }
template<class T, enable_if_t<!is_same<T, string>::value, bool> = true> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) { o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}'; }
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 1000001

vi pw2vec;

int nxtpw2(int x){
    return *lower_bound(all(pw2vec), x);
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    FOR(i,0,29)
        pw2vec.push_back(1 << i);
    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        int a[n];
        GET(a);
        sort(a,a+n);
        vector<pi> vec;
        FORR(i,a){
            if(vec.empty() || vec.back().e1 != i)
                vec.push_back({i, 1});
            else
                ++vec.back().e2;
        }
        int res = INF;
        n = vec.size();
        int pre[n];
        pre[0] = vec[0].e2;
        FOR(i,1,n)
            pre[i] = pre[i - 1] + vec[i].e2;
        // todo empty / entire lightweight.
        FOR(i,0,n){
            int pen1 = nxtpw2(pre[i]) - pre[i];
            for(int x = 0; x < 20; ++x){
                int low = i, high = n - 1, mid, ans;
                while(low <= high){
                    mid = (low + high) / 2;
                    if(pre[mid] - pre[i] <= (1 << x)){
                        ans = mid;
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }
                /* whatis(pen1) */
                // mid not ans xd.
                /* whatis((1 << x) - (pre[ans] - pre[i])) */
                /* whatis(nxtpw2(pre[n - 1] - pre[ans]) - (pre[n - 1] - pre[ans])) */
                res = min(res, pen1 + (1 << x) - (pre[ans] - pre[i]) + nxtpw2(pre[n - 1] - pre[ans]) - (pre[n - 1] - pre[ans]));
            }
            for(int x = 0; x < 20; ++x){
                int low = i, high = n - 1, mid, ans;
                while(low <= high){
                    mid = (low + high) / 2;
                    if(pre[n - 1] - pre[mid] <= (1 << x)){
                        ans = mid;
                        high = mid - 1;
                    }
                    else{
                        low = mid + 1;
                    }
                }
                /* whatis(pen1) */
                // mid not ans xd.
                /* whatis((1 << x) - (pre[ans] - pre[i])) */
                /* whatis(nxtpw2(pre[n - 1] - pre[ans]) - (pre[n - 1] - pre[ans])) */
                res = min(res, pen1 + (1 << x) - (pre[n - 1] - pre[ans]) + nxtpw2(pre[ans] - pre[i]) - (pre[ans] - pre[i]));
            }
        }
        /* ll sum = accumulate(pre,pre+n,0); */
        ll sum = pre[n - 1];
        /* whatis(sum) */
        FORR(i,pre){
            /* whatis(i) */
            /* whatis(sum - i) */
            res = min<ll>(res, 1 + nxtpw2(i) - i + nxtpw2(sum - i) - (sum - i));
        }
        cout << res << '\n';
    }
}