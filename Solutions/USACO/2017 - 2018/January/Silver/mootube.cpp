#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, q;
vector<pair<int, int>> adj[5001];

int dfs(int vtx, int pre, int cur, int lim){
    int res = 1;
    for(auto &i : adj[vtx])
        if(i.first != pre && min(cur, i.second) >= lim)
            res += dfs(i.first, vtx, min(cur, i.second), lim);
    return res;
}

int main(){
    IO("mootube.in", "mootube.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for(int i = 0; i < q; i++){
        int k, v;
        cin >> k >> v;
        cout << dfs(v, 0, INT_MAX, k) - 1 << '\n';
    }
    return 0;
}