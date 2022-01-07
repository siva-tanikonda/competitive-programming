#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

const int mod = 1e9 + 9;
int n, m, c, a[1001], b[1001], dp[11][1001][1001], p[1001][1001];

int main(){
    IO("team.in", "team.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    sort(a, a + n + 1), sort(b, b + m + 1);
    dp[0][0][0] = 1;
    for(int i = 1; i <= c; i++){
        p[0][0] = dp[i - 1][0][0];
        for(int j = 0; j <= n; j++)
            for(int k = 0; k <= m; k++){
                if(!j && !k) p[j][k] = dp[i - 1][j][k];
                else if(!j) p[j][k] = p[j][k - 1];
                else if(!k) p[j][k] = p[j - 1][k];
                else{
                    int bef = (((p[j - 1][k] + p[j][k - 1]) % mod - p[j - 1][k - 1]) % mod + mod) % mod;
                    p[j][k] = (bef + dp[i - 1][j][k]) % mod;
                }
            }
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= m; k++)
                if(a[j] > b[k]) dp[i][j][k] = p[j - 1][k - 1];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            ans = (ans + dp[c][i][j]) % mod;
    cout << ans << '\n';
    return 0;
}