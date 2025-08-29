/*
FENWICK TREE
Purpose: This allows for quick prefix sum/minimum/etc. queries and updates in an array
Space Complexity: O(N)
*/

template <class T> struct fenwick_tree {

    // Stores the actual binary-indexed tree
    vector<T> bit;

    // Constructs a binary-indexed tree of all 0s (Time Complexity: O(N))
    void init(int n) { bit = vector<T>(n, 0); }

    // Constructs a binary-indexed tree based on an array (Time Complexity: O(N))
    void init (const vector<T> &arr) {
        int n = arr.size();
        bit = vector<T>(n, 0);
        for (int i = 0; i < n; i++) {
            bit[i] += arr[i];
            int ni = i | (i + 1);
            if (ni < n) bit[ni] += bit[i];
        }
    }

    // Updates the element in the index pos (Time Complexity: O(log(N)))
    void update(int idx, T add) {
        for (int i = idx; i < (int)bit.size(); i |= i + 1)
            bit[i] += add;
    }

    // Gives us the sum of all elements in the range [0, pos] (Time Complexity: O(log(N)))
    T query(int idx) {
        T sum = 0;
        for (int i = idx; i >= 0; i = (i & (i + 1)) - 1)
            sum += bit[i];
        return sum;
    }

};
