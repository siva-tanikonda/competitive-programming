#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, c, a[1001], dp[1001][1001];
vector<int> adj[1001];

int main(){
	IO("time.in", "time.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> c;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for(int i = 0; i <= 1000; i++)
		for(int j = 1; j <= n; j++) dp[i][j] = -1;
	dp[0][1] = 0;
	int mx = 0;
	for(int i = 1; i <= 1000; i++){
		for(int j = 1; j <= n; j++)
			for(auto &k : adj[j])
				if(dp[i - 1][j] != -1 && (dp[i][k] == -1 || dp[i][k] < dp[i - 1][j] + a[k]))
					dp[i][k] = dp[i - 1][j] + a[k];
		mx = max(mx, dp[i][1] - c * i * i);
	}
	cout << mx << "\n";
	return 0;
}
