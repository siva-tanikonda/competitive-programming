/*
ID: siva.ja1
TASK: castle
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

int m, n;
bool vis[2500];
vector<int> adj[2500];

int dfs(int vtx){
	vis[vtx] = true;
	int cnt = 1;
	for(auto &i : adj[vtx])
		if(!vis[i]) cnt += dfs(i);
	return cnt;
}

int main(){
	IO("castle.in", "castle.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			int val;
			cin >> val;
			if(!(val & 1)) adj[i * m + j].push_back(i * m + j - 1);
			if(!(val & 2)) adj[i * m + j].push_back((i - 1) * m + j);
			if(!(val & 4)) adj[i * m + j].push_back(i * m + j + 1);
			if(!(val & 8)) adj[i * m + j].push_back((i + 1) * m + j);
		}
	int cnt = 0, mx = 0;
	tuple<int, int, int, int> tpl(0, 0, 0, 0);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!vis[i * m + j]){
				cnt++;
				mx = max(mx, dfs(i * m + j));
			}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			if(i > 0){
				adj[(i - 1) * m + j].push_back(i * m + j);
				adj[i * m + j].push_back((i - 1) * m + j);
				for(int k = 0; k < n * m; k++) vis[k] = false;
				tpl = max(tpl, {dfs(i * m + j), m - 1 - j, i, 1});
				adj[(i - 1) * m + j].pop_back();
				adj[i * m + j].pop_back();
			}
			if(j < m - 1){
				adj[i * m + j + 1].push_back(i * m + j);
				adj[i * m + j].push_back(i * m + j + 1);
				for(int k = 0; k < n * m; k++) vis[k] = false;
				tpl = max(tpl, {dfs(i * m + j), m - 1 - j, i, 0});
				adj[i * m + j + 1].pop_back();
				adj[i * m + j].pop_back();
			}
		}
	cout << cnt << "\n" << mx << "\n" << get<0>(tpl) << "\n";
	cout << (get<2>(tpl) + 1) << " " << (m - get<1>(tpl)) << " " << (get<3>(tpl) ? "N" : "E") << "\n";
	return 0;
}