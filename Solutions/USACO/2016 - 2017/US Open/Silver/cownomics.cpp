#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m, cov[4][4][4], a[1000][50];

int main(){
    IO("cownomics.in", "cownomics.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < 2 * n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
            if(s[j] == 'A') a[i][j] = 0;
            else if(s[j] == 'T') a[i][j] = 1;
            else if(s[j] == 'C') a[i][j] = 2;
            else a[i][j] = 3;
    }
    int ans = 0;
    for(int i = 0; i < m - 2; i++)
        for(int j = i + 1; j < m - 1; j++)
            for(int k = j + 1; k < m; k++){
                for(int l = 0; l < n; l++)
                    cov[a[l][i]][a[l][j]][a[l][k]] = true;
                bool work = true;
                for(int l = n; l < 2 * n; l++)
                    work &= !cov[a[l][i]][a[l][j]][a[l][k]];
                for(int l = 0; l < n; l++)
                    cov[a[l][i]][a[l][j]][a[l][k]] = false;
                ans += work;
            }
    cout << ans << '\n';
    return 0;
}