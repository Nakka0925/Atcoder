#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//using mint = modint998244353;
typedef long long ll;

int main(void) {
    int N,n,sum=0; cin >> N;

    vector<int> P(N+1);

    for (int i = 2; i < N+1; i++) cin >> P.at(i);

    n = P.at(N);

    while (true) {
        sum++;
        if (n == 1) break;
        n = P.at(n); 
    }

    cout << sum << endl;
}