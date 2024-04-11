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
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

string S[10];

bool checkWin(int x, int y, int dx, int dy)
{
    // cout<<x<<" "<<y<<" "<<dx<<" "<<dy<<"\n";
    for (int i=0; i<5; i++) 
    {
        if (x<0 || x>9 || y<0 || y>9) return 0;
        if (S[x][y]!='X') return 0;
        x+=dx;
        y+=dy; 
    }
    return 1;
}

int dX[4]={1, 0, 1, 1};
int dY[4]={0, 1, 1, -1};

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=0; i<10; i++) cin>>S[i];

    for (int i=0; i<10; i++) for (int j=0; j<10; j++) if (S[i][j]=='.')
    {
        S[i][j]='X';
        for (int d=0; d<4; d++) for (int c=0; c<5; c++)
        {
            if (checkWin(i-dX[d]*c, j-dY[d]*c, dX[d], dY[d])==1)
            {
                cout<<"YES";
                return 0;
            }
        }
        S[i][j]='.';
    }

    cout<<"NO";
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/