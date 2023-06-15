#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i,n) for (int i = 0; i < (n); i++)
const int mod=998244353;
    
int main(void) {
    vector<int> vec = {1, 1, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
    size_t len = vec.size();
    int key; cin >> key;

    // 二分探索
    auto iter_lower = lower_bound(vec.begin(), vec.end(), key);
    if (*iter_lower == 0) cout << "Key以上の値はなし" << endl;
    else cout << "key以上の値" << *iter_lower << endl;

    // インデックスを取得
    long idx_lower = distance(vec.begin(), iter_lower);  // vec[idx_lower] = vec[7] = 6

    // lower_bound で要素数を数える
    cout << "6 未満の要素数は " << idx_lower << "\n";  // 6 までの要素数 (idx_lower + 1) - 1
    cout << "6 以上の要素数は " << len - idx_lower << "\n";  // 6 までの要素数 (idx_lower + 1) - 1

    return 0;
}