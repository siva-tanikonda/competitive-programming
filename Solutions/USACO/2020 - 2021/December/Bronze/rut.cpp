#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;

int n, ox[50], oy[50], x[50], y[50], ans[50];
char d[50];
bool done[50];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> pos(1, 0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> d[i] >> x[i] >> y[i];
        ox[i] = x[i], oy[i] = y[i];
        for(int j = 0; j < i; j++){
            pos.push_back(abs(y[j] - y[i]));
            pos.push_back(abs(x[j] - x[i]));
        }
    }
    sort(pos.begin(), pos.end());
    fill(ans, ans + n, INT_MAX);
    for(int k = 1; k < (int)pos.size(); k++){
        int dif = pos[k] - pos[k - 1];
        for(int i = 0; i < n; i++){
            if(d[i] == 'N') y[i] += dif;
            else if(d[i] == 'E') x[i] += dif;
            if(d[i] == 'N' && y[i] - oy[i] == ans[i]) done[i] = true;
            if(d[i] == 'E' && x[i] - ox[i] == ans[i]) done[i] = true;
        }
        for(int i = 0; i < n; i++){
            if(done[i]) continue;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(d[j] == 'N' && y[j] >= y[i]) continue;
                if(d[j] == 'E' && x[j] >= x[i]) continue;
                if(d[j] == 'E' && y[j] == y[i]) ans[j] = min(ans[j], ox[i] - ox[j]);
                if(d[j] == 'N' && x[j] == x[i]) ans[j] = min(ans[j], oy[i] - oy[j]);
            }
        }
    }
    for(int i = 0; i < n; i++)
        if(ans[i] == INT_MAX) cout << "Infinity\n";
        else cout << ans[i] << '\n';
    return 0;
}