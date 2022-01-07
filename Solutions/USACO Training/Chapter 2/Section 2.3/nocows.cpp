/*
ID: siva.ja1
TASK: nocows
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

const int mod = 9901;
int n, m;

int main(){
	IO("nocows.in", "nocows.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	dp[1][1] = 1;
	for(int i = 2; i <= m; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k < j - 1; k++){
				dp[i][j] = (dp[i][j] + (dp[i - 1][k] * dp[i - 1][j - 1 - k]) % mod) % mod;
				for(int l = 1; l < i - 1; l++)
					dp[i][j] = (dp[i][j] + (dp[i - 1][k] * dp[l][j - 1 - k] * 2) % mod) % mod;
			}
	cout << dp[m][n] << "\n";
	return 0;
}