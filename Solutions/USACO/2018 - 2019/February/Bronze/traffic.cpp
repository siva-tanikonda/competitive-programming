#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, l[100], r[100], s[2], e[2];
string typ[100];

int main(){
    IO("traffic.in", "traffic.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> typ[i] >> l[i] >> r[i];
    s[0] = e[0] = INT_MAX, s[1] = e[1] = 0;
    for(int i = 0; i <= 1e3; i++){
        int u = i, v = i;
        for(int j = 0; j < n; j++){
            if(typ[j] == "on") u += l[j], v = min(1000, v + r[j]);
            else if(typ[j] == "off") v -= l[j], u = max(0, u - r[j]);
            else v = min(v, r[j]), u = max(u, l[j]);
            if(u > v) break;
            else if(j == n - 1){
                s[0] = min(s[0], i), s[1] = max(s[1], i);
                e[0] = min(e[0], u), e[1] = max(e[1], v);
            } 
        }
    }
    cout << s[0] << ' ' << s[1] << '\n';
    cout << e[0] << ' ' << e[1] << '\n';
    return 0;
}