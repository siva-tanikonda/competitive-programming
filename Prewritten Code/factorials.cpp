/*
FACTORIALS
Purpose: This is just a basic class for maintaining factorials modded by a certain number
Time Complexity: [Build]O(nlg(n)) [Query]O(1)
Space Complexity: O(n)
*/

struct factorials {
    vector<int> fac, inv;
    void init(int n) {
        fac = vector<int>(n + 1);
        inv = vector<int>(n + 1);
        fac[0] = inv[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = mod.mult(fac[i - 1], i);
            inv[i] = mod.inv(fac[i]);
        }
    }
    int prm(int x, int y) {
        if (y > x) return 0;
        return mod.mult(fac[x], inv[x - y]);
    }
    int cmb(int x, int y) {
        if (y > x) return 0;
        return mod.mult(prm(x, y), inv[y]);
    }
};