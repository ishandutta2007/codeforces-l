#include <bits/stdc++.h> //Stack size ~2'000'000(x4)
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x < end(arr); ++x)
#define PRINT(arr) {copy(begin((arr)), end((arr)), ostream_iterator<int>(cout, " "));cout<<'\n';}
#define REE(s_) {cout<<s_<<'\n';exit(0);} //print s_ and terminate program
#define GETCIN(arr) for(auto &i: (arr)) cin>>i
#define GET(arr) for(auto &i: (arr)) sc(i)
#define GETSTR(arr) for(auto &i: (arr)) getstr(i)
#define INF 2139062143 //127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
#define umap unordered_map
#define uset unordered_set
using namespace std;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }//prnt vec
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }//prnt pair
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
template<typename T> inline T fstoi(const string &str){auto it=str.begin();bool neg=0;T num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}template<typename ...Args> inline void getstr(string &str, Args &...arg){str.clear();char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}getstr(arg...);}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }

int n;

inline void counting_sort(int *beg, int *end){
    bool arr[n+1];
    memset(arr,0,sizeof arr);
    int *actbeg = beg;
    while(beg < end){
        arr[*beg++] = 1;
    }
    FORE(i,1,n){
        if(arr[i])
            *actbeg++ = i;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m;
    sc(n,m);
    int arr[n];
    GET(arr);
    int l,r,i;
    while(m--){
        sc(l,r,i);
        --i;
        int newarr[n];
        /* int newarr[i-l+2]; */
        /* partial_sort_copy(arr+l-1,arr+r,newarr,newarr+i-l+2); */
        memcpy(&newarr, &arr, sizeof arr);
        counting_sort(newarr+l-1,newarr+r);
        /* sort(newarr.begin()+l-1,newarr.begin()+r); */
        /* FORR(i,newarr) */
        /*     cout << i << ' '; */
        /* cout << '\n'; */
        cout << (newarr[i] == arr[i]?"Yes\n":"No\n");
        /* cout << (newarr[i-l+1] == arr[i]?"Yes\n":"No\n"); */
    }
}