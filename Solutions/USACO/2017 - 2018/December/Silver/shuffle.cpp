#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
bool vis[100001];
vector<int> a;

int main(){
    IO("shuffle.in", "shuffle.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < 32; i++){
        vector<int> nxt = a;
        for(int j = 1; j <= n; j++) nxt[j] = a[nxt[j]];
        a = nxt;
    }
    for(int i = 1; i <= n; i++) vis[a[i]] = true;
    cout << accumulate(vis + 1, vis + n + 1, 0) << '\n';
    return 0;
}