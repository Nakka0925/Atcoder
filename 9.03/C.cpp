#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main(void) {
    int n,m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    ll s = 0,t = 0;
    rep(i,m) s += a.at(i)*(i+1);
    rep(i,m) t += a.at(i);
    ll ans = s;
    rep(i,n-m) {
        ll ns = s - t + a.at(i+m)*m;
        ll nt = t - a.at(i) + a.at(i+m);
        s = ns; t = nt;
        ans = max(ans, s);
    }

    cout << ans << endl;
}

