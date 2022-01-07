#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m;
bool vis[3001], del[3001];
multiset<int> adj[3001];

int dfs(int vtx){
    vis[vtx] = true;
    int res = 1;
    for(int i : adj[vtx])
        if(!vis[i]) res += dfs(i);
    return res;
}

void check(int rem){
    fill(vis, vis + n + 1, false);
    for(int i = 1; i <= n; i++)
        if(!del[i]){
            int res = dfs(i);    
            cout << ((res == rem) ? "YES\n" : "NO\n");
            break;
        }
}

int main(){
    IO("closing.in", "closing.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].insert(v), adj[v].insert(u);
    }
    check(n);
    for(int i = 1; i < n; i++){
        int vtx;
        cin >> vtx, del[vtx] = true;
        for(int j : adj[vtx])
            adj[j].erase(adj[j].find(vtx));
        adj[vtx].clear();
        check(n - i);
    }
    return 0;
}