#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n, m, crd[1001][2][2], dp[1001][1001][2];

int dst(int a, int x, int b, int y){
	return (crd[a][x][0] - crd[b][y][0]) * (crd[a][x][0] - crd[b][y][0]) + (crd[a][x][1] - crd[b][y][1]) * (crd[a][x][1] - crd[b][y][1]);
}

int main(){
	IO("checklist.in", "checklist.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> crd[i][0][0] >> crd[i][0][1];
	for(int i = 0; i < m; i++) cin >> crd[i][1][0] >> crd[i][1][1];
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			for(int k = 0; k < 2; k++) dp[i][j][k] = -1;
	dp[1][0][0] = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			for(int k = 0; k < 2; k++){
				if(dp[i][j][k] == -1 || (i == n && j == m)) continue;
				if(k == 0){
					if(i < n && (dp[i + 1][j][0] == -1 || dp[i + 1][j][0] > dp[i][j][k] + dst(i - 1, 0, i, 0)))
						dp[i + 1][j][0] = dp[i][j][k] + dst(i - 1, 0, i, 0);
					if(j < m && (dp[i][j + 1][1] == -1 || dp[i][j + 1][1] > dp[i][j][k] + dst(i - 1, 0, j, 1)))
						dp[i][j + 1][1] = dp[i][j][k] + dst(i - 1, 0, j, 1);
				}else{
					if(i < n && (dp[i + 1][j][0] == -1 || dp[i + 1][j][0] > dp[i][j][k] + dst(j - 1, 1, i, 0)))
						dp[i + 1][j][0] = dp[i][j][k] + dst(j - 1, 1, i, 0);
					if(j < m && (dp[i][j + 1][1] == -1 || dp[i][j + 1][1] > dp[i][j][k] + dst(j - 1, 1, j, 1)))
						dp[i][j + 1][1] = dp[i][j][k] + dst(j - 1, 1, j, 1);
				}
			}
	cout << dp[n][m][0] << "\n";
	return 0;
}