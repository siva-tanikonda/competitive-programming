#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m, a[101];

int main(){
    IO("speeding.in", "speeding.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        for(int j = sum + 1; j <= sum + x; j++) a[j] = y;
        sum += x;
    }
    sum = 0;
    int ans = 0;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        for(int j = sum + 1; j <= sum + x; j++)
            ans = max(ans, y - a[j]);
        sum += x;
    }
    cout << ans << '\n';
    return 0;
}