/*
ID: siva.ja1
TASK: concom
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
vector<pair<int, int>> adj[101];

int main(){
	IO("concom.in", "concom.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	vector<pair<int, bool>> vis(101, {0, false});
	vector<pair<int, int>> con;
	for(int i = 1; i <= 100; i++){
		vis.assign(101, {0, false});
		vis[i] = {100, false};
		while(true){
			int vtx = -1;
			for(int j = 1; j <= 100; j++)
				if(vis[j].first >= 50 && !vis[j].second) vtx = j;
			if(vtx == -1) break;
			vis[vtx].second = true;
			for(auto &j : adj[vtx]) vis[j.first].first += j.second;
		}
		for(int j = 1; j <= 100; j++)
			if(j != i && vis[j].first >= 50) con.push_back({i, j});
	}
	sort(con.begin(), con.end());
	for(auto &i : con) cout << i.first << " " << i.second << "\n";
	return 0;
}