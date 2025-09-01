/*
MODULAR ARITHMETIC CLASS
Purpose: This is a class that supports basic modular arithmetic for a prime modulus
Space Complexity: O(log(N))
*/

template <class T> struct modular_arithmetic {

    // The modulus we want to use
    const int m = 1e9 + 7;
    // const int m = 998244353;

    // Calculates (a + b) mod m (Time Complexity: O(1))
    int add(T a, T b) { return (a % m + b % m) % m; }

    // Calculates (a - b) mod m (Time Complexity: O(1))
    int sub(T a, T b) { return ((a % m - b % m) % m + m) % m; }

    // Calculates (a * b) mod m (Time Complexity: O(1))
    int mul(T a, T b) { return ((T)(a % m) * (b % m)) % m; }

    // Calculates (x ^ n) mod m (Time Complexity: O(log(N))) 
    int pow(T x, T n) { 
        if (!n) return 1;
        int res = pow(x, n / 2);
        res = mul(res, res);
        if (n % 2) res = mul(res, x);
        return res;
    }

    // Calculates (x ^ -1) mod m (Time Complexity: O(log(M)))
    int inv(T x) { return pow(x, m - 2); }

    // Calculates (x * (y ^ -1)) mod m (Time Complexity: O(log(M)))
    int div(T a, T b) { return mul(a, inv(b)); }

};
modular_arithmetic<TYPE> mod;
