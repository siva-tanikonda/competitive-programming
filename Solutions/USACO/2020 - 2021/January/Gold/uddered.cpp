#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[20][20], dp[1 << 20];
map<char, int> con;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int n = s.length();
    int idx = 0;
    for(int i = 0; i < n; i++){
        if(con.find(s[i]) == con.end())
            con[s[i]] = idx, s[i] = idx++;
        else s[i] = con[s[i]];
        if(i) cnt[(int)s[i - 1]][(int)s[i]]++;
    }
    fill(dp, dp + (1 << idx), INT_MAX);
    dp[0] = 1;
    for(int i = 1; i < (1 << idx); i++)
        for(int j = 0; j < idx; j++)
            if(i & (1 << j)){
                int op = dp[i ^ (1 << j)];
                for(int k = 0; k < idx; k++)
                    if(i & (1 << k)) op += cnt[j][k]; 
                dp[i] = min(dp[i], op);
            }
    cout << dp[(1 << idx) - 1] << '\n';
    return 0;
}