#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, a[50000];

int main(){
    IO("highcard.in", "highcard.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    set<int> ops;
    for(int i = 1; i <= 2 * n; i++) ops.insert(i);
    for(int i = 0; i < n; i++)
        cin >> a[i], ops.erase(a[i]);
    int ans = 0;
    for(int i = 0; i < n; i++){
        auto it = ops.upper_bound(a[i]);
        if(it == ops.end()) continue;
        ans++, ops.erase(it);
    }
    cout << ans << '\n';
    return 0;
}