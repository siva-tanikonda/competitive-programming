#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, a[100][3];

int main(){
    IO("shell.in", "shell.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    int ans = 0;
    for(int i = 1; i <= 3; i++){
        vector<bool> arr(4, 0);
        arr[i] = 1;
        int cnt = 0;
        for(int j = 0; j < n; j++){
            swap(arr[a[j][0]], arr[a[j][1]]);
            cnt += arr[a[j][2]];
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}