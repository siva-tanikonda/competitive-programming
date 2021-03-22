#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m, d, s;
bool vis[51];
vector<int> b[101];
vector<pair<int, int>> a[101];

int main(){
    IO("badmilk.in", "badmilk.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> d >> s;
    for(int i = 0; i < d; i++){
        int p, x, t;
        cin >> p >> x >> t;
        a[t].emplace_back(p, x);
    }
    for(int i = 0; i < s; i++){
        int p, t;
        cin >> p >> t;
        b[t].push_back(p);
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        vector<set<int>> st(n + 1);
        bool work = true;
        int cnt = 0;
        for(int j = 1; j <= 100; j++){
            for(int k : b[j]){
                cnt++, work &= (st[k].find(i) != st[k].end());
                st[k].clear();
            }
            for(auto &k : a[j])
                st[k.first].insert(k.second);
        }
        for(int j = 1; j <= n; j++)
            cnt += (st[j].find(i) != st[j].end());
        ans = max(ans, cnt * work);
    }
    cout << ans << '\n';
    return 0;
}