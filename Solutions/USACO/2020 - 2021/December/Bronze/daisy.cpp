#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;

int n, p[100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        int sum = 0;
        for(int j = i; j >= 0; j--){
            sum += p[j];
            bool work = false;
            for(int k = j; k <= i; k++)
                work |= (p[k] * (i - j + 1) == sum);
            ans += work;
        }
    }
    cout << ans << '\n';
    return 0;
}