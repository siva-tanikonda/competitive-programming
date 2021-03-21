#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int cap[3], amt[3];

int main(){
    IO("mixmilk.in", "mixmilk.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 3; i++)
        cin >> cap[i] >> amt[i];
    int cur = 0;
    for(int i = 0; i < 100; i++){
        int nxt = (cur + 1) % 3;
        int move = min(amt[cur], cap[nxt] - amt[nxt]);
        amt[nxt] += move, amt[cur] -= move;
        cur = nxt;
    }
    for(int i = 0; i < 3; i++) cout << amt[i] << '\n';
    return 0;
}