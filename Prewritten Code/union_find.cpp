/*
UNION-FIND
Purpose: This allows for maintaining a list of forests and merging them
Space Complexity: O(N)
*/

struct union_find {

    // Array of parents (and tree sizes)
    vector<int> p;

    // Number of trees in the forest
    int cnt;

    // true if we want to use path compression, and false if not
    bool pc;
    
    void init(int n, bool path_compression = false) {
        p = vector<int>(n, -1);
        cnt = n, pc = path_compression;
    }
    
    //Gets the size of the tree vertex v is in (Time Complexity: O(log(N)) w/o path compression, O(alpha(N)) w/ path compression)
    int size(int v) { return -p[find(v)]; }
    
    //Finds the root of the tree vertex v is in (Time Complexity: O(log(N)) w/o path compression, O(alpha(N)) w/ path compression)
    int find(int v) {
        if (p[v] < 0) return v;
        int rt = find(p[v]);
        if (pc) p[v] = rt;
        return rt;
    }

    //Merges the tress that u and v are in (Time Complexity: O(log(N)) w/o path compression, O(alpha(N)) w/ path compression)
    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (size(u) < size(v)) swap(u, v);
        p[u] += p[v], p[v] = u, cnt--;
        return true;
    }
    
};
