#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int x[2], y[2];
bool cov[2000][2000];

int main(){
    IO("billboard.in", "billboard.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    for(int i = 0; i < 3; i++){
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        for(int j = x[0]; j < x[1]; j++)
            for(int k = y[0]; k < y[1]; k++)
                if(i < 2) cov[j + 1000][k + 1000] = true, ans++;
                else ans -= cov[j + 1000][k + 1000];
    }
    cout << ans << '\n';
    return 0;
}