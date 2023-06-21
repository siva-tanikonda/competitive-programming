/*
SEGMENT TREE
Purpose: This is a data structure that allows for quick range queries and point updates.
Time Complexity: [Build]O(n) [Update]O(lg(n)) [Query]O(lg(n))
Space Complexity: O(n)
*/

template <class T> struct segment_tree {

    vector<T> arr;
    int n;

    void init(int an) { n = an, arr = vector<T>(4 * n + 1); }
    void init(vector<T> &a) {
        n = a.size(), arr = vector<T>(4 * n + 1);
        build(1, 0, n - 1, a);
    }
    void init(int an, T a[]) {
        n = an, arr = vector<T>(4 * n + 1);
        vector<T> av(n);
        for (int i = 0; i < n; i++) av[i] = a[i];
        build(1, 0, n - 1, av);
    }

    //Fills the segment tree given the array of data (Time Complexity: O(N))
    void build(int vtx, int l, int r, vector<T> &a) {
        if (l == r) arr[vtx] = a[l];
        else {
            int mid = l + (r - l) / 2;
            build(vtx * 2, l, mid, a);
            build(vtx * 2 + 1, mid + 1, r, a);
            arr[vtx] = arr[vtx * 2] + arr[vtx * 2 + 1];
        }
    }

    //Queries the range [l, r] (Time Complexity: O(Nlog(N)))
    T query(int vtx, int l, int r, int gl, int gr) {
        if (l > gr || r < gl) return 0;
        else if (l == gl && r == gr) return arr[vtx];
        else {
            int mid = l + (r - l) / 2;
            T r1 = query(vtx * 2, l, mid, gl, min(gr, mid));
            T r2 = query(vtx * 2 + 1, mid + 1, r, max(gl, mid + 1), gr);
            return r1 + r2;
        }
    }
    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    //Updates a value in the array (Time Complexity: O(Nlog(N)))
    void update(int vtx, int l, int r, int idx, T val) {
        if (l == idx && r == idx) arr[vtx] = val;
        else {
            int mid = l + (r - l) / 2;
            if (idx <= mid) update(vtx * 2, l, mid, idx, val);
            else update(vtx * 2 + 1, mid + 1, r, idx, val);
            arr[vtx] = arr[vtx * 2] + arr[vtx * 2 + 1];
        }
    }
    void update(int idx, T val) {
        update(1, 0, n - 1, idx, val);
    }
    
};