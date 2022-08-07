#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//using mint = modint998244353;
typedef long long ll;

vector<int> ans2; 
int p = 0;

void printVector(const vector<int>& vec, int N) {
    int n = 0;
    vector<int> ans;
    for (int value : vec) {
        if (value > n){
            n = value;
        }
        else break;
    }
    if (ans.size() >= N) {
        for (int i = 0; i < N; i++) {
            int y = ans[i];
            ans2.push_back(y);
            p++;
        }
    }
    bool present = std::find(begin(ans2), end(ans2), ans) != end(ans2);
    if (!present) {
        for (int i = 0; i < N; i++) {
            cout << ans.at(i) << endl;
        }
        cout << endl;
    }
}

int main(void) {
    int N, M; cin >> N >> M;

    vector<int> vec(M);

    for (int i = 0; i < M; i++) vec.at(i) = i+1;

    do {
        printVector(vec,N);
    } while (next_permutation(vec.begin(), vec.end()));
}