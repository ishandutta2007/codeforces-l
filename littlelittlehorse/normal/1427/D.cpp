#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<iomanip>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
mt19937 gene(233);
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
    const int maxn = 131072;
    static char buf[maxn],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
    int res(0);
    char c = getchar();
    while(c < '0') c = getchar();
    while(c >= '0') {
        res = res * 10 + (c - '0');
        c = getchar();
    }
    return res;
}

inline LL fastpo(LL x, LL n, LL mod) {
    LL res(1);
    while(n) {
        if(n & 1) {
            res = res * (LL)x % mod;
        }
        x = x * (LL) x % mod;
        n /= 2;
    }
    return res;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

inline string itoa(int x, int width = 0) {
    string res;
    if(x == 0) res.push_back('0');
    while(x) {
        res.push_back('0' + x % 10);
        x /= 10;
    }
    while((int)res.size() < width) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
    fwrite(buf, 1, _bl, stdout);
    _bl = 0;
}
__inline void _putchar(char c) {
    if(_bl == _B) flush();
    buf[_bl++] = c;
}
inline void print(LL x, char c) {
    static char tmp[20];
    int l = 0;
    if(!x) tmp[l++] = '0';
    else {
        while(x) {
            tmp[l++] = x % 10 + '0';
            x /= 10;
        }
    }
    for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
    _putchar(c);
}
struct P {
    D x, y;
};
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m, k, t, a[61][61], c[200011];
char str[200011];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

inline void doit(int k) {
    int w[61];
    int cur = n, tot = 0;
    for (int i = a[k][0]; i; --i) {
        for (int j = cur - a[k][i] + 1; j <= cur; j++)
            w[++tot] = c[j];
        cur -= a[k][i];
    }
    for (int i = 1; i <= n; i++)
        c[i] = w[i];
}
    
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    int tot = 0;
    for (int i = 1, j = n; i <= j; i++, j--)
        if (c[i] == i && c[j] == j)
            continue;
        else {
            int p1 = 0, p2 = 0;
            for (int k = i; k <= j; k++)
                if (c[k] == i)
                    p1 = k;
                else
                    if (c[k] == j)
                        p2 = k;
            if (p1 < p2) {
                a[++tot][0] = 0;
                if (i != 1)
                    a[tot][++a[tot][0]] = i - 1;
                a[tot][++a[tot][0]] = p1 - i + 1;
                if (p2 != p1 + 1)
                    a[tot][++a[tot][0]] = p2 - p1 - 1;
                a[tot][++a[tot][0]] = n - i - p2 + 2;
                if (i != 1)
                    a[tot][++a[tot][0]] = i - 1;
                doit(tot);
            } else 
                if (i != 1) {
                    a[++tot][0] = 0;
                    a[tot][++a[tot][0]] = i - 1;
                    if (n != 2 * (i - 1))
                        a[tot][++a[tot][0]] = n - 2 * (i - 1);
                    a[tot][++a[tot][0]] = i - 1;
                    doit(tot);
                }
            
            for (int k = i; k <= j; k++)
                if (c[k] == i)
                    p1 = k;
                else
                    if (c[k] == j)
                        p2 = k;
            a[++tot][0] = 0;
            if (i != 1)
                a[tot][++a[tot][0]] = i - 1;
            a[tot][++a[tot][0]] = p2 - (i - 1);
            if (p1 != p2 + 1)
                a[tot][++a[tot][0]] = p1 - p2 - 1;
            a[tot][++a[tot][0]] = n - i - p1 + 2;
            if (i != 1)
                a[tot][++a[tot][0]] = i - 1;      
            doit(tot);
        }
    printf("%d\n", tot);
    for (int i = 1; i <= tot; i++) {
        printf("%d", a[i][0]);
        for (int j = 1; j <= a[i][0]; j++)
            printf(" %d", a[i][j]);
        printf("\n");
    }
}