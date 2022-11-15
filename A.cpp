#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main(void) {
    ll n;
    cin >> n;
    vi a;
    for (int i = 0; i < 60; i++) {
        if (n & (1ll<<i)) a.push_back(i);
    }

    
}
