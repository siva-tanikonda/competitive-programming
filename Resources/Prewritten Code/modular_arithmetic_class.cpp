/*
MODULAR ARITHMETIC CLASS
Purpose: This is just a class that supports modular arithmetic operations
*/

struct modular_arithmetic{
    const int mod = 1e9 + 7;
    const bool prime = true;
    tuple<int, int, int> gcd(int a, int b){
        if(b == 0) return make_tuple(1, 0, a);
        else{
            int x, y, z;
            tie(x, y, z) = gcd(b, a % b);
            return make_tuple(y, x - (a / b) * y, z);
        }
    }
    int pow(int a, int b){
        if(!b) return 1 % mod;
        int ret = pow(a, b / 2);
        ret = ((ll)ret * ret) % mod;
        if(b % 2) ret = ((ll)ret * a) % mod;
        return ret;
    }
    int powpow(int a, ll b){
        if(!prime) return -1;
        return pow(a, b % (mod - 1));
    }
    int add(int a, int b){ return (a + b) % mod; }
    int sub(int a, int b) { return ((a - b) % mod + mod) % mod; }
    int mult(int a, int b) { return ((ll)a * b) % mod; }
    int div(int a, int b) {
        if(prime) return ((ll)a * pow(b, mod - 2)) % mod;
        else{
            tuple<int, int, int> res = gcd(b, mod);
            if(get<2>(res) != 1) return -1;
            else{
                int inv = (get<0>(res) % mod + mod) % mod;
                return ((ll)a * inv) % mod;
            }
        }
    }
};