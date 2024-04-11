#include <stdio.h>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <climits>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <numeric>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
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
#define N 1000001

int mex(int m){
    FOR(i,0,2){
        if(!(m & (1 << i)))
            return i;
    }
    return 2;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        string s1,s2;
        getstr(s1);
        getstr(s2);
        FORR(i,s1)
            i -= '0';
        FORR(i,s2)
            i -= '0';
        /* int dp[n + 1][1 << 3]; */
        /* int dp[n + 1][1 << 2]; */
        /* memset(dp, 0, sizeof dp); */
        /* dp[0][0] = 1; */
        string s;
        int res = 0;
        FOR(i,0,n){
            if((s1[i] ^ s2[i]) == 1){
                /* res += 1; */
                res += 2;
                s += '3' - '0';
            }
            else{
                assert(s1[i] == s2[i]);
                s += s1[i];
            }
        }
        /* FOR(i,1,n){ */
        /*     res += s[i] == '0' && s[i-1] == '1'; */
        /*     res += s[i] == '1' && s[i-1] == '0'; */
        /* } */
        int nn = s.size();
        /* int dp[nn + 1][1 << 2]; */
        /* memset(dp, 0, sizeof dp); */
        bool is1 = 0;
        FOR(i,0,nn){
            if(s[i] == 1){
                is1 = 1;
            }
            /* else{ */
            else if(s[i] == 0){
                if(is1){
                    res += 2;
                    is1 = 0;
                }
                else{
                    if(i + 1 < nn && s[i + 1] == 1){
                        res += 2;
                        i += 1;
                    }
                    else{
                        res += 1;
                    }
                }
            }
            else{
                is1 = 0;
                /* res += 2; */
            }
        }
        cout << res << '\n';
    }
}