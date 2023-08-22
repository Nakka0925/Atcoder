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

ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main(void) {
    ll n,a,b; cin >> n >> a >> b;

    ll ans = 0, tmpa, tmpb;
    tmpa = n/a,tmpb = n/b;
    ll lcm_n = lcm(a,b);

    ans = (n+1)*n/2;
    ans -= (tmpa+1)*tmpa/2*a;
    ans -= (tmpb+1)*tmpb/2*b;
    ans += ((n/lcm_n)+1)*(n/lcm_n)/2*lcm_n;

    cout << ans << endl;
}
