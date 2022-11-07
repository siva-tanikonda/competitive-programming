/*
SIEVE OF ERATOSTHENES
Purpose: This finds all the primes under a certain number
Time Complexity: O(nlg(lg(n)))
Space Complexity: O(n)
*/

struct sieve_of_eratosthenes{
    vector<bool> arr;
    void init(int n){
        arr.resize(n + 1, true);
        arr[0] = arr[1] = false;
        for(int i = 2; i <= n; i++)
            if(arr[i] && (ll)i * i <= n)
                for(int j = i * i; j <= n; j += i) arr[j] = false;
    }
    bool query(int x){ return arr[x]; }
};