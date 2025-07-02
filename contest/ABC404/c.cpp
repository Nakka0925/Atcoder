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

struct UnionFind {
    vector<int> par, rank, siz;

    // 構造体の初期化
    UnionFind(int n) : par(n,-1), rank(n,0), siz(n,1) { }

    // 根を求める
    int root(int x) {
        if (par[x]==-1) return x; // x が根の場合は x を返す
        else return par[x] = root(par[x]); // 経路圧縮
    }

    // x と y が同じグループに属するか (= 根が一致するか)
    bool issame(int x, int y) {
        return root(x)==root(y);
    }

    // x を含むグループと y を含むグループを併合する
    bool unite(int x, int y) {
        int rx = root(x), ry = root(y); // x 側と y 側の根を取得する
        if (rx==ry) return false; // すでに同じグループのときは何もしない
        // union by rank
        if (rank[rx]<rank[ry]) swap(rx, ry); // ry 側の rank が小さくなるようにする
        par[ry] = rx; // ry を rx の子とする
        if (rank[rx]==rank[ry]) rank[rx]++; // rx 側の rank を調整する
        siz[rx] += siz[ry]; // rx 側の siz を調整する
        return true;
    }

    // x を含む根付き木のサイズを求める
    int size(int x) {
        return siz[root(x)];
    }
};

int main(void) {
    int n, m; cin >> n >> m;
    vvi g(n);
    UnionFind uf(n);
    rep(i,0,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        uf.unite(a, b);
    }
    bool ok = true;
    rep(i,0,n) {
        if (g[i].size() != 2) {
            ok = false;
            break;
        }
    }
    if (uf.size(0) != n) {
        ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
}