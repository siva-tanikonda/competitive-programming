#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;

int main(){
    IO("mowing.in", "mowing.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    map<pair<int, int>, vector<int>> cov;
    int x = 0, y = 0, t = 0;
    cov[make_pair(0, 0)].push_back(0);
    for(int i = 0; i < n; i++){
        char d;
        int s;
        cin >> d >> s;
        int dx = 0, dy = 0;
        if(d == 'N') dx--;
        else if(d == 'S') dx++;
        else if(d == 'W') dy--;
        else dy++;
        for(int j = 0; j < s; j++){
            x += dx, y += dy;
            cov[make_pair(x, y)].push_back(++t);
        }
    }
    int ans = INT_MAX;
    for(auto &i : cov)
        for(int j = 1; j < (int)i.second.size(); j++)
            ans = min(ans, i.second[j] - i.second[j - 1]);
    cout << ((ans == INT_MAX) ? -1 : ans) << '\n';
    return 0;
}