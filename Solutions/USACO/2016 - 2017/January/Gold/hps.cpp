#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n, m, arr[100000], dp[100001][21][3];

int main(){
	IO("hps.in", "hps.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		if(c == 'H') arr[i] = 0;
		else if(c == 'P') arr[i] = 1;
		else arr[i] = 2;
	}
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			for(int k = 0; k < 3; k++) dp[i][j][k] = -1;
	for(int i = 0; i <= m; i++)
		for(int j = 0; j < 3; j++) dp[0][i][j] = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= m; j++)
			for(int k = 0; k < 3; k++){
				if(dp[i][j][k] == -1) continue;
				if(k == arr[i]) dp[i][j][k]++;
				if(dp[i + 1][j][k] == -1 || dp[i + 1][j][k] < dp[i][j][k])
					dp[i + 1][j][k] = dp[i][j][k];
				if(j < m)
					for(int l = 0; l < 3; l++)
						if(dp[i + 1][j + 1][l] == -1 || dp[i + 1][j + 1][l] < dp[i][j][k])
							dp[i + 1][j + 1][l] = dp[i][j][k];
			}
	int mx = 0;
	for(int i = 0; i < 3; i++) mx = max(mx, dp[n][m][i]);
	cout << mx << "\n";
	return 0;
}