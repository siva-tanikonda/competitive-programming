#include <bits/stdc++.h>
using namespace std;

int n, m, b[50001], dp[51][50001];
string s[50];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> b[i], b[i]--;
    for(int i = 0; i < m; i++) cin >> s[i];
    for(int j = 1; j <= n; j++)
        for(int i = 0; i < m; i++) dp[i][j] = -1;
    for(int i = 0; i <= m; i++){
        if(!i) dp[i][1] = 0;
        else{
            vector<int> l(m), r(m);
            for(int j = 0; j < m; j++)
                l[j] = INT_MIN, r[j] = INT_MAX;
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i - 1][j];
                if(dp[i - 1][j] != -1)
                    l[b[j]] = max(l[b[j]], j - dp[i - 1][j]);
                for(int k = 0; k < m; k++)
                    if(s[k][b[j]] == '1'){
                        int x = l[k];
                        if(x != INT_MIN && (dp[i][j] == -1 || dp[i][j] > j - x))
                            dp[i][j] = j - x;
                    }
            }
            for(int j = n; j >= 1; j--){
                if(dp[i - 1][j] != -1)
                    r[b[j]] = min(r[b[j]], j + dp[i - 1][j]);
                for(int k = 0; k < m; k++)
                    if(s[k][b[j]] == '1'){
                        int x = r[k];
                        if(x != INT_MAX && (dp[i][j] == -1 || dp[i][j] > x - j))
                            dp[i][j] = x - j;
                    }
            }
        }
    }
    cout << dp[m][n] << '\n';
    return 0;
}