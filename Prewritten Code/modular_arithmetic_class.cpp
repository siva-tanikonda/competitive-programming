/*
MODULAR ARITHMETIC CLASS
Purpose: This is just a class that supports modular arithmetic operations (only with a prime modulus and all positive values)
*/

struct modular_arithmetic {

    const int m = 1e9 + 7; //const int mod = 998244353;

    //Returns (x + y) mod m
    int add(ll x, ll y) {
        return ((x % m + m) % m + (y % m + m) % m) % m;
    }

    //Returns (x - y) mod m
    int sub(ll x, ll y) {
        return (((x % m + m) % m - (y % m + m) % m) % m + m) % m;
    }

    //Returns (xy) mod m
    int mult(ll x, ll y) {
        return (((x % m + m) % m) * ((y % m + m) % m)) % m;
    }

    //Returns x^y mod m (binary exponentiation)
    int pwr(ll x, ll y) {
        if (!y) return 1 % m;
        ll ans = pwr(x, y / 2);
        ans = (ans * ans) % m;
        if (y % 2) ans = (ans * (x % m)) % m;
        return ans;
    }

    //Returns modular inverse of x mod m (using Fermat's Little Theorem)
    int inv(ll x) {
        return pwr(x, m - 2);
    }

    //Returns (xy^(-1)) mod m (using the modular inverse)
    int div(ll x, ll y) {
        return ((x % m) * inv(y)) % m;
    }

};

//Creates an instance of the class
modular_arithmetic mod;