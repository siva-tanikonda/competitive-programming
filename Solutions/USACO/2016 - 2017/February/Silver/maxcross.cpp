#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, k, b, a[100001];

int main(){
    IO("maxcross.in", "maxcross.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> b;
    for(int i = 0; i < b; i++){
        int pos;
        cin >> pos, a[pos]++;
    }
    for(int i = 1; i <= n; i++) a[i] += a[i - 1];
    int ans = INT_MAX;
    for(int i = k; i <= n; i++)
        ans = min(ans, a[i] - a[i - k]);
    cout << ans << '\n';
    return 0;
}