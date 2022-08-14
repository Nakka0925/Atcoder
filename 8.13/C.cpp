#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(void) {
    int N; cin >> N;
    vi A(N+1), B(N+1), C(N+1);
    
    for (int i = 1; i <= N; i++) {
        cin >> A.at(i);
    }
    for (int i = 1; i <= N; i++) {
        cin >> B.at(i);
    }
    for (int i = 1; i <= N; i++) {
        cin >> C.at(i);
    }
    ll ans = 0;
    vi count(N+1,0);
    for (int i = 1; i <= N; i++) count.at(B.at(C.at(i)))++;
    for (int i = 1; i <= N; i++) {
        ans += count.at(A.at(i));
    }
    cout << ans << endl;
}