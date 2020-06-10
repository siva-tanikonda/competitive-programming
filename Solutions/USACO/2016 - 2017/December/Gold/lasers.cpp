#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n, vis[100002];
pair<int, int> crd[100002];
map<int, set<tuple<int, int, int>>> x, y;

int main(){
	IO("lasers.in", "lasers.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n + 2; i++){
		int a, b;
		cin >> a >> b;
		crd[i] = {a, b};
		x[a].insert(make_tuple(a, b, i));
		y[b].insert(make_tuple(a, b, i));
	}
	queue<pair<int, int>> que;
	que.push({0, 0});
	vis[0] = 0;
	while(!que.empty()){
		int dst = que.front().second, vtx = que.front().first;
		que.pop();
		set<int> rem;
		for(auto &i : x[crd[vtx].first]){
			int a, b, c;
			tie(a, b, c) = i;
			if(!vis[c]){
				vis[c] = dst + 1;
				que.push({c, vis[c]});
				rem.insert(c);
			}
		}
		for(auto &i : y[crd[vtx].second]){
			int a, b, c;
			tie(a, b, c) = i;
			if(!vis[c]){
				vis[c] = dst + 1;
				que.push({c, vis[c]});
				rem.insert(c);
			}
		}
		for(auto &i : rem){
			x[crd[i].first].erase(make_tuple(crd[i].first, crd[i].second, i));
			y[crd[i].second].erase(make_tuple(crd[i].first, crd[i].second, i));
		}
	}
	cout << vis[1] - 1 << "\n";
	return 0;
}