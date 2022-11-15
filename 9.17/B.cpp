#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<string>;
using vvi = vector<vi>;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main(void) {
    vi s(10);

    rep(i,10) cin >> s.at(i);

    int ans1=1000,ans2=0,ans3=1000,ans4=0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (s.at(i).at(j) == '#') {
                ans1 = min(i,ans1);
                ans2 = max(i,ans2);
                ans3 = min(j,ans3);
                ans4 = max(j,ans4);
            }
        }
    }

    cout << ans1+1 << " " << ans2+1 << endl;
    cout << ans3+1 << " " <<ans4+1 << endl;
}