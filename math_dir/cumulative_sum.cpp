#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using vp = vector<pii>;
#define print_y cout << "Yes" << endl;
#define print_n cout << "No" << endl;
#define rep(i,n) for (int i = 0; i < (n); i++)
const int mod=998244353;

void print_yes_no(bool flag) {
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(void) {
    int n; cin >> n; // 配列サイズ
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i]; // a の入力

    // 累積和
    vector<int> s(n+1, 0); // s[0] = 0 になる
    for (int i = 0; i < n; ++i) s[i+1] = s[i] + a[i];

    // 区間 [left, right) の総和を求める
    int left, right;
    cin >> left >> right;
    cout << s[right] - s[left] << endl;
}