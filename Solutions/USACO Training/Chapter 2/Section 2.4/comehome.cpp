/*
ID: siva.ja1
TASK: comehome
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const double pi = 3.14159265358979;

int n;
vector<pair<int, int>> adj[200];

int main(){
	IO("comehome.in", "comehome.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		char a, b;
		int c;
		cin >> a >> b >> c;
		adj[(int)a].push_back({b, c});
		adj[(int)b].push_back({a, c});
	}
	priority_queue<pair<int, int>> que;
	vector<int> dst(200, (int)1e9);
	vector<bool> vis(200, false);
	que.push({0, 90});
	dst[90] = 0;
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
	pair<int, char> res = {INT_MAX, '/'};
	for(int i = 1; i <= 200; i++)
		if(vis[i] && i < 90) res = min(res, {dst[i], i});
	cout << res.second << " " << res.first << "\n";
	return 0;
}