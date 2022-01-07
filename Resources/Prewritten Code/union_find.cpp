/*
UNION-FIND DATA STRUCTURE
Purpose: This allows for maintaining a list of forests and merging them
Time Complexity: [Merge]O(T(n)) [Find]O(T(n))
Space Complexity: O(n)
*/

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