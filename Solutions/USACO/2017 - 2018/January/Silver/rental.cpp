#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using ll = long long;

int n, m, k;
ll r[100001], c[100001], x[100001], b[100001];
pair<ll, ll> a[100001];

ll sell(ll mx){
    if(mx == 0) return 0;
    auto it = lower_bound(x + 1, x + m + 1, mx);
    if(it == x + m + 1) return b[m];
    int pos = it - x;
    ll rem = mx - x[pos - 1];
    assert(rem > 0);
    return b[pos - 1] + rem * a[pos].second;
}

int main(){
    IO("rental.in", "rental.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= m; i++)
        cin >> a[i].second >> a[i].first;
    for(int i = 1; i <= k; i++) cin >> r[i];
    sort(c, c + n + 1);
    sort(a + 1, a + m + 1, greater<pair<ll, ll>>());
    sort(r + 1, r + k + 1, greater<ll>());
    for(int i = 1; i <= m; i++){
        swap(a[i].first, a[i].second);
        b[i] = b[i - 1] + a[i].first * a[i].second;
        x[i] = x[i - 1] + a[i].first;
    }
    ll rent = 0, avail = 0, ans = 0;
    for(int i = 1; i <= n; i++) avail += c[i];
    ans = sell(avail);
    for(int i = 1; i <= min(n, k); i++){
        rent += r[i], avail -= c[i];
        ans = max(ans, rent + sell(avail));
    }
    cout << ans << '\n';
    return 0;
}