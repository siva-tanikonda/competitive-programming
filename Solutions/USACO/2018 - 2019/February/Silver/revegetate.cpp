#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m, vis[100001];
vector<int> dif[100001], adj[100001][2];

void dfs1(int vtx, int src){
    vis[vtx] = src;
    for(int i : adj[vtx][0])
        if(!vis[i]) dfs1(i, src);
}

bool dfs2(int vtx, int col){
    vis[vtx] = col;
    bool work = true;
    for(int i : dif[vtx])
        if(!vis[i]) work &= dfs2(i, col * -1);
        else if(vis[i] == vis[vtx]) return false;
    return work;
}

int main(){
    IO("revegetate.in", "revegetate.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        char typ;
        int u, v;
        cin >> typ >> u >> v;
        int idx = (typ == 'S') ? 0 : 1;
        adj[u][idx].push_back(v);
        adj[v][idx].push_back(u);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(!vis[i]) dfs1(i, ++cnt);
    for(int i = 1; i <= n; i++)
        for(int j : adj[i][1]){
            if(vis[i] == vis[j]){
                cout << "0\n";
                return 0;
            }
            dif[vis[i]].push_back(vis[j]);
        }
    fill(vis, vis + n + 1, 0);
    int ans = 0;
    for(int i = 1; i <= cnt; i++)
        if(!vis[i]){
            bool res = dfs2(i, 1);
            if(!res){
                cout << "0\n";
                return 0;
            }
            ans++;
        }
    cout << '1';
    for(int i = 0; i < ans; i++) cout << '0';
    cout << '\n';
    return 0; 
}