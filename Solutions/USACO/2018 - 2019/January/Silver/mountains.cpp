#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
pair<pair<int, int>, int> a[100000];
set<int> ans;

void solve(){
    set<pair<int, int>> ops;
    for(int i = 0; i < n; i++){
        int x = a[i].first.first, y = a[i].first.second;
        if(!ops.empty()){
            auto it = ops.upper_bound(make_pair(y - x, INT_MAX));
            vector<pair<int, int>> rem;
            for(auto j = ops.begin(); j != it; j++) rem.push_back(*j);
            for(auto &j : rem){
                ops.erase(j);
                if(ans.find(j.second) != ans.end()) ans.erase(j.second);
            }
        }
        ops.insert(make_pair(y - x, a[i].second));
    }
}

int main(){
    IO("mountains.in", "mountains.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    for(int i = 0; i < n; i++) ans.insert(i);
    sort(a, a + n);
    solve();
    for(int i = 0; i < n; i++)
        a[i].first.first = a[n - 1].first.first - a[i].first.first;
    sort(a, a + n);
    solve();
    cout << ans.size() << '\n';
    return 0;
}