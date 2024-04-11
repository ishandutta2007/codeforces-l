#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) (a.begin()),(a.end())
#define ZERO(a) meset(a,0,sizeof(a))
#define FOR(x,val,to) for(int x=(val);x<int((to));x++)
#define FORE(x,val,to) for(auto x=(val);x<=(to);x++)
#define FORR(x,arr) for(auto &x: arr)
#define PRINT(arr) copy((arr).begin(), (arr).end(), ostream_iterator<int>(cout, " ")
#define REE(s_) {cout<<s_<<'\n';return 0;} //print s_ and terminate program
#define GET(vec,type,amount) copy_n(istream_iterator<(type)>(cin),(n),back_inserter((vec)))
#define MEMSET_INF 127 //2139062143 (USE FOR MEMSET)
#define INF 2139062143 //for comparison
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
using namespace std;

bool sth(string tmp){
    string old="";
    FORR(i,tmp){
        if(old.find(i)!=old.npos){
            return false;
        }
        old+=i;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string tmp;
    while(n++){
        tmp=to_string(n);
        if(sth(tmp))
            break;
    }
    cout << n;
}