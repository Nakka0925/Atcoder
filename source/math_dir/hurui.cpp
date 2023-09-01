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
    const int m = 1e6;

    vi prime; //素数配列
    vector<bool> isp(m+1, true); isp[0] = isp[1] = false; //素数判定の配列  ex) 1 = false, 2 = true

    //エラトステネスの篩
    for (int i = 2; i <= m; i++) {
        if (!isp[i]) continue;
        prime.push_back(i);

        for (ll j = (ll)i*i; j <= m; j += i) isp[j] = false;
    }

    //累積和
    vi s(m+1);

    for (auto x : prime) s[x] = 1;
    rep(i,m) s[i+1] += s[i];

}