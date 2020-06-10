#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n, a[248];

int dp[248][248]; 
int main(){
	IO("248.in", "248.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	int res = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; i + j <= n; j++){
			int end = i + j - 1;
			dp[j][end] = -1;
			if(i == 1) dp[j][end] = a[j];
			for(int k = j; k < end; k++)
				if(dp[j][k] == dp[k + 1][end] && dp[j][k] > 0)
					dp[j][end] = max(dp[j][end], dp[j][k] + 1);
			res = max(res, dp[j][end]);
		}
	}
	cout << res << "\n";
	return 0;
}