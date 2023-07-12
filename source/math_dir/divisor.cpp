#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i,n) for (int i = 0; i < (n); i++)
const int mod=998244353;

vector<ll> enum_divisors(ll n) {
    vector<ll> res;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (n / i != i) res.push_back(n/i);
        }        
    }
    sort(res.begin(), res.end());
    return res;
}

int main(void) {
    ll n; cin >> n;
    const auto &res = enum_divisors(n);

    for (auto x : res) cout << x << endl;
}