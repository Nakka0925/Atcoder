#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(void) {
    string S; cin >> S;

    vector<char> D(9);

    if (S[0] == '0') {
        cout << "No" << endl;
        return 0;
    }
    D[0] = S[6];
    D[1] = S[3];
    D[2] = S[7];
    D[3] = S[1];
    D[4] = S[4];
    D[5] = S[8];
    D[6] = S[2];
    D[7] = S[5];
    D[8] = S[9];

    for (int i = 0; i < N; i++) {
        for (int j = i; j < 5 ; j++) {
            if (D[i] == '1') {

            }
        }
    }

    