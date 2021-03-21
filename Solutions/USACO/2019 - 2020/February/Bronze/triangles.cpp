#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, x[100], y[100];

int main(){
    IO("triangles.in", "triangles.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    int ans = 0;
    for(int i = 0; i < n - 2; i++)
        for(int j = i + 1; j < n - 1; j++)
            for(int k = j + 1; k < n; k++){
                int w = -1, h = -1;
                if(y[i] == y[j]) w = abs(x[i] - x[j]);
                else if(y[i] == y[k]) w = abs(x[i] - x[k]);
                else if(y[j] == y[k]) w = abs(x[j] - x[k]);
                else continue;
                if(x[i] == x[j]) h = abs(y[i] - y[j]);
                else if(x[i] == x[k]) h = abs(y[i] - y[k]);
                else if(x[j] == x[k]) h = abs(y[j] - y[k]);
                else continue;
                ans = max(ans, w * h);
            }
    cout << ans << '\n';
    return 0;
}