/*
LAZY SEGMENT TREE
Purpose: This is a segment tree that supports range queries and range updates on select operations
Time Complexity: [Build]O(n) [Update]O(lg(n)) [Query]O(lg(n))
Space Complexity: O(n)
*/

template<class T> struct lazy_segment_tree{
    vector<T> arr, lzy;
    int n;
    void init(int _n){
        n = _n;
        arr.resize(n * 4), lzy.resize(n * 4);
    }
    void init(vector<T> &lst){
        n = (int)lst.size();
        arr.resize(n * 4), lzy.resize(n * 4);
        build(1, 0, n - 1, lst);
    }
    void build(int vtx, int tl, int tr, vector<T> &lst){
        if(tl == tr) arr[vtx] = lst[tl];
        else{
            int mid = tl + (tr - tl) / 2;
            build(vtx * 2, tl, mid, lst);
            build(vtx * 2 + 1, mid + 1, tr, lst);
            arr[vtx] = arr[vtx * 2] + arr[vtx * 2 + 1];
        }
    }
    void push(int vtx, int tl, int tr){
        int mid = tl + (tr - tl) / 2;
        arr[vtx * 2] += (mid - tl + 1) * lzy[vtx];
        lzy[vtx * 2] += lzy[vtx];
        arr[vtx * 2 + 1] += (tr - mid) * lzy[vtx];
        lzy[vtx * 2 + 1] += lzy[vtx];
        lzy[vtx] = 0;
    }
    void update(int vtx, int tl, int tr, int l, int r, T val){
        if(l > r) return;
        else if(l == tl && r == tr){
            arr[vtx] += (tr - tl + 1) * val;
            lzy[vtx] += val;
        }else{
            push(vtx, tl, tr);
            int mid = tl + (tr - tl) / 2;
            update(vtx * 2, tl, mid, l, min(mid, r), val);
            update(vtx * 2 + 1, mid + 1, tr, max(mid + 1, l), r, val);
            arr[vtx] = arr[vtx * 2] + arr[vtx * 2 + 1];
        }
    }
    void update(int l, int r, T val){
        update(1, 0, n - 1, l, r, val);
    }
    T query(int vtx, int tl, int tr, int l, int r){
        if(l > r) return 0;
        else if(l == tl && r == tr) return arr[vtx];
        else{
            push(vtx, tl, tr);
            int mid = tl + (tr - tl) / 2;
            T p1 = query(vtx * 2, tl, mid, l, min(r, mid));
            T p2 = query(vtx * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
            return p1 + p2;
        }
    }
    T query(int l, int r){
        return query(1, 0, n - 1, l, r);
    }
};