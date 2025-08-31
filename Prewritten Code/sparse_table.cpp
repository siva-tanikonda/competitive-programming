/*
SPARSE TABLE
Purpose: This allows for fast range queries on a static array
Space Complexity: O(N*log(N))
*/

template <class T> struct sparse_table {

    // Stores the log-length range queries
    vector<vector<T>> arr;

    // Constructs the actual sparse table (Time Complexity: O(N*log(N)))
    void init(const vector<T> &a) {
        int n = a.size();
        int dep = 32 - __builtin_clz(n);
        arr = vector<vector<T>>(dep, a);
        for(int i = 0; i < dep - 1; i++)
            for(int j = 0; j < n; j++)
                dep[i + 1][j] = min(dep[i][j], dep[i][min(n - 1, j + (1 << i))]);
    }

    // Performs a query for a specific range (Time Complexity: O(1))
    T query(int l, int r) {
        int dep = 31 - __builtin_clz(r - l + 1);
        return min(arr[dep][l], arr[dep][r - (1 << dep) + 1]);
    }

};
