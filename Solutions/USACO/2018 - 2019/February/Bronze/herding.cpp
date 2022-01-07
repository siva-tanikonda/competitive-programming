#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int a, b, c;

int main(){
    IO("herding.in", "herding.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    if(b - a == 1 && c - b == 1){
        cout << "0\n0\n";
        return 0;
    }
    if(b - a == 2 || c - b == 2) cout << "1\n";
    else cout << "2\n";
    cout << max(c - b - 1, b - a - 1) << '\n';
    return 0;
}