/*
PERSISTENT SEGMENT TREE
Purpose: This is a segment tree that keeps a history of past states
Time Complexity: [Build]O(n) [Update]O(lg(n)) [Query]O(lg(n))
Space Complexity: O(n)
*/

template<class T> struct node{
    node<T> *l, *r;
    T val;
    node<T>(T tval) : l(nullptr), r(nullptr), val(tval) {}
    node<T>(node* tl, node* tr) : l(tl), r(tr), val(0) {
        if(l) val += l -> val;
        if(r) val += r -> val;
    }
};
template<class T> struct persistent_segment_tree{
    vector<node<T>*> rts;
    int n;
    void init(int _n){
        n = _n;
        vector<T> arr;
        for(int i = 0; i < n; i++)
            arr.push_back(0);
        rts.push_back(build(arr, 0, n - 1)); 
    }
    void init(vector<T> &arr){
        n = (int)arr.size();
        rts.push_back(build(arr, 0, n - 1));
    }
    node<T>* build(vector<T> &arr, int tl, int tr){
        if(tl == tr) return new node<T>(arr[tl]);
        else{
            int mid = tl + (tr - tl) / 2;
            return new node<T>(build(arr, tl, mid), build(arr, mid + 1, tr));
        }
    }
    T query(int pre, int l, int r){
        return query(rts[pre], 0, n - 1, l, r);
    }
    T query(node<T> *vtx, int tl, int tr, int l, int r){
        if(l > r) return 0;
        else if(l == tl && r == tr) return vtx -> val;
        else{
            int mid = tl + (tr - tl) / 2;
            T p1 = query(vtx -> l, tl, mid, l, min(r, mid));
            T p2 = query(vtx -> r, mid + 1, tr, max(l, mid + 1), r);
            return p1 + p2;
        }
    }
    void update(int pre, int pos, T val){
        rts.push_back(update(rts[pre], 0, n - 1, pos, val));
    }
    node<T>* update(node<T> *vtx, int tl, int tr, int pos, T val){
        if(tl == tr) return new node<T>(val);
        else{
            int mid = tl + (tr - tl) / 2;
            if(pos <= mid)
                return new node<T>(update(vtx -> l, tl, mid, pos, val), vtx -> r);
            else
                return new node<T>(vtx -> l, update(vtx -> r, mid + 1, tr, pos, val));
        }
    }
};