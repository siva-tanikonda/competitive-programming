#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;
pair<int, int> a[100000];

int main(){
    IO("pairup.in", "pairup.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a, a + n);
    int ans = 0;
    int i = 0, j = n - 1;
    while(i < j){
        ans = max(ans, a[i].first + a[j].first);
        int rem = min(a[i].second, a[j].second);
        a[i].second -= rem, a[j].second -= rem;
        if(!a[i].second) i++;
        if(!a[j].second) j--;
    }
    if(i == j && a[i].second > 0)
        ans = max(ans, 2 * a[i].first);
    cout << ans << '\n';
    return 0;
}