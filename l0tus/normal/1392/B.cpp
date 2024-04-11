#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int main()
{
	#ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
	#endif
	
    ios_base::sync_with_stdio(0),cin.tie(0);

    int T;
    cin >> T;
    while(T--){
    	int N;
    	ll k;
    	cin >> N >> k;
    	vector<int> A(N);
    	int L=INF,R=-INF;
    	for(int i=0; i<N; i++){
    		cin >> A[i];
    		L = min(L,A[i]);
    		R = max(R,A[i]);
    	}
    	if(k%2){
    		for(int i=0; i<N; i++){
    			cout << R-A[i] << ' ';
    		}
    	}
    	else{
    		for(int i=0; i<N; i++){
    			cout << -L+A[i] << ' ';
    		}    		
    	}
    	cout << '\n';
    }
}