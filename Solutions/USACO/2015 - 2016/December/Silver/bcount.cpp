#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, q, a[100001][4];

int main(){
    IO("bcount.in", "bcount.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int val;
        cin >> val;
        a[i][val]++;
        for(int j = 1; j <= 3; j++)
            a[i][j] += a[i - 1][j];
    }
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        for(int j = 1; j <= 3; j++)
            cout << a[r][j] - a[l - 1][j] << " \n"[j == 3];
    }
    return 0;
}