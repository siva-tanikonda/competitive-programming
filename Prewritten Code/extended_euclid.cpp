/*
EXTENDED GCD
Purpose: This gives a single solution to an equation of the form: ax + by = gcd(a, b)
Time Complexity: O(log(N))
Space Complexity: O(1)
*/

template <class T> tuple<T, T, T> extended_gcd(T a, T b){
    if(b == 0) return make_tuple(1, 0, a);
    T x, y, g;
    tie(x, y, g) = extended_gcd(b, a % b);
    return make_tuple(y, x - (a / b) * y, g);
}
