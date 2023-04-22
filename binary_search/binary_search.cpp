
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec = {3, 1, 4, 6, 5};

    // ソート：二分探索はソートされた配列に対して適用する
    sort(vec.begin(), vec.end());  // 1, 3, 4, 5, 6

    // 0 - 10 の整数が vec に含まれているか検索
    for (int key = 0; key <= 10; ++key) {
        if (binary_search(vec.begin(), vec.end(), key)) {
            cout << key << ": " << "found" << std::endl;
        } else {
            cout << key << ": " << "not found" << std::endl;
        }
    }

    return 0;
}