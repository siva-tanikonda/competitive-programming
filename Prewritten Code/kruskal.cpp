/*
KRUSKAL'S ALGORITHM
Purpose: calculates the minimum-spanning tree for a given undirected graph
Time Complexity: O(M*(log(M)+alpha(N))+N)
Space Complexity: O(M+N)
*/

template <class T> vector<tuple<T, int, int>> kruskal(int n, vector<tuple<T, int, int>> edg) {
    union_find dsu;
    dsu.init(n, true);
    sort(edg.begin(), edg.end());
    vector<tuple<T, int, int>> tree;
    for (tuple<T, int, int> &e : edg) {
        T w;
        int u, v;
        tie(w, u, v) = e;
        if (dsu.merge(u, v)) tree.emplace_back(w, u, v);
        if (dsu.cnt == 1) return tree;
    }
    return vector<tuple<T, int, int>>();
}
