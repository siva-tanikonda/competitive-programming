#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
string a[10];

int main(){
    IO("cowtip.in", "cowtip.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int i = n - 1; i >= 0; i--)
        for(int j = n - 1; j >= 0; j--)
            if(a[i][j] == '1'){
                ans++;
                for(int k = 0; k <= i; k++)
                    for(int l = 0; l <= j; l++)
                        a[k][l] = (a[k][l] == '0') ? '1' : '0';
            }
    cout << ans << '\n';
    return 0;
}