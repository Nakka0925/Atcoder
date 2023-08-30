#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using vp = vector<pii>;
using vs = vector<string>;
#define print_y cout << "Yes" << endl
#define print_n cout << "No" << endl
#define rep(i,n) for (int i = 0; i < (n); i++)
const int mod=998244353;

void print_yes_no(bool flag) {
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(void) {
    int n; cin >> n;
    int right = 0;     
for (int left = 0; left < n; left++) {
    while (right < n && "条件") {//1 個進めたときに条件を満たす)) {
        /* 実際に right を 1 進める */
        // ex: sum += a[right];
        right++;
    }

    /* break した状態で right は条件を満たす最大なので、何かする */
    // ex: res += (right - left);

    /* left をインクリメントする準備 */
    // ex: if (right == left) ++right;
    // ex: else sum -= a[left];
}