#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, r[1000];

int main(){
    IO("cbarn.in", "cbarn.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++)
        cin >> r[i], sum += r[i];
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int cnt = sum, res = 0;
        cnt -= r[i];
        for(int j = (i + 1) % n; j != i; j = (j + 1) % n)
            res += cnt, cnt -= r[j];
        ans = min(ans, res);
    }
    cout << ans << '\n';
    return 0;
}