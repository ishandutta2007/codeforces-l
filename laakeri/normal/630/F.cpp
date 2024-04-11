#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll bin[800][800];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	bin[0][0]=1;
	for (int i=1;i<800;i++){
		bin[i][0]=1;
		for (int ii=1;ii<800;ii++){
			bin[i][ii]=bin[i-1][ii-1]+bin[i-1][ii];
		}
	}
	ll n;
	cin>>n;
	cout<<bin[n][5]+bin[n][6]+bin[n][7]<<endl;
}