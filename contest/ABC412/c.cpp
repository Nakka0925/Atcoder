#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using vp = vector<pii>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vvvi = vector<vector<vector<int>>>;
#define print_y cout << "Yes" << endl
#define print_n cout << "No" << endl
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#define INPUT(type, ...) \
    type __VA_ARGS__; \
    do { \
        auto read_variables = [&](auto&... args) { (cin >> ... >> args); }; \
        read_variables(__VA_ARGS__); \
    } while (0)
#define INPUT_ARRAY(type, array, size) \
    vector<type> array((size)); \
    for (int i = 0; i < (size); i++) { \
        cin >> (array)[i]; \
    }
#define INPUT_ARRAY2(type, array, rows, cols) \
    vector<vector<type>> array((rows), vector<type>((cols))); \
    for (int i = 0; i < (rows); i++) { \
        for (int j = 0; j < (cols); j++) { \
            cin >> (array)[i][j]; \
        } \
    }
set<char> abc = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector<pair<int,int>> d = {{1,0},{0,-1},{-1,0},{0,1}};
const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
const int mod=998244353;

// Pair Sort
// 一つ目を昇順、二つ目を降順にソートする関数
void sortPairsWithDescendingSecond(vector<pair<int, int>>& v) {
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first; // 一つ目の要素が異なる場合は、一つ目の要素で昇順ソート
        }
        return a.second > b.second; // 一つ目の要素が同じ場合は、二つ目の要素で降順ソート
    });
}
// NUMERIC FUNCTION
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
// PRIME
bool isprime(ll N) {
    if (N < 2) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}
map<ll, ll> numeric_component(ll N) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= N; i++) {
        if (N % i != 0) continue;
        while (N % i == 0) {res[i]++; N /= i;}
    }
    if (N != 1) res[N]++;
    return res;
}

int solve(const vl& a, int n) {
    vector<pair<ll, int>> dominoes;
    for (int i = 1; i < n - 1; ++i) {
        dominoes.emplace_back(a[i], i);
    }

    sort(all(dominoes));

    vector<bool> used(n, false);
    queue<pair<ll, int>> q;

    if (a[0] == a[n - 1]) return 2;

    q.push({a[0], 1});
    used[0] = true;

    int ptr = 0;

    while (!q.empty()) {
        auto [val, len] = q.front(); q.pop();

        while (ptr < dominoes.size() && dominoes[ptr].first <= 2 * val) {
            int idx = dominoes[ptr].second;
            if (!used[idx]) {
                used[idx] = true;
                q.push({a[idx], len + 1});
            }
            ++ptr;
        }

        if (!used[n - 1] && a[n - 1] <= 2 * val) {
            return len + 1;
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vl a(n);
        rep(i,0,n) cin >> a[i];
        cout << solve(a, n) << endl;
    }

    return 0;
}
