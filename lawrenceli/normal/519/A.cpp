#include <bits/stdc++.h>

using namespace std;

int main() {
    int a=0, b=0;
    for (int i=0; i<8; i++)
        for (int j=0; j<8; j++) {
            char c; cin >> c;
            if (c == 'Q') a+=9;
            if (c == 'R') a+=5;
            if (c == 'B' || c == 'N') a+=3;
            if (c == 'P') a++;
            
            if (c == 'q') b+=9;
            if (c == 'r') b+=5;
            if (c == 'b' || c == 'n') b+=3;
            if (c == 'p') b++;
       }
   if (a > b) cout << "White";
   else if (a < b) cout << "Black";
   else cout << "Draw";
}