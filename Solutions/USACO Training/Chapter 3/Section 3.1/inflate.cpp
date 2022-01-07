/*
ID: siva.ja1
TASK: inflate
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const double pi = 3.14159265358979;

int m, n, pnt[10000], mn[10000];

int main(){
	IO("inflate.in", "inflate.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for(int i = 0; i < n; i++) cin >> pnt[i] >> mn[i];
	vector<int> dp(m + 1, 0);
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= m; j++)
			if(j - mn[i] >= 0) dp[j] = max(dp[j], dp[j - mn[i]] + pnt[i]);
	int mx = 0;
	for(int i = 0; i <= m; i++) mx = max(mx, dp[i]);
	cout << mx << "\n";
	return 0;
}