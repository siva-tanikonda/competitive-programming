#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m;
bool adj[100][100];

int main(){
    IO("revegetate.in", "revegetate.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u - 1][v - 1] = adj[v - 1][u - 1] = true;
    }
    string ans(n, ' ');
    for(int i = 0; i < n; i++)
        for(int j = 1; j <= 4; j++){
            bool work = true;
            for(int k = 0; k < i; k++)
                work &= (ans[k] - '0' != j || !adj[i][k]);
            if(work){
                ans[i] = j + '0';
                break;
            }
        }
    cout << ans << '\n';
    return 0;
}