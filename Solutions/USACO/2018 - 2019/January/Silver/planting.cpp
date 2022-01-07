#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
vector<int> adj[100001];

int main(){
    IO("planting.in", "planting.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 1;
    for(int i = 0; i < n; i++)
        ans = max(ans, (int)adj[i].size() + 1);
    cout << ans << '\n';
    return 0;
}