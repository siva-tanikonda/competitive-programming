/*
ID: siva.ja1
TASK: game1
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, a[101], dp[101][101];

int main(){
	IO("game1.in", "game1.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) dp[i][i] = a[i];
	for(int i = 1; i < n; i++) dp[i][i + 1] = max(a[i], a[i + 1]);
	for(int i = 2; i < n; i++)
		for(int j = 1; j <= n - i; j++){
			int op1 = a[j] + min(dp[j + 2][j + i], dp[j + 1][j + i - 1]);
			int op2 = a[j + i] + min(dp[j][j + i - 2], dp[j + 1][j + i - 1]);
			dp[j][j + i] = max(op1, op2);
		}
	cout << dp[1][n] << " " << min(dp[2][n], dp[1][n - 1]) << "\n";
	return 0;
}