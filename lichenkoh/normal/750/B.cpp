/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class TaskB {
public:
	void solve(std::istream& in, std::ostream& out) {
        ll n; in>>n;
		ll y=20000;
		bool ok=true;
        for (ll i=0;i<n;i++) {
			ll t; string s; in>>t>>s;
			if (y==20000&&s!="South") ok=false;
			if (y==0&&s!="North") ok=false;
			if (s=="North") {
				if (y>=20000) ok=false;
				y+=t;
				if (y>20000) ok=false;
			}
			else if (s=="South") {
				if (y<=0) ok=false;
				y-=t;
				if (y<0) ok=false;
			}
		}
		if (y!=20000) ok=false;
		if (ok) out<<"YES"<<endl;
		else out<<"NO"<<endl;
	}
};


int main() {
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}