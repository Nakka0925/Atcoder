#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i,n) for (int i = 0; i < (n); i++)

string toBinary(int n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}

int strbin2i (const string &s) {

    int out = 0;

    for (int i = 0, size = s.size() ; i < size ; ++i ) {

        out *= 2;

        out += ((int)s[i] == 49) ? 1 : 0;

    }
    return out;
}

int main(void) {
    int n; cin >> n;
    string N = toBinary(n);

    vector<string> S;

    for (int i = 0; i < n+1; i++) {
        string tmp = toBinary(i);
        string k;
        for (int j = 0; j < tmp.size(); j++) {
            if (N.at(j) == '1' && N.at(j) == '1') k.push_back('1');
            else k.push_back('0');
        }
        string tmp_s_reversed (k.rbegin(), k.rend());
        S.push_back(tmp_s_reversed);
    }

    rep(i,S.size()){
        int tmp = strbin2i(S.at(i));
        cout << tmp << endl;
    }
}

