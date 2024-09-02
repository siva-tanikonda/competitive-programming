/*
MODULAR ARITHMETIC CLASS
Purpose: This is just a class that supports modular arithmetic operations (only with a prime modulus)
*/

struct modular_arithmetic {

    const int m = 1e9 + 7; //const int m = 998244353;

    //Returns (x + y) mod m (Time Complexity: O(1))
    int add(ll x, ll y) {
        return ((x % m + m) % m + (y % m + m) % m) % m;
    }

    //Returns (x - y) mod m (Time Complexity: O(1))
    int sub(ll x, ll y) {
        return (((x % m + m) % m - (y % m + m) % m) % m + m) % m;
    }

    //Returns (xy) mod m (Time Complexity: O(1))
    int mult(ll x, ll y) {
        return (((x % m + m) % m) * ((y % m + m) % m)) % m;
    }

    //Returns x^y mod m (Time Complexity: O(log(N)))
    int pow(ll x, ll y) {
        if (!y) return 1 % m;
        ll ans = pow(x, y / 2);
        ans = (ans * ans) % m;
        if (y % 2) ans = (ans * (x % m)) % m;
        return ans;
    }

    //Returns modular inverse of x mod m (Time Complexity: O(log(N)))
    int inv(ll x) {
        return pow(x, m - 2);
    }

    //Returns (xy^(-1)) mod m (Time Complexity: O(log(N)))
    int div(ll x, ll y) {
        return ((x % m) * inv(y)) % m;
    }

};

//Creates an instance of the class to use for operations
modular_arithmetic mod;