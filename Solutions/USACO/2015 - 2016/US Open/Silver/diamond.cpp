#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m, a[50000], sz[50001], mx[50001];

int main(){
    IO("diamond.in", "diamond.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j < n && a[j] - a[i] <= m) j++;
        sz[i] = j - i;
    }
    for(int i = n - 1; i >= 0; i--)
        mx[i] = max(mx[i + 1], sz[i]);
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(i + sz[i] < n)
            ans = max(ans, sz[i] + mx[i + sz[i]]);
    cout << ans << '\n';
    return 0;
}