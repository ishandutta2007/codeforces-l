#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vi V(N + 1, 0);
	for (int i = 2; i <= N; i++) cin >> V[i];
	stack<int> s;
	for (int w = N; w > 1; w = V[w]) s.push(w);
	s.push(1);
	while (!s.empty()) {
		cout << s.top();
		s.pop();
		cout << " \n"[s.empty()];
	}

	return 0;
}