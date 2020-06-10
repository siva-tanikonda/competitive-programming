#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n, a[1000], b[1000], dp[1001][1001];

int main(){
	IO("nocross.in", "nocross.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++) dp[i][j] = -1;
	dp[0][0] = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++){
			if(dp[i][j] == -1) continue;
			if(i < n && j < n && abs(a[i] - b[j]) <= 4 && (dp[i + 1][j + 1] == -1 || dp[i + 1][j + 1] < dp[i][j] + 1))
				dp[i + 1][j + 1] = dp[i][j] + 1;
			if(i < n && (dp[i + 1][j] < dp[i][j])) dp[i + 1][j] = dp[i][j];
			if(j < n && (dp[i][j + 1] < dp[i][j])) dp[i][j + 1] = dp[i][j]; 
		}
	cout << dp[n][n] << "\n";
	return 0;
}