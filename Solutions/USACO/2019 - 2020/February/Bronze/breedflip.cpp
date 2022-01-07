#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
string a, b;

int main(){
    IO("breedflip.in", "breedflip.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b;
    int ans = 0, cur = 0;
    for(int i = 0; i < n; i++)
        if(a[i] != b[i]) cur++;
        else if(cur) ans++, cur = 0;
    cout << ans << '\n';
    return 0;
}