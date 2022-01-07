#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m;
string a[200];

int main(){
    IO("cownomics.in", "cownomics.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < 2 * n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 0; i < m; i++){
        set<char> use;
        bool work = true;
        for(int j = 0; j < n; j++) use.insert(a[j][i]);
        for(int j = n; j < 2 * n; j++)
            work &= (use.find(a[j][i]) == use.end());
        ans += work;
    }
    cout << ans << '\n';
    return 0;
}