#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(void) {
   int R,C; cin >> R >> C;

   if (C >= 8) C = 16 - C;
   if (R >= 8) R = 16 - R; 

   if (R % 2 == 0) {
    if ((C >= R && C <= 16 - R)) {
        cout << "white" << endl;
        return 0;
    }
    if (C % 2 == 0) {
        cout << "white" << endl;
        return 0;
    }
    else cout << "black" << endl;
    return 0;
   }
   if (R % 2 == 1) {
    if (C >= R && C <= 16 - R) {
        cout << "black" << endl;
        return 0;
    }
    if (C % 2 == 1) {
        cout << "black" << endl;
        return 0;
    }
    else cout << "white" << endl;
    return 0;
   }
}