#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int odd = 0, even = 0;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        if(val % 2) odd++;
        else even++;
    }
    int ans = 0, cur = 0;
    while(true){
        if(cur){
            if(odd) odd--;
            else break;
        }else{
            if(even) even--;
            else if(odd >= 2) odd -= 2;
            else break;
        }
        ans++, cur ^= 1;
    }
    if(odd % 2) ans--;
    cout << ans << '\n';
    return 0;
}