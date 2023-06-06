/*
BINARY EXPONENTIATION
Purpose: This quickly calculates exponents
Time Complexity: O(log(n))
Space Complexity: O(1)
*/

ll binary_exponentiation(ll a, ll b){
    if(!b) return 1;
    ll res = binary_exponentiation(a, b / 2);
    res = res * res;
    if(b % 2) res = res * a;
    return res;
}