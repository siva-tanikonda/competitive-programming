/*
UNION-FIND DATA STRUCTURE
Purpose: This allows for maintaining a list of forests and merging them (with the list being initially n 1-sized forests)
Time Complexity: [Merge]O(T(n)) [Find]O(T(n))
                 *T(n) is on-average log(n) at the end of merging every single vertex
Space Complexity: O(n)
*/

struct union_find {

    vector<int> par;
    int cnt;
    
    void init(int n) { par.resize(n + 1, -1), cnt = n; }
    
    //Gets the number of elements in the set that vertex x is a part of 
    int size(int x) { return -par[find(x)]; }
    
    //Finds the set that vertex x is a part of (and reduces the height of the tree for optimization)
    int find(int x) {
        return (par[x] < 0) ? x : par[x] = find(par[x]);
    }

    //Finds whether vertices x and y are part of the same set
    int same(int x, int y) { return find(x) == find(y); }

    //Unites the forests that a and b are part of (returns true if a and b aren't part of the same forest already)
    //Small-to-large merging optimization used
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (size(x) < size(y)) swap(x, y);
        par[x] += par[y], par[y] = x, cnt--;
        return true;
    }
    
};