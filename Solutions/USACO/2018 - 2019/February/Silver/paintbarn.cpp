#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, k, pre[1001][1001];

int main(){
    IO("paintbarn.in", "paintbarn.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pre[a][b]++, pre[c][d]++;
        pre[a][d]--, pre[c][b]--;
    }
    int ans = 0;
    for(int i = 0; i <= 1e3; i++)
        for(int j = 0; j <= 1e3; j++){
            if(i && j) pre[i][j] -= pre[i - 1][j - 1];
            if(i) pre[i][j] += pre[i - 1][j];
            if(j) pre[i][j] += pre[i][j - 1];
            ans += (pre[i][j] == k);
        }
    cout << ans << '\n';
    return 0;
}