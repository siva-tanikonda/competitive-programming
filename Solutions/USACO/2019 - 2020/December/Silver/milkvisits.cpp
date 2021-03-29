#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m, pos[100001];
string s;
vector<int> adj[100001];

void dfs(int vtx, int pre, int src){
    pos[vtx] = src;
    for(int i : adj[vtx])
        if(i != pre && s[i] == s[vtx])
            dfs(i, vtx, src);
}

int main(){
    IO("milkvisits.in", "milkvisits.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> s;
    s = ' ' + s;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i < n; i++)
        if(!pos[i]) dfs(i, 0, i);
    for(int i = 0; i < m; i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        cout << !(pos[a] == pos[b] && s[a] != c);
    }
    cout << '\n';
    return 0;
}