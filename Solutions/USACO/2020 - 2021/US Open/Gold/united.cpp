#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct fenwick_tree{
    vector<int> arr;
    void init(int n) { arr.resize(n); }
    void update(int pos, int add){
        for(; pos < (int)arr.size(); pos |= pos + 1)
            arr[pos] += add;
    }
    int query(int pos){
        int sum = 0;
        for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
            sum += arr[pos];
        return sum;
    }
};

int n, b[200001], pre[200001];
vector<int> rem[200001];
fenwick_tree fen;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> b[i];
    fill(pre, pre + n + 1, n + 1);
    for(int i = n; i > 0; i--){
        rem[pre[b[i]] - 1].push_back(i);
        pre[b[i]] = i;
    }
    fill(pre, pre + n + 1, 0);
    fen.init(n + 1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += fen.query(i) - fen.query(pre[b[i]]);
        fen.update(i, 1);
        for(int j : rem[i]) fen.update(j, -1);
        pre[b[i]] = i;
    }
    cout << ans << '\n';
    return 0;
}