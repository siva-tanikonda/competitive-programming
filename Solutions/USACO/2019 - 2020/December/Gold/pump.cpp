#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m;
vector<tuple<int, int, int>> adj[1001];

vector<pair<int, int>> nadj[1001];
int dst[1001];
bool vis[1001];
int checkFlow(int flow){
	for(int i = 1; i <= n; i++)
		dst[i] = INT_MAX, vis[i] = false, nadj[i].clear();
	for(int i = 1; i <= n; i++)
		for(auto &j : adj[i]){
			int b, c, f;
			tie(b, c, f) = j;
			if(f >= flow) nadj[i].push_back(make_pair(b, c));
		}
	priority_queue<pair<int, int>> que;
	dst[1] = 0;
	que.push({0, 1});
	while(!que.empty()){
		int vtx = que.top().second;
		que.pop();
		if(vis[vtx]) continue;
		vis[vtx] = true;
		for(auto &i : nadj[vtx])
			if(dst[i.first] == INT_MAX || dst[i.first] > dst[vtx] + i.second){
				dst[i.first] = dst[vtx] + i.second;
				que.push(make_pair(-dst[i.first], i.first));
			}
	}
	return dst[n];
}

int main(){
	IO("pump.in", "pump.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, c, f;
		cin >> a >> b >> c >> f;
		adj[a].push_back(make_tuple(b, c, f));
		adj[b].push_back(make_tuple(a, c, f));
	}
	double mx = 0;
	for(int i = 1; i <= 1000; i++) mx = max(mx, (double)i / checkFlow(i));
	cout << (int)(mx * 1e6) << "\n";
	return 0;
}