/*
GOOGLE CODE JAM TEMPLATE
Purpose: This is just a template for Google Code Jam problems
*/

#pragma GCC optimize("unroll-loops, O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int xx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
const int yy[8] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const ld pi = atan(1) * 4;

void solve() {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), srand(time(NULL));
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

//RIP :(