#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, a[100001][3];

int main(){
    IO("hps.in", "hps.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        char val;
        cin >> val;
        if(val == 'H') a[i][0]++;
        else if(val == 'P') a[i][1]++;
        else a[i][2]++;
        for(int j = 0; j < 3; j++)
            a[i][j] += a[i - 1][j];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int left = max(a[i][0], max(a[i][1], a[i][2]));
        int right = max(a[n][0] - a[i][0], max(a[n][1] - a[i][1], a[n][2] - a[i][2]));
        ans = max(ans, left + right);
    }
    cout << ans << '\n';
    return 0;
}