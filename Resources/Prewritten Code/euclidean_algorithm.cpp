/*
EUCLIDEAN ALGORITHM
Purpose: It finds the greatest-common-factor of two numbers
Time Complexity: O(lg(n))
Space Complexity: O(1)
*/

ll gcd(ll a, ll b){
    if(!b) return a;
    else return gcd(b, a % b);
}