#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

const int mod = 1e9 + 7;
int n, m;
long long dp[100001][3];
vector<int> adj[100001];

void dfs(int vtx, int pre){
	if((int)adj[vtx].size() == 1 && adj[vtx][0] == pre){
		for(int i = 0; i < 3; i++)
			if(dp[vtx][i] != -1) dp[vtx][i] = 1;
	}else{
		for(auto &i : adj[vtx])
			if(i != pre) dfs(i, vtx);
		for(int i = 0; i < 3; i++)
			if(dp[vtx][i] != -1){
				dp[vtx][i] = 1;
				for(auto &j : adj[vtx])
					if(j != pre){
						long long sum = 0;
						for(int k = 0; k < 3; k++)
							if(k != i) sum = (sum + max(0LL, dp[j][k])) % mod;
						dp[vtx][i] = (dp[vtx][i] * sum) % mod;
					}
			}
	}
}

int main(){
	IO("barnpainting.in", "barnpainting.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		for(int j = 0; j < 3; j++)
			if(j != b - 1) dp[a][j] = -1;
	}
	dfs(1, 0);
	cout << ((dp[1][0] + dp[1][1]) % mod + dp[1][2]) % mod << "\n";
	return 0;
}
