#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct UnionFind{
	int size;
	vector<int> parent;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i;
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	void unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return;
		parent[root_i] = root_j;
	}
};

int n, k;
UnionFind uf(100005);
set<int> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	int u, v;
	for(int i = 1; i <= k; i++){
		cin >> u >> v;
		uf.unite(u, v);
	}
	for(int i = 1; i <= n; i++) S.insert(uf.root(i));
	cout << k - (n - S.size()) << endl;
	
	return 0;
}