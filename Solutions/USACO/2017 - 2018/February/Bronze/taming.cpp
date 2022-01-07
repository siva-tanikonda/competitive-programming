#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, a[100];
bool on[100], off[100];

int main(){
    IO("taming.in", "taming.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    on[0] = true;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == -1) continue;
        if(a[i] > i){
            cout << "-1\n";
            return 0;
        }
        on[i - a[i]] = true;
        for(int j = i - a[i] + 1; j <= i; j++) off[j] = true;
    }
    int mn = 0, free = 0;
    for(int i = 0; i < n; i++)
        if(on[i] && off[i]){
            cout << "-1\n";
            return 0;
        }else if(on[i]) mn++;
        else if(!off[i] && !on[i]) free++;
    cout << mn << ' ' << mn + free << '\n';
    return 0;
}