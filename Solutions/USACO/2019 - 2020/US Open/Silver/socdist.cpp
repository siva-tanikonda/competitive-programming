#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using ll = long long;

int n, m;
pair<ll, ll> a[100000];

bool check(ll d){
    ll pre = a[0].first;
    int j = 0;
    for(int i = 1; i < n; i++){
        ll nxt = pre + d;
        while(j < m && a[j].second < nxt) j++;
        if(j == m) return false;
        if(a[j].first > nxt) nxt = a[j].first;
        pre = nxt;
    }
    return true;
}

int main(){
    IO("socdist.in", "socdist.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + m);
    ll l = 1, r = 1e18;
    while(l < r){
        ll mid = l + (r - l + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
    return 0;
}