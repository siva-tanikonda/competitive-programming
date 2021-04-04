#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
pair<int, int> a[100001];

int main(){
    IO("sort.in", "sort.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), srand(time(NULL));
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].first, a[i].second = i;
    sort(a, a + n + 1);
    vector<int> alt(n + 1);
    for(int i = 1; i <= n; i++)
        alt[a[i].second] = i;
    int ans = 1;
    for(int i = 1; i <= n; i++)
        ans = max(ans, i - alt[i] + 1);
    cout << ans << '\n';
    return 0;
}