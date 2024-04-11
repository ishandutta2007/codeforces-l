/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>
using namespace std;
typedef int ll;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

const ll INF=1e9;
const ll mc=5;
ll n,q;
string s;
struct SS {
    ll a[mc][mc];
};
typedef struct SS S;
S digits[10];
S identity;
S combine(S &a, S &b) {
    S c;
    for (ll x=0;x<mc;x++) {
        for (ll y=0;y<mc;y++) {
            ll ans = INF;
            for (ll z = 0; z < mc; z++) {
                ll aa=a.a[x][z];
                ll bb=b.a[z][y];
                if (aa>=INF||bb>=INF) continue;
                chkmin(ans, aa+bb);
            }
            c.a[x][y]=ans;
        }
    }
    return c;
}
const ll MAXN=2e5+4;
S t[2*MAXN];
void build(ll n) {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}
/*void modify(int p, const S& value) {
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}*/

S query(int l, int r, ll n) {
    r++;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) resl = combine(resl, t[l++]);
        if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
}
class TaskE {
public:
	void solve(std::istream& in, std::ostream& out) {
        cin.tie(0); ios::sync_with_stdio(0);
        in>>n>>q;
        in>>s;
        for (ll x=0;x<mc;x++) for (ll y=0;y<mc;y++) identity.a[x][y]=(x==y)?0:INF;
        for (ll d=0;d<10;d++) {
            S t;
            for (ll x=0;x<mc;x++) for (ll y=0;y<mc;y++) t.a[x][y]=INF;
            {
                ll x=0;
                if (d==2) {
                    t.a[x][x+1]=0;
                    t.a[x][x]=1;
                }
                else {
                    t.a[x][x]=0;
                }
            }
            {
                ll x=1;
                if (d==0) {
                    t.a[x][x+1]=0;
                    t.a[x][x]=1;
                }
                else {
                    t.a[x][x]=0;
                }
            }
            {
                ll x=2;
                if (d==1) {
                    t.a[x][x+1]=0;
                    t.a[x][x]=1;
                }
                else {
                    t.a[x][x]=0;
                }
            }
            {
                ll x=3;
                if (d==7) {
                    t.a[x][x+1]=0;
                    t.a[x][x]=1;
                }
                else if (d==6) {
                    t.a[x][x]=1;
                }
                else {
                    t.a[x][x]=0;
                }
            }
            {
                ll x=4;
                if (d==6) {
                    t.a[x][x]=1;
                }
                else {
                    t.a[x][x]=0;
                }
            }
            digits[d]=t;
        }
        for (ll i=0;i<n;i++) {
            ll d=s[i]-'0';
            t[n+i]=digits[d];
        }
        build(n);
        for (ll i=0;i<q;i++) {
            ll l,r; in>>l>>r;
            --l; --r;
            S ans=query(l,r,n);
            ll final=ans.a[0][4];
            if (final>=INF) final=-1;
            out<<final<<endl;
        }
	}
};


int main() {
	TaskE solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}