#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct lazy_segment_tree{
    vector<ll> arr, lzy;
    vector<int> inv;
    int n;
    void init(int _n){
        n = _n, inv.resize(n * 4);
        arr.resize(n * 4), lzy.resize(n * 4);
    }
    void push(int vtx, int tl, int tr){
        int mid = tl + (tr - tl) / 2;
        arr[vtx * 2] += (mid - tl + 1 - inv[vtx * 2]) * lzy[vtx];
        lzy[vtx * 2] += lzy[vtx];
        arr[vtx * 2 + 1] += (tr - mid - inv[vtx * 2 + 1]) * lzy[vtx];
        lzy[vtx * 2 + 1] += lzy[vtx];
        lzy[vtx] = 0;
    }
    void update(int vtx, int tl, int tr, int l, int r, ll val){
        if(l > r) return;
        else if(l == tl && r == tr){
            arr[vtx] += (tr - tl + 1 - inv[vtx]) * val;
            lzy[vtx] += val;
        }else{
            push(vtx, tl, tr);
            int mid = tl + (tr - tl) / 2;
            update(vtx * 2, tl, mid, l, min(mid, r), val);
            update(vtx * 2 + 1, mid + 1, tr, max(mid + 1, l), r, val);
            arr[vtx] = arr[vtx * 2] + arr[vtx * 2 + 1];
        }
    }
    void update(int l, int r, ll val){
        update(1, 0, n - 1, l, r, val);
    }
    void invalid(int vtx, int tl, int tr, int pos){
        if(tl == tr) arr[vtx] = 0, inv[vtx] = 1;
        else{
            push(vtx, tl, tr);
            int mid = tl + (tr - tl) / 2;
            if(mid >= pos) invalid(vtx * 2, tl, mid, pos);
            else invalid(vtx * 2 + 1, mid + 1, tr, pos);
            inv[vtx] = inv[vtx * 2] + inv[vtx * 2 + 1];
            arr[vtx] = arr[vtx * 2] + arr[vtx * 2 + 1];
        }
    }
    void invalid(int pos){
        invalid(1, 0, n - 1, pos);
    }
    ll query(int vtx, int tl, int tr, int l, int r){
        if(l > r) return 0;
        else if(l == tl && r == tr) return arr[vtx];
        else{
            push(vtx, tl, tr);
            int mid = tl + (tr - tl) / 2;
            ll p1 = query(vtx * 2, tl, mid, l, min(r, mid));
            ll p2 = query(vtx * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
            return p1 + p2;
        }
    }
    ll query(int l, int r){
        return query(1, 0, n - 1, l, r);
    }
};

int n, b[200001], l[200001], pre[200001], sub[200001];
lazy_segment_tree seg;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> b[i];
    fill(pre, pre + n + 1, 0);
    for(int i = 1; i <= n; i++)
        l[i] = pre[b[i]] + 1, pre[b[i]] = i;
    fill(pre, pre + n + 1, n + 1);
    for(int i = n; i > 0; i--)
        sub[pre[b[i]] - 1] = i, pre[b[i]] = i;
    seg.init(n + 1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += seg.query(l[i], i);
        seg.update(l[i], i - 1, 1);
        seg.invalid(sub[i]);
        seg.update(l[sub[i]], sub[i] - 1, -1);
    }
    cout << ans << '\n';
    return 0;
}