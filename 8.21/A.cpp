#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<char>;
using vvi = vector<vi>;

int main(void) {
    int H,W; cin >> H >> W;
    vvi M(H+1,vi(W+1));

    for (int i = 1; i < H+1; i++) {
        for (int j = 1; j < W+1; j++) {
            cin >> M.at(i).at(j);
        }
    }

    int a=1,b=1;
    int e = 0;
    pair<int,int> ans;
    
    while (0 < a && a <= H && 0 < b && b <= W) {
        e++;
        ans.first = a;ans.second = b;    
        
        if (M.at(a).at(b) == 'R') b += 1;
        else if (M.at(a).at(b) == 'L') b -= 1;
        else if (M.at(a).at(b) == 'U') a -= 1;
        else if (M.at(a).at(b) == 'D') a += 1;
        
        if (e == 250000) {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << ans.first << " " << ans.second << endl;
}