#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, w[100000];

int main(){
    IO("lemonade.in", "lemonade.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> w[i];
    sort(w, w + n, greater<int>());
    int cnt = 0, ans = 0;
    for(int i = 0; i < n; i++)
        ans += (cnt++ <= w[i]);
    cout << ans << '\n';
    return 0;
}