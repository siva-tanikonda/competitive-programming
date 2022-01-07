#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
vector<int> adj[101];

void dfs(int vtx, vector<bool> &vis){
    vis[vtx] = true;
    for(int i : adj[vtx]) dfs(i, vis);
}

int main(){
    IO("factory.in", "factory.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        vector<bool> vis(n + 1);
        dfs(i, vis);
        bool work = true;
        for(int j = 1; j <= n; j++)
            work &= vis[j];
        if(work){
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}