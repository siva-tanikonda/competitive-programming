#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, l[10], r[10], b[10], t[10];
string a[10];
bool ans[10];

int main(){
    IO("art.in", "art.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < 10; i++)
        l[i] = b[i] = INT_MAX, r[i] = t[i] = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < n; j++){
            int c = a[i][j] - '0';
            if(!c) continue;
            l[c] = min(l[c], i), r[c] = max(r[c], i);
            b[c] = min(b[c], j), t[c] = max(t[c], j);
        }
    }
    bool blank = true;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            blank &= (a[i][j] == '0');
    if(blank){
        cout << "0\n";
        return 0;
    }
    vector<int> ord;
    for(int i = 1; i < 10; i++)
        if(r[i] != -1) ord.push_back(i);
    do{
        if(ans[ord[0]]) continue;
        vector<vector<int>> arr(n, vector<int>(n, 0));
        for(int i : ord)
            for(int j = l[i]; j <= r[i]; j++)
                for(int k = b[i]; k <= t[i]; k++) arr[j][k] = i;
        bool work = true;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                work &= ((int)(a[i][j] - '0') == arr[i][j]);
        ans[ord[0]] |= work;
    }while(next_permutation(ord.begin(), ord.end()));
    int res = 0;
    cout << accumulate(ans, ans + 10, res) << '\n';
    return 0;
}