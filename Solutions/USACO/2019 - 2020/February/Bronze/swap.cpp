#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, k, l1, r1, l2, r2, fir[101], nxt[10001][101];

int main(){
    IO("swap.in", "swap.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> l1 >> r1 >> l2 >> r2;
    for(int i = 1; i <= n; i++) fir[i] = i;
    reverse(fir + l1, fir + r1 + 1);
    reverse(fir + l2, fir + r2 + 1);
    for(int i = 1; i <= n; i++) nxt[1][i] = fir[i];
    for(int i = 2; i <= 1e4; i++)
        for(int j = 1; j <= n; j++)
            nxt[i][j] = nxt[i - 1][nxt[1][j]];
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++) ans[i] = i;
    for(int i = 1; i <= k; i += 1e4)
        for(int j = 1; j <= n; j++)
            ans[j] = nxt[min(10000, k - i + 1)][ans[j]];
    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}