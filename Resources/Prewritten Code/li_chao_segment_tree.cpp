/*
LI CHAO SEGMENT TREE
Purpose: This is a segment tree that can maintain operations for a dynamic convex hulll trick
Time Complexity: [Update]O(lg(n)) [Query]O(lg(n))
Space Complexity: O(n)
*/

template<class T> struct li_chao_segment_tree{
    vector<line<T>> arr;
    int n;
    void init(int _n){
        n = _n;
        arr.resize(4 * n + 4, line<T>(0, INF)); 
    }
    void add(int vtx, int tl, int tr, line<T> val){
        int mid = tl + (tr - tl) / 2;
        bool l = val.evaluate(tl) < arr[vtx].evaluate(tl);
        bool m = val.evaluate(mid) < arr[vtx].evaluate(mid);
        if(m) swap(arr[vtx], val);
        if(tr - tl == 1) return;
        else if(l != m) add(vtx * 2, tl, mid, val);
        else add(vtx * 2 + 1, mid, tr, val);
    }
    void add(line<T> val) { add(1, 0, n, val); }
    T query(int vtx, int tl, int tr, int x){
        int mid = tl + (tr - tl) / 2;
        if(tr - tl == 1) return arr[vtx].evaluate(x);
        else if(x < mid)
            return min(arr[vtx].evaluate(x), query(vtx * 2, tl, mid, x));
        else
            return min(arr[vtx].evaluate(x), query(vtx * 2 + 1, mid, tr, x));
    }
    T query(int x) { return query(1, 0, n, x); }
};