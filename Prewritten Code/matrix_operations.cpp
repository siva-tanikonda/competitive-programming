/*
MATRIX OPERATIONS CLASS
Purpose: This is just a class that supports basic matrix operations
*/

struct matrix_operations {

    //Element-wise addition of two matrices (Time Complexity: O(nm))
    vector<vector<ll>> add(vector<vector<ll>> &a, vector<vector<ll>> &b) {
        vector<vector<ll>> res(a.size(), vector<ll>(a[0].size()));
        for (int i = 0; i < (int)a.size(); i++)
            for (int j = 0; j < (int)a[0].size(); j++)
                res[i][j] = a[i][j] + b[i][j];
        return res;
    }

    //Element-wise subtraction of two matrices (Time Complexity: O(nm))
    vector<vector<ll>> sub(vector<vector<ll>> &a, vector<vector<ll>> &b) {
        vector<vector<ll>> res(a.size(), vector<ll>(a[0].size()));
        for (int i = 0; i < (int)a.size(); i++)
            for (int j = 0; j < (int)a[0].size(); j++)
                res[i][j] = a[i][j] - b[i][j];
        return res;
    }

    //Typical matrix multiplication (Time Complexity: O(nmk))
    vector<vector<ll>> mul(vector<vector<ll>> &a, vector<vector<ll>> &b) {
        vector<vector<ll>> res(a.size(), vector<ll>(b[0].size()));
        for (int i = 0; i < (int)a.size(); i++)
            for (int j = 0; j < (int)b[0].size(); j++)
                for (int k = 0; k < (int)a[0].size(); k++)
                    res[i][j] += a[i][k] * b[k][j];
        return res;
    }

    //Creates an nxn identity matrix (Time Complexity: O(n^2))
    vector<vector<ll>> identity(int n) {
        vector<vector<ll>> res(n, vector<ll>(n));
        for (int i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }

    //Exponentiates a square matrix (binary exponentiation) (Time Complexity: O(m^3log(n)))
    vector<vector<ll>> pow(vector<vector<ll>> &x, ll n) {
        if (!n) return identity(x.size());
        vector<vector<ll>> res = pow(x, n / 2);
        res = mul(res, res);
        if (n % 2) res = mul(res, x);
        return res;
    }

};

//Creates an instance of the class to use for operations
matrix_operations mat;