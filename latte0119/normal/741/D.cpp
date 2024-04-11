#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

template<class W>
struct WeightedTree{
	struct Edge{
		int to;
		W cost;
		Edge(int to,W cost):to(to),cost(cost){}
	};

	int V;
	int root;
	int E;
	vector<vector<Edge>>G;

	vector<int>par_,dep_,sz_,head_;
	vector<int>tin_,tout_,vs_;
	vector<W>dist_;
	WeightedTree(int V=0,int root=0):V(V),root(root),G(V),par_(V),sz_(V),dep_(V),head_(V),dist_(V),tin_(V),tout_(V),vs_(V),E(0){}
	void set(int v){
		*this=WeightedTree(v);
	}

	void addEdge(int a,int b,W c=W(1)){
		assert(a<V&&b<V);
		assert(E+1<V);
		G[a].push_back(Edge(b,c));
		G[b].push_back(Edge(a,c));
		E++;
	}

	void dfs(int v,int p,int d,W c){
		par_[v]=p;
		dep_[v]=d;
		sz_[v]=1;
		dist_[v]=c;

		for(auto &e:G[v]){
			if(e.to==p)continue;
			dfs(e.to,v,d+1,c+e.cost);
			sz_[v]+=sz_[e.to];
			if(G[v][0].to==p||sz_[e.to]>sz_[G[v][0].to])swap(G[v][0],e);
		}
	}

	void dfs_hld(int v,int &tt){
		vs_[tt]=v;
		tin_[v]=tt++;
		for(auto &e:G[v]){
			if(e.to==par_[v])continue;
			head_[e.to]=(e.to==G[v][0].to)?head_[v]:e.to;
			dfs_hld(e.to,tt);
		}
		tout_[v]=tt;
	}
	void init(){
		dfs(root,-1,0,W(0));
		int tt=0;
		dfs_hld(root,tt);
	}

	inline int lca(int u,int v)const{
		while(head_[u]!=head_[v]){
			if(dep_[head_[u]]<dep_[head_[v]])swap(u,v);
			u=par_[head_[u]];
		}
		return dep_[u]<dep_[v]?u:v;
	}

	
	inline int ancestor(int v,int k){
		while(v!=-1){
			if(dep_[v]-dep_[head_[v]]<k){
				k-=dep_[v]-dep_[head_[v]]+1;
				v=par_[head_[v]];
				continue;
			}
			return vs_[tin_[v]-k];
		}
		return -1;
	}
	

	inline int par(int v)const{
		return par_[v];
	}

	inline int size(int v)const{
		return sz_[v];
	}
	inline int len(int a,int b=0)const{
		int l=lca(a,b);
		return dep_[a]+dep_[b]-2*dep_[l];
	}
	inline W dist(int a,int b)const{
		int l=lca(a,b);
		return dist_[a]+dist_[b]-2*dist_[l];
	}

	inline W dist(int a)const{
		return dist_[a];
	}

	inline int dep(int v)const{
		return dep_[v];
	}
	inline int tin(int v)const{
		return tin_[v];
	}
	inline int tout(int v)const{
		return tout_[v];
	}

	inline int vs(int k)const{
		return vs_[k];
	}
	inline int heavy(int v)const{
		if(G[v].size()==0||G[v][0].to==par_[v])return -1;
		return G[v][0].to;
	}

	vector<Edge>& operator[](int i){
		return G[i];
	}
};

struct X{
	int a;
	X(int a=0):a(a){}
	X operator+(const X &b){
		return X(a^b.a);
	}

};
WeightedTree<X>wt;
int dp[555555];

const int INF=1001001001;
int mxdep[1<<22];
int mxlen;

namespace DSUOnTree{
	void check(int v){
		int x=wt.dist(v).a;
		int d=wt.dep(v);
		chmax(mxlen,mxdep[x]+d);
		rep(i,22)chmax(mxlen,mxdep[x^(1<<i)]+d);
	}
	void add(int v){
		int x=wt.dist(v).a;
		int d=wt.dep(v);
		chmax(mxdep[x],d);
	}
	void dfs(int v,int p,bool keep){
		int hv=wt.heavy(v);
		for(auto &e:wt[v]){
			if(e.to!=p&&e.to!=hv)dfs(e.to,v,false);
		}

		if(hv!=-1)dfs(hv,v,true);

		mxlen=-INF;
		check(v);add(v);
		for(auto &e:wt[v])if(e.to!=p&&e.to!=hv){
			for(int i=wt.tin(e.to);i<wt.tout(e.to);i++)check(wt.vs(i));
			for(int i=wt.tin(e.to);i<wt.tout(e.to);i++)add(wt.vs(i));
		}

		//calc
		for(auto &e:wt[v])if(e.to!=p)chmax(dp[v],dp[e.to]);
		chmax(dp[v],mxlen-2*wt.dep(v));

		if(!keep){
		//delete
			for(int i=wt.tin(v);i<wt.tout(v);i++){
				int u=wt.vs(i);
				mxdep[wt.dist(u).a]=-INF;
				//delete
			}
		}
	}
	void solve(){
		dfs(0,-1,false);
	}
}


signed main(){
	int N;scanf("%d",&N);
	wt.set(N);
	for(int i=1;i<N;i++){
		int p;
		char c;
		scanf("%d %c",&p,&c);
		p--;
		wt.addEdge(p,i,1<<(c-'a'));
	}
	wt.init();
	fill_n(mxdep,1<<22,-INF);



	DSUOnTree::solve();
	rep(i,N){
		if(i)printf(" ");
		printf("%d",dp[i]);
	}puts("");
	return 0;
}