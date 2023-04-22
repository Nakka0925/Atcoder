#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i,n) for (int i = 0; i < (n); i++)
const int mod=998244353;

int main(void) {
    ll N;
    cin >> N;
    vector<pair<int,int>> p;
    
    for (ll A = 1; A * A <= N; ++A) {
        if (N % A == 0) p.push_back({A,N/A});
    }

    for (auto x : p) cout << x.first << " " << x.second << endl;
}