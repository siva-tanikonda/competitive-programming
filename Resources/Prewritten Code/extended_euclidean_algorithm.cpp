/*
EXTENDED EUCLIDEAN ALGORITHM
Purpose: This can solve an equation in the form of ax + by = gcd(a, b)
Time Complexity: O(lg(n))
Space Complexity: O(1)
*/

tuple<ll, ll, ll> extendedGcd(ll a, ll b){
    if(b == 0) return make_tuple(1, 0, a);
    else{
        ll x, y, z;
        tie(x, y, z) = extendedGcd(b, a % b);
        return make_tuple(y, x - (a / b) * y, z);
    }
}