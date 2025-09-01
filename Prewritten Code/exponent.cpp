/*
BINARY EXPONENTIATION
Purpose: This quickly calculates exponents
Time Complexity: O(log(N))
Space Complexity: O(log(N))
*/

template <class T> T exponent(T x, T n){
    if(!n) return 1;
    T res = exponent(x, n / 2);
    res = res * res;
    if(n % 2) res = res * x;
    return res;
}
