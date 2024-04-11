#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define pii pair <int, int>
#define XX first
#define YY second

// constants:
const int mn = 200005;
const int mod = 1000000007;
const long long inf = 4444444444444444444;
const int sminf = 1111111111;
const bool is_multitest = 1;
const bool is_interactive = 0;

// i/o methods:
const bool input_from_file = 0;
const bool output_to_file = 0;
#define filename ""
#define in_extension "inp"
#define out_extension "out"

// data preprocessing: (e.g.: divisor generating, prime sieve)
void preprocess()
{
    
}

// global variables:
int n;
string A, B;
set <pair <int, pair <char, char> > > ss;
int root[mn];
int getroot(int u) {
    if (u==root[u]) return u;
    return root[u] = getroot(root[u]);
}
int mergeroot(int u, int v) {
    int x = getroot(u), y = getroot(v);
    if (x==y) return 0;
    root[x] = y;
    return 1;
}
// main solution goes here:
void execute(int test_number)
{
    for (int i=1; i<30; i++) root[i] = i;
    ss.clear();
    cin>>n>>A>>B;
    for (int i=0; i<n; i++) if (A[i] > B[i]) {
        cout<<"-1\n";
        return;
    }

    for (int i=0; i<n; i++) {
        ss.insert({B[i] - A[i], {A[i], B[i]}});
    }

    int ans = 0;
    for (pair <int, pair <char, char> > p: ss) {
        ans += mergeroot(p.YY.XX - 'a' + 1, p.YY.YY - 'a' + 1);
    }
    cout<<ans<<"\n";

}
// REMEMBER TO CHOOSE TEST METHODS
// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Solution by low_



















signed main()
{
#ifdef lowie
    if (!is_interactive)
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
#else
    if (input_from_file) freopen(filename"."in_extension, "r", stdin);
    if (output_to_file) freopen(filename"."out_extension, "w", stdout);
#endif
    if (!is_interactive)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    preprocess();
    int ntest;
    if (is_multitest) cin >> ntest;
    else ntest = 1;

    for (int testno = 1; testno <= ntest; testno++)
    // use for instead of while to serve facebook hacker cup test format
    {
        execute(testno); // only start coding in this function, not in main
    }
}
// Template by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/