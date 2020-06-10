#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m;
long long a[1001][2], b[1001][2];

long long dist(int i, int j){
	return (a[i][0] - b[j][0]) * (a[i][0] - b[j][0]) + (a[i][1] - b[j][1]) * (a[i][1] - b[j][1]);
}

long long dp[1001][1001];
int main(){
	IO("radio.in", "radio.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string x, y;
	cin >> n >> m >> a[0][0] >> a[0][1] >> b[0][0] >> b[0][1] >> x >> y;
	for(int i = 0; i < n; i++){
		a[i + 1][0] = a[i][0], a[i + 1][1] = a[i][1];
		if(x[i] == 'N') a[i + 1][1]++;
		else if(x[i] == 'S') a[i + 1][1]--;
		else if(x[i] == 'E') a[i + 1][0]++;
		else a[i + 1][0]--;
	}
	for(int i = 0; i < m; i++){
		b[i + 1][0] = b[i][0], b[i + 1][1] = b[i][1];
		if(y[i] == 'N') b[i + 1][1]++;
		else if(y[i] == 'S') b[i + 1][1]--;
		else if(y[i] == 'E') b[i + 1][0]++;
		else b[i + 1][0]--;
	}
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++) dp[i][j] = LLONG_MAX;
	dp[0][0] = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++){
			if(i < n) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dist(i + 1, j));
			if(j < m) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + dist(i, j + 1));
			if(i < n && j < m) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + dist(i + 1, j + 1));
		}
	cout << dp[n][m] << "\n";
	return 0;
}