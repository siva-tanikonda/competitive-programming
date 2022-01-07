#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using ll = long long;

int n, m, k, t[100000];

bool check(int mx){
    int use = 0;
    for(int i = 0; i < n;){
        int ub = t[i] + mx, cnt = 0;
        while(i < n && cnt < k && t[i] <= ub)
            i++, cnt++;
        use++;
    }
    return (use <= m);
}

int main(){
    IO("convention.in", "convention.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> t[i];
    sort(t, t + n);
    int l = 0, r = 1e9;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}