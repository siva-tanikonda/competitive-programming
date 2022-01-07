#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m, x[100001], y[100001];
vector<int> adj[100001];
bool vis[100001];

void dfs(int vtx, tuple<int, int, int, int> &rect){
    vis[vtx] = true;
    get<0>(rect) = min(get<0>(rect), x[vtx]);
    get<1>(rect) = max(get<1>(rect), x[vtx]);
    get<2>(rect) = min(get<2>(rect), y[vtx]);
    get<3>(rect) = max(get<3>(rect), y[vtx]);
    for(int i : adj[vtx])
        if(!vis[i]) dfs(i, rect);
}

int main(){
    IO("fenceplan.in", "fenceplan.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++)
        if(!vis[i]){
            tuple<int, int, int, int> rect(1e8 + 1, 0, 1e8 + 1, 0);
            dfs(i, rect);
            int l, r, b, t;
            tie(l, r, b, t) = rect;
            ans = min(ans, 2 * (r - l) + 2 * (t - b));
        }
    cout << ans << '\n';
    return 0;
}