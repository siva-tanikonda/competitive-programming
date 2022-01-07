#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int a, b, c, d;
bool cov[101];

int main(){
    IO("paint.in", "paint.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c >> d;
    int ans = 0;
    for(int i = a; i < b; i++)
        cov[i] = true, ans++;
    for(int i = c; i < d; i++) ans += (!cov[i]);
    cout << ans << '\n';
    return 0;
}