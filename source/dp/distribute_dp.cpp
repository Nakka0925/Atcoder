#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i,n) for (int i = 0; i < (n); i++)
const int mod=998244353;

int main(void) {
    int n; cin >> n;
    vvi dp(n,vi(n, 0));

// スタート地点であるマス (0, 0) は 1 通り
dp[0][0] = 1;

// 順に各マスの値を決定していく
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // 下へ行く場合
        if (i+1 < n) dp[i+1][j] += dp[i][j];
        
        // 右へ行く場合
        if (j+1 < n) dp[i][j+1] += dp[i][j];
    }
}