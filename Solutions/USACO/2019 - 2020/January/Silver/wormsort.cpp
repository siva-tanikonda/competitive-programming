#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m, p[100001];
tuple<int, int, int> edg[100000];

void dfs(int vtx, int src, vector<vector<int>> &adj, vector<int> &vis, vector<int> &cov){
    vis[vtx] = src, cov.push_back(vtx);
    for(int i : adj[vtx])
        if(!vis[i]) dfs(i, src, adj, vis, cov);
}

bool check(int mn){
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        tie(u, v, w) = edg[i];
        if(w < mn) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1);
    for(int i = 1; i <= n; i++)
        if(!vis[i]){
            vector<int> cov;
            dfs(i, i, adj, vis, cov);
            for(int j : cov)
                if(vis[p[j]] != i) return false;
        }
    return true;
}

int main(){
    IO("wormsort.in", "wormsort.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edg[i] = make_tuple(u, v, w);
    }
    int l = 1, r = 1e9 + 1;
    while(l < r){
        int mid = l + (r - l + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    if(r == 1e9 + 1) cout << "-1\n";
    else cout << l << '\n';
    return 0;
}