#include <bits/stdc++.h>
using namespace std;
//using mint = modint998244353;
typedef long long ll;

int main(void) {
    int N; cin >> N;
    vector<int> A(N);
    
    for (int i = 0; i < N; i++) cin >> A.at(i);

    int ans = 0;

    for (int i = 1; i < N; i++) {
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(i+1,vector<int>(i,0)));
        dp[0][0][0] = 1;

        for (int j = 0; j < N; j++) {
            for(int k  = 0;k <= i; k++){
				for(int l = 0; l < i; l++){
                    dp[j+1][k][l] += dp[j][k][l];
					if(k!=i)dp[j+1][k+1][(l+A[j])%i] += dp[j][k][l];
                }
            }
        }
        ans += dp[N][i][0];
    }
    cout << ans << endl;
	
	return 0;
}