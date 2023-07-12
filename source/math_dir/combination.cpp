#include <iostream>
#include <vector>
using namespace std;
#include <numeric>


// Combination  nCr ----------
template <class T>
void dfs_combination(vector<T> &arr, int idx, int r, vector<T> &pattern, vector<vector<T>> &result) {
    if (r == 0) {
        result.push_back(pattern);
        return;
    }
    if ((idx + r) > arr.size()) {
        return;
    }

    // select
    pattern.push_back(arr[idx]);
    dfs_combination(arr, idx + 1, r - 1, pattern, result);
    pattern.pop_back();
    // not select
    dfs_combination(arr, idx + 1, r, pattern, result);
}

template <class T>
vector<vector<T>> combination(vector<T> &arr, int r) {
    if (arr.size() < r) {
        printf("combination ERROR: r is larger than arr.size()\n");
        exit(1);
    }

    vector<T> pattern;
    vector<vector<T>> result;
    dfs_combination(arr, 0, r, pattern, result);
    return result;
}
// ------------------------------

// Debug用  配列の表示 ----------
template <class T>
void print_vector(vector<T> arr) {
    printf("[ ");
    for (int i = 0; i < arr.size(); i++) {
        //printf("%d", arr[i]);
        cout << arr[i];
        if (i != (arr.size() - 1)) printf(", ");
    }
    printf(" ]\n");
}

template <class T>
void print_vector2(vector<T> arr) {
    for (int i = 0; i < arr.size(); i++) {
        print_vector(arr[i]);
    }
}
// ------------------------------


int main() {
    vector<int> arr(5);
    iota(arr.begin(), arr.end(), 0);
    vector<vector<int>> res = combination(arr, 3);
    print_vector2(res);

    vector<string> arr2 = {"aa", "aa", "cc", "dd", "ee"};
    vector<vector<string>> res2 = combination(arr2, 3);
    print_vector2(res2);
}