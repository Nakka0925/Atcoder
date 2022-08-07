#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N, X, Y; cin >> N >> X >> Y;
    vector<long long> b(N+1), r(N+1);
    b.at(1) = 1, r.at(1) = 0;
    for(int i = 2; i <= N; i++) {
        b.at(i) = r.at(i-1) + b.at(i-1) * Y;
        r.at(i) = r.at(i-1) + b.at(i) * X;
    }

    cout << r.at(N) << endl;
}