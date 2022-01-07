#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m, q;

int main(){
    IO("cowsignal.in", "cowsignal.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < q; j++){
            for(int k = 0; k < m; k++)
                for(int l = 0; l < q; l++) cout << s[k];
            cout << '\n';
        }
    }
    return 0;
}