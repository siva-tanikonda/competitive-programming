/*
UNION-FIND DATA STRUCTURE
Purpose: This allows for maintaining a list of forests and merging them (with the list being initially n 1-sized forests)
Time Complexity: [Merge]O(T(n)) [Find]O(T(n))
                 *T(n) is on-average log(n) at the end of merging every single vertex
Space Complexity: O(n)
*/

struct union_find {

    vector<int> par;
    
    void init(int n) { par.resize(n + 1, -1); }
    
    //Gets the number of elements in the set that vertex x is a part of 
    int size(int x) { return -par[find(x)]; }
    
    //Finds the set that vertex x is a part of (and reduces the height of the tree for optimization)
    int find(int x) {
        return (par[x] < 0) ? x : par[x] = find(par[x]);
    }

    //Unites the forests that a and b are part of (returns true if a and b aren't part of the same forest already)
    //Small-to-large merging optimization used
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (size(a) < size(b)) swap(a, b);
        par[a] += par[b], par[b] = a;
        return true;
    }
    
};