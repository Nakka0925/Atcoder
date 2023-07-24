#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// 入力
int h, w;
vector<string> field;

// 探索
bool seen[510][510]; // seen[h][w] := マス (h, w) が検知済みかどうか
void dfs(int htmp, int wtmp) {
    seen[htmp][wtmp] = true;

    // 四方向を探索
    for (int dir = 0; dir < 4; ++dir) {
        int nh = htmp + dx[dir];
        int nw = wtmp + dy[dir];

        // 場外アウトしたり、移動先が壁の場合はスルー
        if (nh < 0 || nh >= h || nw < 0 || nw >= w) continue;
        if (field[nh][nw] == '#') continue;

        // 移動先が探索済みの場合
        if (seen[nh][nw]) continue;

        // 再帰的に探索
        dfs(nh, nw);
    }
}

int main() {
    // 入力受け取り
    cin >> h >> w;
    field.resize(h);
    for (int i = 0; i < h; i++) cin >> field[i];

    // s と g のマスを特定する
    int sh, sw, gh, gw;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (field[i][j] == 's') sh = i, sw = j;
            if (field[i][j] == 'g') gh = i, gw = j;
        }
    }

    // 探索開始
    memset(seen, 0, sizeof(seen)); // seen 配列全体を false に初期化
    dfs(sh, sw);

    // 結果
    if (seen[gh][gw]) cout << "Yes" << endl;
    else cout << "No" << endl;
}