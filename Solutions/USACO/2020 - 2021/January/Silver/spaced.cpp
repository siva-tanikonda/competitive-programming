#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;

int solve(){
    int res = 0;
    for(int i = 0; i < n; i++){
        int cnt[2] = {0, 0};
        for(int j = 0; j < n; j++) cnt[j % 2] += a[i][j];
        res += max(cnt[0], cnt[1]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> a[i][j];
    int ans = solve();
    vector<vector<int>> rot = a;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) rot[j][i] = a[i][j];
    a = rot;
    ans = max(ans, solve());
    cout << ans << '\n';
    return 0;
}