#include <bits/stdc++.h>
    #define pcc pair<char, char>
    #define pii pair<int, int>
    #define vi vector<int>
    #define vl vector<ll>
    #define rep(i, x, y) for(int i = x; i <= y; i ++)
    #define rrep(i, x, y) for(int i = x; i >= y; i --)
    #define rep0(i, n) for(int i = 0; i < (n); i ++)
    #define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
    //#define mp make_pair
    #define pb push_back
    #define ls rt << 1
    #define rs rt << 1 | 1
    #define F first
    #define S second
    #define X first
    #define Y second
    #define eps 1e-9
    #define inf 0x3f3f3f3f
    #define sz(x) (x).size()
    #define ALL(x) (x).begin(), (x).end()
    #define ll long long
    #define db double
    using namespace std;
    namespace IO
    {
    const int sz = 1 << 15;
    char inbuf[sz], outbuf[sz];
    char *pinbuf = inbuf + sz;
    char *poutbuf = outbuf;
    inline char _getchar()
    {
    	if (pinbuf == inbuf + sz)fread(inbuf, 1, sz, stdin), pinbuf = inbuf;
    	return *(pinbuf++);
    }
    inline void _putchar(char x)
    {
    	if (poutbuf == outbuf + sz)fwrite(outbuf, 1, sz, stdout), poutbuf = outbuf;
    	*(poutbuf++) = x;
    }
    inline void flush()
    {
    	if (poutbuf != outbuf)fwrite(outbuf, 1, poutbuf - outbuf, stdout), poutbuf = outbuf;
    }
    }
    #define getchar IO::_getchar
    inline int read()
    {
    	int x = 0, f = 1; char ch = getchar();
    	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    	return x * f;
    }
    inline ll read1()
    {
    	ll x = 0, f = 1; char ch = getchar();
    	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    	return x * f;
    }
    template<typename T> inline T qmin(const T a,const T b) {return a < b ? a : b;}
    template<typename T> inline T qmax(const T a,const T b) {return a > b ? a : b;}
    template<typename T> inline void getmin(T &a,const T b) {if(a > b) a = b;}
    template<typename T> inline void getmax(T &a,const T b) {if(a < b) a = b;}
    const ll linf = 1e17 + 7;
    const int N = 200010;
     
    int a[N];
    int main()
    {
    	int T = read();
    	while(T --)
    	{
    		int n = read();
    		ll times = read1();
    		int mx = -0x3f3f3f3f;
    		rep(i, 1, n)
    			a[i] = read(), mx = max(mx, a[i]);
    		times = times % 2;
    		if(times == 0) times = 2;
    		while(times --)
    		{
    			rep(i, 1, n)
    				a[i] = mx - a[i];
    			mx = -0x3f3f3f3f;
    			rep(i, 1, n)
    				mx = max(mx, a[i]);
    		}
    		rep(i, 1, n) printf("%d ", a[i]);
    		puts("");
    	}
     
    	return 0;
    }