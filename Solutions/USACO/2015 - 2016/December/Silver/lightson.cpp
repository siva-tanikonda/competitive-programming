#pragma GCC optimize("unroll-loops", "O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

const int xx[4] = {-1, 0, 1, 0};
const int yy[4] = {0, -1, 0, 1};
int n, m;
bool vis[101][101], on[101][101], que[101][101];
vector<pair<int, int>> con[101][101];

int main(){
    IO("lightson.in", "lightson.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        con[x][y].emplace_back(a, b);
    }
    on[1][1] = true;
    queue<pair<int, int>> nxt;
    nxt.emplace(1, 1);
    while(!nxt.empty()){
        int x = nxt.front().first, y = nxt.front().second;
        nxt.pop(), vis[x][y] = true;
        for(auto &i : con[x][y]){
            on[i.first][i.second] = true;
            if(que[i.first][i.second])
                que[i.first][i.second] = false, nxt.push(i);
        }
        for(int i = 0; i < 4; i++){
            int nx = x + xx[i], ny = y + yy[i];
            if(min(nx, ny) > 0 && max(nx, ny) <= n && !vis[nx][ny]){
                if(on[nx][ny]) nxt.emplace(nx, ny);
                else que[nx][ny] = true;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) ans += on[i][j];
    cout << ans << '\n';
    return 0;
}