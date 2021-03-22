#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m;
string a[8];
vector<string> b[10];

int ones(int idx, int i, int j, int dx, int dy){
    int res = 0;
    for(int k = 0; k < n; k++){
        res += (b[idx][i][j] == '#');
        i += dx, j += dy;
    }
    return res;
}

int main(){
    IO("bcs.in", "bcs.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++){
        b[i].resize(n);
        for(int j = 0; j < n; j++) cin >> b[i][j];
        while(!ones(i, 0, 0, 1, 0))
            for(int j = 0; j < n; j++) b[i][j].erase(b[i][j].begin());
        while(!ones(i, 0, (int)b[i][0].size() - 1, 1, 0))
            for(int j = 0; j < n; j++) b[i][j].pop_back();
        while(!ones(i, 0, 0, 0, 1)) b[i].erase(b[i].begin());
        while(!ones(i, (int)b[i].size() - 1, 0, 0, 1)) b[i].pop_back();
    }
    for(int i = 0; i < m - 1; i++)
        for(int j = i + 1; j < m; j++)
            for(int k = 0; k <= n - (int)b[i].size(); k++)
                for(int l = 0; l <= n - (int)b[i][0].size(); l++)
                    for(int p = 0; p <= n - (int)b[j].size(); p++)
                        for(int q = 0; q <= n - (int)b[j][0].size(); q++){
                            vector<vector<int>> cnt(n, vector<int>(n));
                            for(int x = 0; x < n; x++)
                                for(int y = 0; y < n; y++) cnt[x][y] = (a[x][y] == '#');
                            for(int x = 0; x < (int)b[i].size(); x++)
                                for(int y = 0; y < (int)b[i][0].size(); y++)
                                    cnt[k + x][l + y] -= (b[i][x][y] == '#');
                            for(int x = 0; x < (int)b[j].size(); x++)
                                for(int y = 0; y < (int)b[j][0].size(); y++)
                                    cnt[p + x][q + y] -= (b[j][x][y] == '#');
                            bool work = true;
                            for(int x = 0; x < n; x++)
                                for(int y = 0; y < n; y++) work &= !cnt[x][y];
                            if(work){
                                cout << (i + 1) << ' ' << (j + 1) << '\n';
                                return 0;
                            }
                        }
    return 0;
}