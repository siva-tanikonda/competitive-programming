#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, arr[101], dif[101][101], dp[100][101];

int main(){
	IO("taming.in", "taming.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++) dif[i][j] = dif[i][j - 1] + (arr[j] != j - i);
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++) dp[0][i] = dp[0][i - 1] + (arr[i] != i - 1);
	for(int i = 1; i < n; i++){
		dp[i][0] = 0;
		for(int j = i + 1; j <= n; j++){
			dp[i][j] = INT_MAX;
			for(int k = i; k < j; k++) dp[i][j] = min(dp[i][j], dp[i - 1][k] + dif[k + 1][j]);
		}
	}
	for(int i = 0; i < n; i++) cout << dp[i][n] << "\n";
	return 0;
}
