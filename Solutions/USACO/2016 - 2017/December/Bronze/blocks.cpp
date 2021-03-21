#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, ans[26];

int main(){
    IO("blocks.in", "blocks.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        vector<int> x(26), y(26);
        for(char j : a) x[j - 'a']++;
        for(char j : b) y[j - 'a']++;
        for(int j = 0; j < 26; j++)
            ans[j] += max(x[j], y[j]);
    }
    for(int i = 0; i < 26; i++) cout << ans[i] << '\n';
    return 0;
}