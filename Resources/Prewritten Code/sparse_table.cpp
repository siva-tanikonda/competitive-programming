/*
SPARSE TABLE
Purpose: This allows for fast range queries on static arrays
Time Complexity: [Build]O(nlg(n)) [Query]O(1)
Space Complexity: O(nlg(n))
*/

template<class T> struct sparse_table{
    vector<vector<T>> jmp;
    void init(vector<T> &arr){
        int n = (int)arr.size(), dpt = 32 - __builtin_clz(n);
        jmp = vector<vector<T>>(dpt, arr);
        for(int i = 0; i < dpt - 1; i++)
            for(int j = 0; j < n; j++)
                jmp[i + 1][j] = min(jmp[i][j], jmp[i][min(j + (1 << i), n - 1)]);
    }
    T query(int l, int r){
        int dpt = 31 - __builtin_clz(r - l + 1);
        return min(jmp[dpt][l], jmp[dpt][r - (1 << dpt) + 1]);
    }
};