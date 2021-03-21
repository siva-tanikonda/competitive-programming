#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, k, a[1000];

int main(){
    IO("diamond.in", "diamond.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= 1e4; i++){
        int op = 0;
        for(int j = 0; j < n; j++)
            op += (a[j] >= i && a[j] <= i + k);
        ans = max(ans, op);
    }
    cout << ans << '\n';
    return 0;
}