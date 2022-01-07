#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

template<class T> struct sparse_table{
	vector<vector<T>> arr;
	void init(vector<T> &lst){
		int n = (int)lst.size(), dep = 31 - __builtin_clz(n);
		arr.resize(dep + 1, lst);
		for(int i = 0; i < dep; i++)
			for(int j = 0; j < n; j++)
				arr[i + 1][j] = min(arr[i][j], arr[i][min(n - 1, j + (1 << i))]);
	}
	T query(int a, int b){
		int dep = 31 - __builtin_clz(b - a + 1);
		return min(arr[dep][a], arr[dep][b - (1 << dep) + 1]);
	}
};

struct lowest_common_ancestor{
	vector<int> fir;
	vector<pair<int, int>> eul;
	sparse_table<pair<int, int>> rmq;
	void init(int n, vector<int> adj[]){
		fir.resize(n + 1);
		dfs(1, 0, 0, adj);
		rmq.init(eul);
	}
	void dfs(int vtx, int pre, int hgt, vector<int> adj[]){
		fir[vtx] = (int)eul.size();
		eul.push_back({hgt, vtx});
		for(int i : adj[vtx])
			if(i != pre){
				dfs(i, vtx, hgt + 1, adj);
				eul.push_back({hgt, vtx});
			}
	}
	int query(int a, int b){
		a = fir[a], b = fir[b];
		if(a > b) swap(a, b);
		return rmq.query(a, b).second;
	}
};	

int n, m, par[50001], dp[50001];
vector<int> adj[50001];

void dfs1(int vtx, int pre){
	par[vtx] = pre;
	for(int i : adj[vtx])
		if(i != pre) dfs1(i, vtx);
}

int dfs2(int vtx, int pre){
	for(int i : adj[vtx])
		if(i != pre) dp[vtx] += dfs2(i, vtx);
	return dp[vtx];
}

int main(){
	IO("maxflow.in", "maxflow.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	lowest_common_ancestor lca;
	lca.init(n, adj);
	dfs1(1, 0);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		int con = lca.query(a, b);
		dp[a]++, dp[b]++;
		dp[con]--, dp[par[con]]--;
	}
	dfs2(1, 0);
	int ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans << '\n';
	return 0;
}