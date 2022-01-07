#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, a[101];

int main(){
    IO("shuffle.in", "shuffle.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int val;
        cin >> val;
        a[val] = i;
    }
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++) cin >> ans[i];
    for(int i = 0; i < 3; i++){
        vector<int> nxt(n + 1);
        for(int j = 1; j <= n; j++)
            nxt[a[j]] = ans[j];
        ans = nxt;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}