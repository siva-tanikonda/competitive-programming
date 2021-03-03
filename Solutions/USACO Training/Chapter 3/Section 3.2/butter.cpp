/*
ID: siva.ja1
TASK: butter
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int c, n, m, cost[801], dst[801], cow[801];
bool vis[801];
vector<pair<int, int>> adj[801];

int main(){
	IO("butter.in", "butter.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> c >> n >> m;
	for(int i = 0; i < c; i++){
		int idx;
		cin >> idx;
		cow[idx]++;
	}
	for(int i = 0; i < m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({y, z});
		adj[y].push_back({x, z});
	}
	for(int k = 1; k <= n; k++)
		if(cow[k]){
			for(int i = 1; i <= n; i++) vis[i] = false, dst[i] = 1e9;
			priority_queue<pair<int, int>> que;
			que.push({0, k}), dst[k] = 0;
			while(!que.empty()){
				int vtx = que.top().second;
				que.pop();
				if(vis[vtx]) continue;
				vis[vtx] = true;
				for(auto &i : adj[vtx])
					if(dst[i.first] > dst[vtx] + i.second){
						dst[i.first] = dst[vtx] + i.second;
						que.push({-dst[i.first], i.first});
					}
			}
			for(int i = 1; i <= n; i++) cost[i] += dst[i] * cow[k];
		}
	int mn = INT_MAX;
	for(int i = 1; i <= n; i++) mn = min(mn, cost[i]);
	cout << mn << "\n";
	return 0;
}