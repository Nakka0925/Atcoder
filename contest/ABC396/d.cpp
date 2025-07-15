#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vb = vector<bool>;
const ll INF = 1LL << 60;

// XOR基底を保持
vector<ll> basis;

void add_to_basis(ll x) {
    for (ll b : basis) x = min(x, x ^ b);
    if (x) basis.push_back(x);
}

ll minimize_with_basis(ll x) {
    for (ll b : basis) x = min(x, x ^ b);
    return x;
}

int main() {
    int n, m;
    cin >> n >> m;

    // 隣接リスト + 重み
    vector<vector<pair<int, ll>>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    // dist[i] = 頂点0からiまでのXOR距離
    vl dist(n, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto [nv, w] : g[v]) {
            if (dist[nv] == -1) {
                dist[nv] = dist[v] ^ w;
                que.push(nv);
            } else {
                // サイクル検出 → XOR基底に追加
                ll cycle = dist[v] ^ w ^ dist[nv];
                add_to_basis(cycle);
            }
        }
    }

    // 頂点N-1への最短XORをXOR基底で最小化
    ll ans = minimize_with_basis(dist[n - 1]);
    cout << ans << endl;
}
