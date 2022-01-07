#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int x, y, m;

int main(){
    IO("pails.in", "pails.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y >> m;
    int ans = 0;
    for(int i = 0; i <= m; i++){
        int sum = x * i;
        if(sum > m) continue;
        for(int j = 0; j <= m; j++)
            if(sum + y * j <= m) ans = max(ans, sum + y * j);
    }
    cout << ans << '\n';
    return 0;
}