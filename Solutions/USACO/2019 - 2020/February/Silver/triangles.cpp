#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using ll = long long;

struct modular_arithmetic{
    const int mod = 1e9 + 7;
    int add(int a, int b){ return (a + b) % mod; }
    int sub(int a, int b){ return ((a - b) % mod + mod) % mod; }
    int mult(int a, int b){ return ((ll)a * b) % mod; }
};

modular_arithmetic mod;
int n, side[100000];
vector<pair<int, int>> v[20001], h[20001];

int main(){
    IO("triangles.in", "triangles.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), srand(time(NULL));
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x += 1e4, y += 1e4;
        v[x].emplace_back(y, i);
        h[y].emplace_back(x, i);
    }
    for(int i = 0; i < 2e4; i++){
        sort(v[i].begin(), v[i].end());
        int sum = 0;
        for(int j = 0; j < (int)v[i].size(); j++){
            int add = mod.sub(mod.mult(v[i][j].first, j), sum);
            side[v[i][j].second] = mod.add(side[v[i][j].second], add);
            sum = mod.add(sum, v[i][j].first);
        }
        sum = 0;
        for(int j = v[i].size() - 1; j >= 0; j--){
            int add = mod.sub(sum, mod.mult(v[i][j].first, v[i].size() - 1 - j));
            side[v[i][j].second] = mod.add(side[v[i][j].second], add);
            sum = mod.add(sum, v[i][j].first);
        }
    }
    int ans = 0;
    for(int i = 0; i < 2e4; i++){
        sort(h[i].begin(), h[i].end());
        int sum1 = 0, sum2 = 0;
        for(int j = 0; j < (int)h[i].size(); j++){
            ans = mod.add(ans, mod.sub(mod.mult(h[i][j].first, sum1), sum2));
            sum1 = mod.add(sum1, side[h[i][j].second]);
            sum2 = mod.add(sum2, mod.mult(side[h[i][j].second], h[i][j].first));
        }
        sum1 = 0, sum2 = 0;
        for(int j = h[i].size() - 1; j >= 0; j--){
            ans = mod.add(ans, mod.sub(sum2, mod.mult(h[i][j].first, sum1)));
            sum1 = mod.add(sum1, side[h[i][j].second]);
            sum2 = mod.add(sum2, mod.mult(side[h[i][j].second], h[i][j].first));
        }
    }
    cout << ans << '\n';
    return 0;
}