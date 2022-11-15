#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(void) {
    string s, t; cin >> s >> t;
    if (s == t.substr(0, s.size())) cout << "Yes" << endl;
    else cout << "No" << endl;
}