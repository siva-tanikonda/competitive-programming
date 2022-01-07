#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int x[2], y[2];
bool cov[2000][2000];

int main(){
    IO("billboard.in", "billboard.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int k = 0; k < 2; k++){
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        for(int i = x[0]; i < x[1]; i++)
            for(int j = y[0]; j < y[1]; j++)
                if(!k) cov[i + 1000][j + 1000] = true;
                else cov[i + 1000][j + 1000] = false; 
    }
    int lx = INT_MAX, ly = INT_MAX, ux = 0, uy = 0;
    for(int i = 0; i < 2000; i++)
        for(int j = 0; j < 2000; j++)
            if(cov[i][j]){
                lx = min(lx, i), ly = min(ly, j);
                ux = max(ux, i), uy = max(uy, j);
            }
    if(lx == INT_MAX) cout << "0\n";
    else cout << (ux - lx + 1) * (uy - ly + 1) << '\n';
    return 0;
}