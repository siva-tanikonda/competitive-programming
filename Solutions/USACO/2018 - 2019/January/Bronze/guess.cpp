#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
vector<string> a[100];

int main(){
    IO("guess.in", "guess.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        int k;
        string s;
        cin >> s >> k, a[i].resize(k);
        for(int j = 0; j < k; j++) cin >> a[i][j];
    }
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        set<string> cov;
        for(string j : a[i]) cov.insert(j);
        for(int j = i + 1; j < n; j++){
            int cnt = 0;
            for(string k : a[j])
                cnt += (cov.find(k) != cov.end());
            ans = max(ans, cnt + 1);
        }
    }
    cout << ans << '\n';
    return 0;
}