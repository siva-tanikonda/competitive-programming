#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

string s;
int l[26], r[26];

int main(){
    IO("circlecross.in", "circlecross.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s, s = ' ' + s;
    for(int i = 1; i <= 52; i++)
        if(!l[s[i] - 'A']) l[s[i] - 'A'] = i;
        else r[s[i] - 'A'] = i;
    int ans = 0;
    for(int i = 0; i < 25; i++)
        for(int j = i + 1; j < 26; j++)
            if(l[i] < l[j]) ans += (r[i] > l[j] && r[i] < r[j]);
            else ans += (r[j] > l[i] && r[j] < r[i]);
    cout << ans << '\n';
    return 0;
}