/*
ID: siva.ja1
TASK: money
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

int n, m, val[26];

int main(){
	IO("money.in", "money.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> val[i];
	vector<long long> dp(m + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = val[i]; j <= m; j++) dp[j] += dp[j - val[i]];
	cout << dp[m] << "\n";
	return 0;
}