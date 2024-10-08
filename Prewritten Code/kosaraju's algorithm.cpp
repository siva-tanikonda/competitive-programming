/*
KOSARAJU'S ALGORITHM
Purpose: This algorithm finds the strongly-connected components of a graph
Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

struct kosaraju{
    vector<vector<int>> adj[2];
    vector<bool> vis;
    int n;
    void init(int _n){
        n = _n;
        for(int i = 0; i < 2; i++)
            adj[i].resize(n + 1);
        vis.resize(n + 1);
    }
    void addEdge(int u, int v){
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }
    void dfs(int vtx, int id, vector<int> &arr){
        vis[vtx] = true;
        for(int i : adj[id][vtx])
            if(!vis[i]) dfs(i, id, arr);
        arr.push_back(vtx);
    }
    vector<vector<int>> solve(){
        vector<int> ord;
        for(int i = 1; i <= n; i++)
            if(!vis[i]) dfs(i, 0, ord);
        fill(vis.begin(), vis.end(), false);
        reverse(ord.begin(), ord.end());
        vector<vector<int>> ans;
        for(int i : ord)
            if(!vis[i]){
                vector<int> cmp;
                dfs(i, 1, cmp), ans.push_back(cmp);
            }
        return ans;
    }
};