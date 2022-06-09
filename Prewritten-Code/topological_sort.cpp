/*
TOPOLOGICAL SORT
Purpose: To get the topological sort of a DAG Graph
Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

struct topological_sort {
    vector<vector<int>> adj;
    vector<int> in;
    void init(int n, vector<int> inp[]) {
        adj = vector<vector<int>>(n + 1, vector<int>());
        for (int i = 1; i <= n; i++) adj[i] = inp[i];
    }
    void init(vector<vector<int>> inp) { adj = inp; }
    vector<int> getSort() {
        queue<int> que;
        vector<int> ord;
        in = vector<int>(adj.size());
        for (int i = 1; i < (int)adj.size(); i++)
            for (int j : adj[i]) in[j]++;
        for (int i = 1; i < (int)adj.size(); i++)
            if (!in[i]) que.push(i);
        while (!que.empty()) {
            int vtx = que.front();
            que.pop();
            ord.push_back(vtx);
            for (int i : adj[vtx])
                if (--in[i] <= 0) que.push(i);
        }
        return ord;
    }
};