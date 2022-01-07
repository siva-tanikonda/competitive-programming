/*
LOWEST-COMMON ANCESTOR
Purpose: This finds the lowest-common ancestor of two nodes in a tree
Time Complexity: [Build]O(nlg(n)) [Query]O(1)
Space Complexity: O(nlg(n))
*/

struct lowest_common_ancestor{
    sparse_table<pair<int, int>> rmq;
    vector<int> hgt, fir;
    vector<pair<int, int>> eul;
    void init(vector<vector<int>> &adj){
        hgt.resize(adj.size());
        fir.resize(adj.size());
        dfs(adj, 1, 1, 0);
        rmq.init(eul);
    }
    void dfs(vector<vector<int>> &adj, int vtx, int pre, int h){
        hgt[vtx] = h;
        fir[vtx] = eul.size();
        eul.push_back(make_pair(h, vtx));
        for(int i : adj[vtx])
            if(i != pre){
                dfs(adj, i, vtx, h + 1);
                eul.push_back(make_pair(h, vtx));
            }
    }
    int query(int a, int b){
        a = fir[a], b = fir[b];
        if(a > b) swap(a, b);
        return rmq.query(a, b).second;
    }
};