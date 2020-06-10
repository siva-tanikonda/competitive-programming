/*
ID: siva.ja1
TASK: subset
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

int n;

int main(){
	IO("subset.in", "subset.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<vector<long long>> dp(n + 1, vector<long long>((n * (n + 1)) / 4 + 1));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= (n * (n + 1)) / 4; j++){
			dp[i][j] = dp[i - 1][j];
			if(j - i >= 0) dp[i][j] += dp[i - 1][j - i];
		}
	cout << (((n * (n + 1)) % 4 == 0) ? dp[n][(n * (n + 1)) / 4] / 2 : 0) << "\n";
	return 0;
}