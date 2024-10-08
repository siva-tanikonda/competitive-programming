/*
FENWICK TREE
Purpose: This allows for quick prefix queries and updates in an array of length n
Space Complexity: O(n)
*/

template <class T> struct fenwick_tree {

    vector<T> arr;

    void init(int n) { arr = vector<int>(n + 1, 0); }

    //Updates the element in the index pos (Time Complexity: O(log(N)))
    void update(int pos, T add) {
        for (; pos < (int)arr.size(); pos |= pos + 1)
            arr[pos] += add;
    }

    //Gives us the sum of all elements in the range [0, pos] (Time Complexity: O(log(N)))
    T query(int pos) {
        T sum = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
            sum += arr[pos];
        return sum;
    }

};