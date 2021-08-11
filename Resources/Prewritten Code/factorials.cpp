/*
FACTORIALS
Purpose: This is just a basic class for maintaining factorials modded by a certain number
Time Complexity: [Build]O(nlg(n)) [Query]O(1)
Space Complexity: O(n)
*/

struct factorials{
    vector<int> fac, inv;
    void init(int n){
        fac = inv = vector<int>(n + 1);
        fac[0] = inv[0] = 1;
        for(int i = 1; i <= n; i++){
            fac[i] = mod.mult(fac[i - 1], i);
            inv[i] = mod.inv(fac[i]);
        }
    }
    int prm(int a, int b){
        if(a < b) return 0;
        else return mod.mult(fac[a], inv[a - b]);
    }
    int cmb(int a, int b){
        if(a < b) return 0;
        else return mod.mult(prm(a, b), inv[b]);
    }
};
factorials fact;