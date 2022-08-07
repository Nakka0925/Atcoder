#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, x, y, z, t; cin >> n >> x >> y >> z;
    vector<int> a(n+1), b(n+1), c, d;
    vector<bool> v(n+1, false);
    for (int i = 1; i <= n; i++) cin >> a.at(i);
    for (int i = 1; i <= n; i++) cin >> b.at(i);
    for (int i = 1; i <= n; i++) c.emplace_back((10000 * (100 - a.at(i))) + i);

    sort(c.begin(), c.end());

    for (int i = 0; i < x; i++) {
        t = c.at(i) % 1000;
        v.at(t) = true;
        d.push_back(t);
    }

    c.clear();
    for (int i = 1; i <= n; i++) c.emplace_back((10000 * (100 - b.at(i))) + i);
    
    sort(c.begin(), c.end());

    for (int i = 0; i < n; i++) {
        t = c.at(i) % 1000;
        cout << t << endl;
        if (v.at(t) == true) continue;
        v.at(t) = true;
        d.push_back(t);
        //cout << "a" << endl;
        y--;
        cout << y << endl;
        if (y == 0) break;
    }

    c.clear();
    for (int i = 1; i <= n; i++) c.emplace_back(((10000 * (200 - (a.at(i) + b.at(i))))) + i);
    sort(c.begin(), c.end());

    for (int i = 0; i < n; i++) {
        t = c.at(i) % 1000;
        if (v.at(t) == true) continue;
        v.at(t) = true;
        d.push_back(t);
        z--;
        if (z == 0) break;
    }

    //sort(d.begin(), d.end());

    int e = x;
    //e += z;

    for (int i = 0; i < d.size(); i++) cout << d.at(i) << endl;
}