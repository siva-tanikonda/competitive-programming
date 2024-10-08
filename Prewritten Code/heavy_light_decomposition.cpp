/*
HEAVY-LIGHT DECOMPOSITION
Purpose: This algorithm splits a tree into paths of max length lg(n)
Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

struct heavy_light_decomposition{
    int cur;
    vector<int> dep, hvy, hd, pos;
    void init(vector<vector<int>> &adj){
        dep.resize((int)adj.size());
        hvy.resize((int)adj.size(), -1);
        hd.resize((int)adj.size());
        pos.resize((int)adj.size());
        dfs1(1, 0, adj), dfs2(1, 1, 0, adj);
    }
    int dfs1(int vtx, int pre, vector<vector<int>> &adj){
        int sz = 0, msz = 0;
        for(int i : adj[vtx])
            if(i != pre){
                dep[i] = dep[vtx] + 1;
                int add = dfs1(i, vtx, adj);
                sz += add;
                if(msz < add) msz = add, hvy[vtx] = i;
            }
        return sz;
    }
    void dfs2(int vtx, int up, int pre, vector<vector<int>> &adj){
        pos[vtx] = cur++, hd[vtx] = up;
        if(hvy[vtx] != -1) dfs2(hvy[vtx], up, vtx, adj);
        for(int i : adj[vtx])
            if(i != pre && i != hvy[vtx])
                dfs2(i, i, vtx, adj);
    }
};