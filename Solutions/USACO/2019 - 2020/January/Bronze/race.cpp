#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using ll = long long;

int n;
ll k, x;

bool able(ll sum, ll cur){
    ll nxt = sum + cur;
    ll add = ((cur + x) * (cur - x - 1)) / 2;
    return (nxt + add < k);
}

int main(){
    IO("race.in", "race.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        ll sum = 0, cur = 0, ans = 0;
        while(sum < k){
            if(cur < x || able(sum, cur + 1)) cur++;
            else if(!able(sum, cur)) cur--;
            sum += cur, ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}