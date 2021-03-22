#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, x[1000], y[1000];

int main(){
    IO("balancing.in", "balancing.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int v = y[i] + 1, q1 = 0, q2 = 0, q3 = 0, q4 = 0;
        map<int, vector<int>> add;
        for(int j = 0; j < n; j++){
            add[x[j]].push_back(y[j]);
            if(y[j] > v) q1++;
            else q4++;
        }
        ans = min(ans, max(max(q1, q2), max(q3, q4)));
        for(auto &j : add){
            for(int k : j.second)
                if(k > v) q1--, q2++;
                else q4--, q3++;
            ans = min(ans, max(max(q1, q2), max(q3, q4)));
        }
    }
    cout << ans << '\n';
    return 0;
}