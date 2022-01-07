#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, l[100], r[100];
bool cov[1001];

int main(){
    IO("lifeguards.in", "lifeguards.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++)
            if(i != j)
                for(int k = l[j] + 1; k <= r[j]; k++)
                    cnt += !cov[k], cov[k] = true;
        ans = max(ans, cnt);
        fill(cov, cov + 1001, false);
    }
    cout << ans << '\n';
    return 0;
}