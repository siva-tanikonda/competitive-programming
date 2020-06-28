#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, nxt[100000], pre[100000];
pair<int, int> f[100000];
tuple<int, int, int> bt[100000];
bool ans[100000];

int main(){
	IO("snowboots.in", "snowboots.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> f[i].first, f[i].second = i;
	for(int i = 0; i < m; i++){
		int a, b, c = i;
		cin >> a >> b;
		bt[i] = make_tuple(a, b, c);
	}
	for(int i = 1; i < n - 1; i++)
		nxt[i] = i + 1, pre[i] = i - 1;
	sort(f, f + n, greater<pair<int, int>>());
	sort(bt, bt + m, greater<tuple<int, int, int>>());
	int j = 0, mx = 1;
	for(int i = 0; i < m; i++){
		int h, s, idx;
		tie(h, s, idx) = bt[i];
		while(j < n && f[j].first > h){
			int k = f[j].second;
			pre[nxt[k]] = pre[k];
			nxt[pre[k]] = nxt[k];
			mx = max(mx, nxt[k] - pre[k]);
			nxt[k] = pre[k] = -1;
			j++;
		}
		ans[idx] = (mx <= s);
	}
	for(int i = 0; i < m; i++) cout << ans[i] << "\n";
	return 0;
}
