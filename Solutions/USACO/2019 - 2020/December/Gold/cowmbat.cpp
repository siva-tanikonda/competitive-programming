#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, k, adj[26][26];
string s;

int dp[100001][26], mn[100001], cost[100001][26];
int main(){
	IO("cowmbat.in", "cowmbat.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k >> s;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++) cin >> adj[i][j];
	for(int l = 0; l < m; l++)
		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				adj[i][j] = min(adj[i][j], adj[i][l] + adj[l][j]);
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < m; j++) cost[i][j] = cost[i - 1][j] + adj[s[i - 1] - 'a'][j];
	for(int i = 0; i <= n; i++){
		mn[i] = 1e9;
		for(int j = 0; j < m; j++) dp[i][j] = 1e9;
	}
	mn[0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < m; j++){
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + adj[s[i - 1] - 'a'][j]);
			if(i >= k) dp[i][j] = min(dp[i][j], cost[i][j] - cost[i - k][j] + mn[i - k]);
			mn[i] = min(mn[i], dp[i][j]);
		}
	cout << mn[n] << "\n";
	return 0;
}