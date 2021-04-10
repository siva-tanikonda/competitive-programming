#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;

int n, vis[400001];
vector<int> adj[400001];
tuple<int, int, int, int, int> edg[100000];

struct union_find{
    vector<int> par;
    void init(int n) { par.resize(n, -1); }
    int size(int x) { return -par[find(x)]; }
    int find(int x){
        return (par[x] < 0) ? x : par[x] = find(par[x]);
    }
    bool unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return false;
        if(size(a) < size(b)) swap(a, b);
        par[a] += par[b], par[b] = a;
        return true;
    }
};

void dfs(int vtx, int cyc){
    vis[vtx] = cyc;
    for(int i : adj[vtx])
        if(!vis[i]) dfs(i, cyc);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        int c, p[4];
        cin >> c;
        for(int j = 0; j < 4; j++) cin >> p[j];
        adj[p[0]].push_back(p[1]);
        adj[p[1]].push_back(p[0]);
        adj[p[2]].push_back(p[3]);
        adj[p[3]].push_back(p[2]);
        edg[i] = make_tuple(c, p[0], p[1], p[2], p[3]);
    }
    int cyc = 0;
    for(int i = 1; i <= 2 * n; i++)
        if(!vis[i]) dfs(i, ++cyc);
    sort(edg, edg + n);
    union_find dsu;
    dsu.init(4 * n + 1);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x, a, b, c, d;
        tie(x, a, b, c, d) = edg[i];
        int cmp1 = vis[a], cmp2 = vis[c];
        bool use = dsu.unite(cmp1, cmp2);
        if(use) ans += x;
    }
    cout << ans << '\n';
    return 0;
}