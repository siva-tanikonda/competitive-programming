#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct modular_arithmetic{
    const int mod = 1e9 + 7;
    int add(int a, int b) { return (a + b) % mod; }
    int mult(int a, int b) { return ((ll)a * b) % mod; }
};

modular_arithmetic mod;
int n, x[40], y[40], dp[41][40][40][40];
vector<int> in[40][40][40];

int cross(int i, int j, int k){
    pair<int, int> l1(x[j] - x[i], y[j] - y[i]);
    pair<int, int> l2(x[k] - x[j], y[k] - y[j]);
    return l1.first * l2.second - l2.first * l1.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++){
                dp[3][i][j][k] = 6;
                for(int l = 0; l < n; l++){
                    if(i == l || j == l || k == l || i == j || i == k || j == k) continue;
                    int c1 = cross(i, j, l);
                    int c2 = cross(j, k, l);
                    int c3 = cross(k, i, l);
                    bool pos = (c1 > 0 || c2 > 0 || c3 > 0);
                    bool neg = (c1 < 0 || c2 < 0 || c3 < 0);
                    if(!(pos && neg)) in[i][j][k].push_back(l);
                }
            }
    int ans = 0;
    for(int r = 4; r <= n; r++)
        for(int i = 0; i < n - 2; i++)
            for(int j = i + 1; j < n - 1; j++)
                for(int k = j + 1; k < n; k++){
                    if((int)in[i][j][k].size() < r - 3) continue;
                    int other = in[i][j][k].size() - (r - 4);
                    dp[r][i][j][k] = mod.add(dp[r][i][j][k], mod.mult(dp[r - 1][i][j][k], other));
                    for(int l : in[i][j][k]){
                        vector<vector<int>> ops = {{i, j, l}, {i, k, l}, {j, k, l}};
                        for(auto &m : ops){
                            sort(m.begin(), m.end());
                            dp[r][i][j][k] = mod.add(dp[r][i][j][k], dp[r - 1][m[0]][m[1]][m[2]]);
                        }
                    }
                    if(r == n) ans = dp[r][i][j][k];
                }
    cout << ans << '\n';
    return 0;
}