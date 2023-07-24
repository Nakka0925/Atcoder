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
#define print_y cout << "Yes" << endl
#define print_n cout << "No" << endl
#define rep(i,n) for (int i = 0; i < (n); i++)
const int mod=998244353;

void print_yes_no(bool flag) {
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

// 深さ優先探索
vector<bool> seen;
void dfs(vvi &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    int n, m; cin >> n >> m;

    // グラフ入力受取 (ここでは無向グラフを想定)
    vvi G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 0 をスタートとした探索
    seen.assign(n, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0);
}