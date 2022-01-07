#pragma GCC optimize("unroll-loops, O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m;
string s;
tuple<int, int, int> a[250];

int main(){
    IO("tracing.in", "tracing.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> s, s = '0' + s;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = make_tuple(x, y, z);
    }
    sort(a, a + m);
    int x = 0, y = 251, z = 0;
    for(int i = 1; i <= n; i++){
        bool work = false;
        for(int j = 0; j <= 251; j++){
            string nxt(n + 1, '0');
            vector<int> cnt(n + 1, -1);
            nxt[i] = '1', cnt[i] = j;
            for(int k = 0; k < m; k++){
                int p, q, r;
                tie(p, q, r) = a[k];
                if((nxt[q] == '1' && cnt[q] > 0) || (nxt[r] == '1' && cnt[r] > 0)){
                    if(cnt[q] > 0) cnt[q]--;
                    if(cnt[r] > 0) cnt[r]--;
                    if(nxt[q] == '0' && cnt[q] == -1)
                        nxt[q] = '1', cnt[q] = j;
                    if(nxt[r] == '0' && cnt[r] == -1)
                        nxt[r] = '1', cnt[r] = j;
                }
            }
            if(nxt == s)
                work = true, y = min(y, j), z = max(z, j);
        }
        x += work;
    }
    cout << x << ' ' << y << ' ';
    if(z == 251) cout << "Infinity\n";
    else cout << z << '\n';
    return 0;
}