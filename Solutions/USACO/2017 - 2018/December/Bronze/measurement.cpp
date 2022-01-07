#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
pair<string, int> a[101];

int main(){
    IO("measurement.in", "measurement.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, z;
        string y;
        cin >> x >> y >> z;
        a[x] = make_pair(y, z);
    }
    vector<int> rec, cur(3, 7);
    for(int i = 0; i < 3; i++) cur.push_back(i);
    int ans = 0;
    for(int i = 1; i <= 100; i++){
        if(a[i].first.empty()) continue;
        if(a[i].first == "Bessie") cur[0] += a[i].second;
        else if(a[i].first == "Elsie") cur[1] += a[i].second;
        else cur[2] += a[i].second;
        int mx = 0;
        for(int j : cur) mx = max(mx, j);
        vector<int> nxt;
        for(int j = 0; j < 3; j++)
            if(cur[j] == mx) nxt.push_back(j);
        ans += (rec != nxt);
        rec = nxt;  
    }
    cout << ans << '\n';
    return 0;
}