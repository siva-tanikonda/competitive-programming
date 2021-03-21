#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

string s, t;

int main(){
    IO("censor.in", "censor.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    string ans;
    int m = t.length();
    for(char i : s){
        ans += i;
        while((int)ans.length() >= m && ans.substr(ans.length() - m, m) == t)
            for(int j = 0; j < m; j++) ans.pop_back();
    }
    cout << ans << '\n';
    return 0;
}