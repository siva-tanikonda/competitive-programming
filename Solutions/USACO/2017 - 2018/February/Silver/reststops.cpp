#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using ll = long long;

int n;
ll l, j, b, x[100000], c[100000];

int main(){
    IO("reststops.in", "reststops.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> n >> j >> b;
    multiset<ll, greater<ll>> que;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> c[i];
        que.insert(c[i]);
    }
    ll pj = 0, pb = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(*que.begin() == c[i]){
            ll req = b * x[i] - pb;
            pj += req, pb += req;
            ll lim = j * x[i] - pj;
            pj += lim, ans += lim * c[i];
        }
        que.erase(que.find(c[i]));
    }
    cout << ans << '\n';
    return 0;
}