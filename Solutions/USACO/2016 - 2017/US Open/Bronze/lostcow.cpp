#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int x, y, ans;

bool found(int cur, int nxt){
    int dir = (cur < nxt) ? 1 : -1;
    for(int i = cur; i != nxt; i += dir){
        if(i == y) return true;
        ans++;
    }
    return false;
}

int main(){
    IO("lostcow.in", "lostcow.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y;
    int dir = 1, cur = x, nxt = x + 1;
    while(!found(cur, nxt)){
        cur = nxt, dir *= -2;
        nxt = x + dir;
    }
    cout << ans << '\n';
    return 0;
}