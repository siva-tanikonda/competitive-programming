/*
GOOGLE CODE JAM TEMPLATE
Purpose: This is just my template for the Google Code Jam
*/

#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
const int xx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int yy[8] = {0, -1, 0, 1, -1, 1, -1, 1};

void solve(){

}

int main(){
    //IO("input.txt", "output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), srand(time(NULL));
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}