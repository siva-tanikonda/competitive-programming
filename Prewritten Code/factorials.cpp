/*
FACTORIALS CLASS
Purpose: This is a class for basic combinatorics (permutations, combinations, and factorials)
Space Complexity: O(N)
*/

struct factorials {

    // Stores factorials and inverse factorials
    vector<int> arr, narr;

    // Populates the factorials and inverse factorials arrays (Time Complexity: O(N*log(N)))
    void init(int n) {
        arr = vector<int>(n, 1);
        narr = vector<int>(n, 1);
        for (int i = 1; i < n; i++) {
            arr[i] = mod.mul(arr[i - 1], i);
            narr[i] = mod.inv(arr[i]);
        }
    }

    // Returns x! (Time Complexity: O(1))
    int fac(int x) { return arr[x]; }

    // Returns n choose m times m! (Time Complexity: O(1))
    int perm(int n, int m) {
        if (n < m) return 0;
        return mod.mul(arr[n], narr[n - m]);
    }

    // Returns n choose m (Time Complexity: O(1))
    int comb(int n, int m) { return mod.mul(perm(n, m), narr[m]); }

};
