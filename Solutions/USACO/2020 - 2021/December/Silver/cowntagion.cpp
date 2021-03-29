#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100001];

int dfs(int vtx, int pre){
    int need = adj[vtx].size() + 1 - (pre != 0);
    int res = 31 - __builtin_clz(need);
    if((1 << res) < need) res++;
    for(int i : adj[vtx])
        if(i != pre) res += dfs(i, vtx) + 1;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs(1, 0) << '\n';
    return 0;
}