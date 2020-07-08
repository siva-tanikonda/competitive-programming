#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, dp[100001], cur[100001];
vector<int> adj[100001], num[100001];

void dfs(int vtx, int pre){
	dp[vtx] = 1;
	for(auto &i : adj[vtx])
		if(i != pre){
			dfs(i, vtx);
			dp[vtx] += dp[i];
			num[vtx].push_back(dp[i]);
		}
	if(dp[vtx] != n) num[vtx].push_back(n - dp[vtx]);
}

bool check(int k){
	if((n - 1) % k) return 0;
	for(int i = 0; i < k; i++) cur[i] = 0;
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(auto &j : num[i]){
			int z = j % k;
			if(z == 0) continue;
			if(cur[k - z]) cur[k - z]--, cnt--;
			else cur[z]++, cnt++;
		}
		if(cnt) return false;
	}
	return true;
}

int main(){
	IO("deleg.in", "deleg.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	for(int i = 1; i < n; i++) cout << check(i);
	cout << "\n";
	return 0;
}
