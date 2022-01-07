/*
BINARY EXPONENTIATION
Purpose: This quickly calculates exponents
Time Complexity: O(lg(n))
Space Complexity: O(1)
*/

ll binpow(ll a, ll b, ll mod){
    if(!b) return 1 % mod;
    ll res = binpow(a, b / 2);
    res = (res * res) % mod;
    if(b % 2) res = (res * a) % mod;
    return res;
}