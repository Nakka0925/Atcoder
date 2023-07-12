#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i,n) for (int i = 0; i < (n); i++)
const int mod=998244353;

double getDistance(double x, double y, double x2, double y2) {
    double distance = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));

    return distance;
}

double getRadian(double x, double y, double x2, double y2) {
    double radian = atan2(y2 - y,x2 - x);
    //radianをdegreeに変換
    // double degree = radian * (180 / M_PI);
    // return degree;
    return radian;
}

int main(void) {
}