#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using ll = long long;

int n;

int main(){
    IO("citystate.in", "citystate.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    map<string, map<string, int>> cov;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        string sub = a.substr(0, 2);
        if(sub != b && cov.find(sub) != cov.end()) ans += cov[sub][b];
        cov[b][sub]++;
    }
    cout << ans << '\n';
    return 0;
}