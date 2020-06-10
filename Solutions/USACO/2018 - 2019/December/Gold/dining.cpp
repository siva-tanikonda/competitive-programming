#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, k;
pair<int, int> yum;
vector<pair<int, int>> adj[50002];

int dst[50002][2];
bool vis[50002][2];
void dijkstra(int idx, int src){
	for(int i = 1; i <= n + 1; i++) dst[i][idx] = INT_MAX;
	set<pair<int, int>> que;
	que.insert({0, src});
	dst[src][idx] = 0;
	while(!que.empty()){
		int vtx = que.begin() -> second;
		que.erase(que.begin());
		if(vis[vtx][idx]) continue;
		vis[vtx][idx] = true;
		for(auto &i : adj[vtx])
			if(dst[i.first][idx] == INT_MAX || dst[i.first][idx] > dst[vtx][idx] + i.second){
				dst[i.first][idx] = dst[vtx][idx] + i.second;
				que.insert({dst[i.first][idx], i.first});
			}
	}
}

int main(){
	IO("dining.in", "dining.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int u, v, t;
		cin >> u >> v >> t;
		adj[u].push_back({v, t});
		adj[v].push_back({u, t});
	}
	dijkstra(0, n);
	for(int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		adj[n + 1].push_back({x, dst[x][0] - y});
	}
	dijkstra(1, n + 1);
	for(int i = 1; i < n; i++) cout << (dst[i][0] >= dst[i][1]) << "\n";
	return 0;
}