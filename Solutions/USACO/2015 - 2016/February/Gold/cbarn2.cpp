#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m;
long long r[101];

long long dp[8][101], dst[101][101];
int main(){
	IO("cbarn2.in", "cbarn2.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> r[i];
	long long mn = LLONG_MAX;
	for(int x = 1; x < n; x++){
		for(int i = 1; i <= n; i++){
			dst[i][i] = 0;
			for(int j = i + 1; j <= n; j++) dst[i][j] = dst[i][j - 1] + r[j] * (j - i);
		}
		for(int i = 0; i <= m; i++)
			for(int j = 0; j <= n; j++) dp[i][j] = -1;
		dp[0][0] = 0;
		for(int i = 1; i <= m; i++)
			for(int j = 0; j <= n; j++){
				dp[i][j] = LLONG_MAX;
				for(int k = 0; k <= j; k++)
					if(dp[i - 1][k] != -1) dp[i][j] = min(dp[i][j], dp[i - 1][k] + dst[k + 1][j]);
			}
		mn = min(mn, dp[m][n]);
		rotate(r + 1, r + 2, r + n + 1);
	}
	cout << mn << "\n";
	return 0;
}