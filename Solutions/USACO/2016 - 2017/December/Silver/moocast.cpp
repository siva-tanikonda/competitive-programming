#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, x[200], y[200], p[200];

void dfs(int vtx, vector<bool> &vis){
    vis[vtx] = true;
    for(int i = 0; i < n; i++)
        if(!vis[i] && (x[i] - x[vtx]) * (x[i] - x[vtx]) + (y[i] - y[vtx]) * (y[i] - y[vtx]) <= p[vtx] * p[vtx])
            dfs(i, vis);
}

int main(){
    IO("moocast.in", "moocast.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> p[i];
        p[i] = min(p[i], 50000);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        vector<bool> vis(n);
        dfs(i, vis);
        ans = max(ans, accumulate(vis.begin(), vis.end(), 0));
    }
    cout << ans << '\n';
    return 0;
}