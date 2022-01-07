#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, q, a[100001];

int main(){
    IO("haybales.in", "haybales.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    a[0] = -1;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a, a + n + 1);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        auto it1 = upper_bound(a, a + n + 1, r) - 1;
        auto it2 = lower_bound(a, a + n + 1, l) - 1;
        cout << (it1 - it2) << '\n';
    }
    return 0;
}