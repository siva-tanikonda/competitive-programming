#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m, a[50000];

bool check(int rad){
    int need = 0;
    for(int i = 0; i < n;){
        int ub = a[i] + 2 * rad;
        while(i < n && a[i] <= ub) i++;
        need++;
    }
    return (need <= m);
}

int main(){
    IO("angry.in", "angry.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int l = 0, r = 1e9 / 2;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}