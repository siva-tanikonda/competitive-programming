/*
FENWICK TREE
Purpose: This allows for quick prefix queries and updates
Time Complexity: [Update]O(lg(n)) [Query]O(lg(n))
Space Complexity: O(n)
*/

template<class T> struct fenwick_tree{
    vector<T> arr;
    void init(int n) { arr.resize(n); }
    void update(int pos, T add){
        for(; pos < (int)arr.size(); pos |= pos + 1)
            arr[pos] += add;
    }
    T query(int pos){
        T sum = 0;
        for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
            sum += arr[pos];
        return sum;
    }
};