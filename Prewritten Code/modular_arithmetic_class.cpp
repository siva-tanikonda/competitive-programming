/*
MODULAR ARITHMETIC CLASS
Purpose: This is just a class that supports modular arithmetic operations (only with a prime modulus)
*/

struct modular_arithmetic {
    const int mod = 1e9 + 7; //const int mod = 998244353;
    int add(ll x, ll y) {
        return ((x % mod + mod) % mod + (y % mod + mod) % mod) % mod;
    }
    int sub(ll x, ll y) {
        return (((x % mod + mod) % mod - (y % mod + mod) % mod) % mod + mod) % mod;
    }
    int mult(ll x, ll y) {
        return (((x % mod + mod) % mod) * ((y % mod + mod) % mod)) % mod;
    }
    int pwr(ll x, ll y) {
        if (!y) return 1 % mod;
        ll ans = pwr(x, y / 2);
        ans = (ans * ans) % mod;
        if (y % 2) ans = (ans * (x % mod)) % mod;
        return ans;
    }
    int inv(ll x) {
        return pwr(x, mod - 2);
    }
    int div(ll x, ll y) {
        return ((x % mod) * inv(y)) % mod;
    }
};
modular_arithmetic mod;