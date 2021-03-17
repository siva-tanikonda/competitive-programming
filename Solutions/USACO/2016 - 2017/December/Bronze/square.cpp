#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int x[2], y[2];

int main(){
    IO("square.in", "square.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int lx = INT_MAX, ux = 0, ly = INT_MAX, uy = 0;
    for(int i = 0; i < 2; i++){
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        lx = min(lx, x[0]);
        ly = min(ly, y[0]);
        ux = max(ux, x[1]);
        uy = max(uy, y[1]);
    }
    int side = max(ux - lx, uy - ly);
    cout << side * side << '\n';
    return 0;
}