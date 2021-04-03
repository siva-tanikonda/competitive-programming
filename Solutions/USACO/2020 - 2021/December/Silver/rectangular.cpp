#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, pre[2501][2501];
pair<int, int> a[2500];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    set<int> sx, sy;
    for(int i = 0; i < n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        a[i].first = i + 1;
        swap(a[i].first, a[i].second);
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        a[i].first = i + 1;
        pre[a[i].first][a[i].second]++;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    ll ans = 1 + n;
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++){
            int l = a[j].first, r = a[i].first;
            int b = min(a[i].second, a[j].second);
            int t = max(a[i].second, a[j].second);
            int p1 = pre[r][n] - pre[l - 1][n] - pre[r][t - 1] + pre[l - 1][t - 1];
            int p2 = pre[r][b] - pre[l - 1][b];
            ans += p1 * p2;
        }
    cout << ans << '\n';
    return 0;
}