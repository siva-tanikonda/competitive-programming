#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n;

int main(){
    IO("outofplace.in", "outofplace.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> a, b;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    bool work = true;
    for(int i = 1; i < n; i++)
        work &= (a[i] >= a[i - 1]);
    if(work){
        cout << "0\n";
        return 0;
    }
    int beg = -1, end = -1;
    for(int i = 0; i < n; i++){
        b = a;
        b.erase(b.begin() + i);
        work = true;
        for(int j = 1; j < n - 1; j++)
            work &= (b[j] >= b[j - 1]);
        if(work) beg = i;
    }
    b = a;
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++)
        if(b[i] == a[beg]) end = i;
    if(end < beg){
        beg = a.size() - 1 - beg;
        end = a.size() - 1 - end;
        reverse(a.begin(), a.end());
    }
    int ans = 0;
    for(int i = beg + 1; i <= end; i++)
        ans += (a[i] != a[i - 1]);
    ans -= (a[end] == a[beg]);
    cout << ans << '\n';
    return 0;
}