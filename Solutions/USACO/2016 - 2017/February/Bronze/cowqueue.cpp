#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
pair<int, int> a[100];

int main(){
    IO("cowqueue.in", "cowqueue.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, a[i].first) + a[i].second;
    cout << ans << '\n';
    return 0;
}