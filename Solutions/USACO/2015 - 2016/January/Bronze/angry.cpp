#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, x[100];

int main(){
    IO("angry.in", "angry.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        vector<int> bombs(1, x[i]);
        vector<bool> vis(n, false);
        int cnt = 1;
        vis[i] = true;
        for(int j = 1; j <= 100; j++){
            vector<int> nxt;
            for(int k : bombs)
                for(int l = 0; l < n; l++)
                    if(!vis[l] && x[l] >= k - j && x[l] <= k + j)
                        cnt++, nxt.push_back(x[l]), vis[l] = true;
            bombs = nxt;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}