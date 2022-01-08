/*
TWO-DIMENSIONAL FENWICK TREE
Purpose: This allows for 2D prefix queries and updates
Time Complexity: [Update]O(lg^2(n)) [Query]O(lg^2(n))
Space Complexity: O(n^2)
*/

template<class T> struct two_dimensional_fenwick_tree{
    vector<vector<T>> arr;
    void init(int n, int m){
        arr.resize(n, vector<T>(m));
    }
    void update(int x, int y, T add){
        for(; x < (int)arr.size(); x |= x + 1)
            for(int i = y; i < (int)arr[0].size(); i |= i + 1)
                arr[x][i] += add;
    }
    T query(int x, int y){
        T sum = 0;
        for(; x >= 0; x = (x & (x + 1)) - 1)
            for(int i = y; i >= 0; i = (i & (i + 1)) - 1)
                sum += arr[x][i];
        return sum;
    }
};