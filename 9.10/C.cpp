#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main(void) {
    int n; cin >> n;
    vi p(n);
    rep(i,n) cin >> p.at(i);
    vi cnt(n);
    rep(i,n) {
        int j = (p.at(i)-i-1+n)%n;
        rep(k,3) cnt.at((j+k)%n)++;
    } 
    int ans = 0;
    rep(i,n) ans = max(ans,cnt.at(i));
    cout << ans << endl;
}
