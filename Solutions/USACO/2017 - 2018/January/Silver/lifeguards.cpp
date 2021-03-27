#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
pair<int, int> a[100000];

int main(){
    IO("lifeguards.in", "lifeguards.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if(n == 1){
        cout << "0\n";
        return 0;
    }
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    int up = a[0].first, ans = 0;
    for(int i = 0; i < n; i++)
        if(a[i].second > up){
            ans += a[i].second - max(a[i].first, up);
            up = a[i].second;
        }
    for(int i = 0; i < n - 1; i++)
        if(a[i + 1].second < a[i].second){
            cout << ans << '\n';
            return 0;
        }
    int rem = INT_MAX;
    for(int i = 0; i < n; i++){
        int l = a[i].first, r = a[i].second;
        if(i + 1 < n) r = min(r, a[i + 1].first);
        if(i - 1 >= 0) l = max(l, a[i - 1].second);
        rem = min(rem, r - l);
    }
    cout << ans - rem << '\n';
    return 0;
}