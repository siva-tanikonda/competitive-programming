#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, p[100];

int main(){
    IO("sleepy.in", "sleepy.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i];
    int i = n - 1;
    while(i >= 0 && (i == n - 1 || p[i] < p[i + 1])) i--;
    cout << (i + 1) << '\n';
    return 0;
}