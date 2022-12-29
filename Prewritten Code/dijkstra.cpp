/*
DIJKSTRA'S ALGORITHM
Purpose: Find the shortest path from one node to all other nodes on a graph (without negative edges)
Time Complexity: O(Mlg(N))
Space Complexity: O(M + N)
*/

template<class T> struct dijkstra {
    vector<vector<pair<int, T>>> adj;
    vector<T> dst;
    vector<int> pre;
    void init(int n, vector<pair<int, T>> inp[]) {
        adj = vector<vector<pair<int, T>>>(n + 1, vector<pair<int, T>>());
        for (int i = 1; i <= n; i++) adj[i] = inp[i];
    }
    void init(vector<vector<pair<int, T>>> &inp) { adj = inp; }
    void getPaths(int src) {
        dst = vector<T>(adj.size(), -1);
        pre = vector<int>(adj.size());
        set<pair<T, int>> que;
        que.emplace(0, src);
        dst[src] = 0;
        while (!que.empty()) {
            int vtx = que.begin()->second;
            que.erase(que.begin());
            for (auto &i : adj[vtx])
                if (dst[i.first] == -1 || dst[i.first] > dst[vtx] + i.second) {
                    que.erase({ dst[i.first], i.first });
                    dst[i.first] = dst[vtx] + i.second;
                    pre[i.first] = vtx;
                    que.emplace(dst[i.first], i.first);
                }
        }
    }
};