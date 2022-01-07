#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m, a[10][20];

int main(){
    IO("gymnastics.in", "gymnastics.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> a[i][j];
    int ans = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++){
            if(i == j) continue;
            bool work = true;
            for(int k = 0; k < n; k++)
                for(int x = 0; x < m - 1; x++)
                    for(int y = x + 1; y < m; y++)
                        if(a[k][y] == i && a[k][x] == j) work = false;
            ans += work;
        }
    cout << ans << '\n';
    return 0;
}