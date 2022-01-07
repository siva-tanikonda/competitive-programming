#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m, x[100], y[100];

int main(){
    IO("balancing.in", "balancing.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            int p = x[i] + 1, q = y[j] + 1;
            int one = 0, two = 0, three = 0, four = 0;
            for(int k = 0; k < n; k++)
                if(x[k] < p && y[k] < q) one++;
                else if(x[k] < p && y[k] > q) two++;
                else if(x[k] > p && y[k] < q) three++;
                else four++;
            ans = min(ans, max(max(one, two), max(three, four)));
        }
    cout << ans << '\n';
    return 0;
}