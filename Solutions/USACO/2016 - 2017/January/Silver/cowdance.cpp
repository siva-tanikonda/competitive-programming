#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using ll = long long;

int n, m, a[10000];

bool check(int k){
    multiset<int> que;
    for(int i = 0; i < k; i++) que.insert(a[i]);
    int t = 0;
    for(int i = k; i < n; i++){
        t += *que.begin() - t;
        que.erase(que.begin());
        que.insert(a[i] + t);
    }
    while(!que.empty())
        t += *que.begin() - t, que.erase(que.begin());
    return (t <= m);
}

int main(){
    IO("cowdance.in", "cowdance.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 1, r = n;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}