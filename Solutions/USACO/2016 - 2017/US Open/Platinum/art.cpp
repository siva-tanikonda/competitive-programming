#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, a[1001][1001], pre[1002][1002];
tuple<int, int, int, int> rect[1000001];
bool fail[1000001];

int main(){
    IO("art.in", "art.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n * n; i++)
        rect[i] = make_tuple(INT_MAX, -1, INT_MAX, -1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(!a[i][j]) continue;
            int l, r, b, t;
            tie(l, r, b, t) = rect[a[i][j]];
            l = min(l, i), r = max(r, i);
            b = min(b, j), t = max(t, j);
            rect[a[i][j]] = make_tuple(l, r, b, t);
        }
    int col = 0;
    for(int i = 1; i <= n * n; i++){
        int l, r, b, t;
        tie(l, r, b, t) = rect[i];
        if(l == INT_MAX) continue;
        col++;
        pre[l][b]++, pre[r + 1][t + 1]++;
        pre[l][t + 1]--, pre[r + 1][b]--;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            if(pre[i][j] > 1) fail[a[i][j]] = true;
        }
    int ans = n * n;
    for(int i = 1; i <= n * n; i++) ans -= fail[i];
    ans -= (col == 1);
    cout << ans << '\n';
    return 0;
}