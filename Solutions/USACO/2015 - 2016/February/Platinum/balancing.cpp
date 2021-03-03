#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

struct fenwick_tree{
    vector<int> arr;
    void init(int n){
        arr.resize(n);
        fill(arr.begin(), arr.end(), 0);
    }
    void update(int i, int add){
        for(; i < (int)arr.size(); i |= i + 1) arr[i] += add;
    }
    int query(int i){
        int sum = 0;
        for(; i >= 0; i = (i & (i + 1)) - 1) sum += arr[i];
        return sum;
    }
};

int n, m;
pair<int, int> a[100000];
map<int, vector<int>> ord;
fenwick_tree fen[2];

bool check(int goal){
    fen[0].init(m + 1), fen[1].init(m + 1);
    int sz1 = 0, sz2 = n, l1 = m, r1 = 0, l2 = m, r2 = 0;
    for(auto &i : ord)
        for(int j : i.second) fen[1].update(j, 1);
    while(l2 > 0 && fen[1].query(l2) > goal) l2--;
    while(r2 < m && n - fen[1].query(r2) > goal) r2++;
    if(l2 >= r2) return true;
    for(auto &i : ord){
        for(int j : i.second){
            fen[1].update(j, -1);
            fen[0].update(j, 1);
        }
        sz1 += i.second.size(), sz2 -= i.second.size();
        while(l1 > 0 && fen[0].query(l1) > goal) l1--;
        while(r1 < m && sz1 - fen[0].query(r1) > goal) r1++;
        while(l2 < m && fen[1].query(l2) <= goal) l2++;
        while(r2 > 0 && sz2 - fen[1].query(r2) <= goal) r2--;
        if(l2 != m) l2--;
        if(r2) r2++;
        if(l1 < r1) return false;
        else if(l2 < r2 || l1 < r2 || l2 < r1) continue;
        else return true;
    }
    return false;
}

int main(){
    IO("balancing.in", "balancing.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    set<int> crd;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        crd.insert(a[i].first);
        crd.insert(a[i].second);
    }
    map<int, int> pnt;
    m = 1;
    for(int i : crd) pnt[i] = m++;
    for(int i = 0; i < n; i++){
        a[i].first = pnt[a[i].first];
        a[i].second = pnt[a[i].second];
        ord[a[i].first].push_back(a[i].second);
    }
    int l = 0, r = n;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}