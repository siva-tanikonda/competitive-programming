/*
MODULAR ARITHMETIC CLASS
Purpose: This is just a class that supports modular arithmetic operations
*/

struct modular_arithmetic{
    const int mod = 1e9 + 7;//const int mod = 998244353;
    const bool prime = true;
    tuple<ll, ll, ll> gcd(ll a, ll b){
        if(b == 0) return make_tuple(1, 0, a);
        else{
            ll x, y, z;
            tie(x, y, z) = gcd(b, a % b);
            return make_tuple(y, x - (a / b) * y, z);
        }
    }
    int pow(ll a, ll b){
        if(!b) return 1 % mod;
        ll ret = pow(a, b / 2);
        ret = (ret * ret) % mod;
        if(b % 2) ret = (ret * a) % mod;
        return ret;
    }
    int powpow(ll a, ll b){
        if(!prime) return -1;
        return pow(a, b % (mod - 1));
    }
    int inv(ll num){
        if(prime) return pow(num, mod - 2);
        else{
            tuple<ll, ll, ll> res = gcd(num, mod);
            if(get<2>(res) != 1) return -1;
            else{
                ll inv = (get<0>(res) % mod + mod) % mod;
                return inv % mod;
            }
        }
    }
    int add(ll a, ll b){ return (a + b) % mod; }
    int sub(ll a, ll b) { return ((a - b) % mod + mod) % mod; }
    int mult(ll a, ll b) { return (a * b) % mod; }
    int div(ll a, ll b) {
        int res = inv(b);
        if(res == -1) return -1;
        return (a * res) % mod;
    }
};
modular_arithmetic mod;