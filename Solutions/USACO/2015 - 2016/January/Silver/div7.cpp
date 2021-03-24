#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, mn[7];

int main(){
    IO("div7.in", "div7.out");
    cin >> n;
    fill(mn, mn + 7, -1);
    mn[0] = 0;
    int val = 0, sum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        cin >> val;
        sum = (sum + val) % 7;
        if(mn[sum] == -1) mn[sum] = i;
        else ans = max(ans, i - mn[sum]);
    }
    cout << ans << '\n';
}