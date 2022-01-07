#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;

int n, ans[1000];
tuple<int, int, int, int> a[1000];
bool done[1000];

bool cmp(const tuple<int, int, int, int> &u, const tuple<int, int, int, int> &v){
    return get<1>(u) < get<1>(v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        char c;
        int x, y;
        cin >> c >> x >> y;
        a[i] = make_tuple(x, y, c, i);
    }
    sort(a, a + n);
    for(int i = 1; i < n; i++){
        char c;
        int x, y, idx;
        tie(x, y, c, idx) = a[i];
        if(c == 'E') continue;
        sort(a, a + i, cmp);
        for(int j = 0; j < i; j++){
            char d;
            int u, v, jdx;
            tie(u, v, d, jdx) = a[j];
            if(d == 'N' || v < y || done[jdx] || done[idx]) continue;
            if(v - y < x - u)
                done[jdx] = true, ans[idx] += ans[jdx] + 1;
            else if(v - y > x - u)
                ans[jdx] += ans[idx] + 1, done[idx] = true;
        }
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << '\n';
    return 0;
}