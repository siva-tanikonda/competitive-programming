#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, x[100], dir[100];

int main(){
    IO("hoofball.in", "hoofball.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if(n == 1){
        cout << "1\n";
        return 0;
    }
    for(int i = 0; i < n; i++) cin >> x[i];
    sort(x, x + n);
    dir[0] = 1, dir[n - 1] = -1;
    for(int i = 1; i < n - 1; i++)
        dir[i] = (x[i] - x[i - 1] <= x[i + 1] - x[i]) ? -1 : 1;
    int ans = 0;
    for(int i = 0; i < n - 1; i++)
        if(dir[i] == 1 && dir[i + 1] == -1){
            int cnt = 0;
            cnt += (i && dir[i - 1] == 1);
            cnt += (i < n - 2 && dir[i + 2] == -1);
            ans += max(1, cnt);
        }
    cout << ans << '\n';
    return 0;
}