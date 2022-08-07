#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//using mint = modint998244353;
typedef long long ll;



int main(void) {
    
    vector<int> vec(5);

    for (int i = 0; i < 5; i++) {
        cin >> vec.at(i);
    }
    
    sort(vec.begin(), vec.end());

    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    if (vec.size() == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}


    