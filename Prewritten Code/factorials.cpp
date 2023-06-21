/*
FACTORIALS CLASS
Purpose: This is just a basic class for maintaining factorials modded by a certain number
Space Complexity: O(n)
*/

struct factorials {

    vector<int> fac, inv;

    //Calculates the factorials and the modular inverses of the factorials (Time Complexity: O(Nlog(N)))
    void init(int n) {
        fac = vector<int>(n + 1);
        inv = vector<int>(n + 1);
        fac[0] = inv[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = mod.mul(fac[i - 1], i);
            inv[i] = mod.inv(fac[i]);
        }
    }
    //Gives us x! (Time Complexity: O(1))
    int query(int x) { return fac[x]; }
    
    //Gives us xPy (Time Complexity: O(1))
    int prm(int x, int y) {
        if (y > x) return 0;
        return mod.mul(fac[x], inv[x - y]);
    }

    //Gives us x choose y (Time Complexity: O(1))
    int cmb(int x, int y) {
        if (y > x) return 0;
        return mod.mul(prm(x, y), inv[y]);
    }
    
};