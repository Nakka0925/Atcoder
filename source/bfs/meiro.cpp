#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i,n) for (int i = 0; i < (n); i++)
const int mod=998244353;

int main(void) {
    int h,w; cin >> h >> w;
    vector<pair<int,int>> d = {{1,0},{0,-1},{-1,0},{0,1}},ans;
    map<int,int> mp;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<vector<bool>> chk(h,vector<bool>(w,true));

    queue<pair<int,int>> que;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') continue; 
            if (!chk[i][j]) continue;
            que.push({i,j});
            while (!que.empty()) {
                pair<int,int> current = que.front();que.pop();
                int y = current.first;
                int x = current.second;
                chk[y][x] = false;
                for (auto k : d) {
                    int next_x = x + k.first;
                    int next_y = y + k.second;
                    if (next_x < 0 || next_x >= w || next_y < 0 || next_y >= h) continue;
                    if (s[next_y][next_x] == '.') continue; 
                    if (chk[next_y][next_x]) {
                        que.push({next_y, next_x});
                        chk[next_y][next_x] = false;
                    }
                }
            }
        }
    }
}