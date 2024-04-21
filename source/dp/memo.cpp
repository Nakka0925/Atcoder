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

map<ll,ll> memo;

ll f(ll n) {
 // ベースケース
 if(n == 0) return 1;

 // 再帰ステップ
   return f(n/2) + f(n/3);
   if(memo[n] != 0) return memo[n]; // メモがあったら返す
   ll ans = f(n/2) + f(n/3);
   memo[n] = ans;
   return ans;
}

int main(void) {
 ll n; cin >> n;
 cout << f(n) << endl;
}