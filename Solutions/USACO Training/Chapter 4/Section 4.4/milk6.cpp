/*
ID: siva.ja1
TASK: milk6
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

struct dinic{
	vector<int> lvl, ptr;
	vector<vector<tuple<int, double, double, int, int>>> adj;
	void init(int n){
		lvl.resize(n + 1), ptr.resize(n + 1);
		adj.resize(n + 1);
	}
	void addEdge(int a, int b, double c, int idx){
		adj[a].push_back({b, 0, c, (int)adj[b].size(), idx});
		adj[b].push_back({a, 0, 0, (int)adj[a].size(), -idx});
	}
	bool bfs(int src, int snk){
		fill(lvl.begin(), lvl.end(), -1);
		queue<int> que;
		lvl[src] = 0, que.push(src);
		while(!que.empty()){
			int vtx = que.front();
			que.pop();
			for(auto &i : adj[vtx])
				if(lvl[get<0>(i)] < 0 && get<1>(i) < get<2>(i)){
					lvl[get<0>(i)] = lvl[vtx] + 1;
					que.push(get<0>(i));
				}
		}
		return lvl[snk] >= 0;
	}
	double dfs(int vtx, double flw, int snk){
		if(vtx == snk) return flw;
		for(; ptr[vtx] < (int)adj[vtx].size(); ptr[vtx]++){
			tuple<int, double, double, int, int> &edg = adj[vtx][ptr[vtx]];
			if(lvl[get<0>(edg)] == lvl[vtx] + 1 && get<1>(edg) < get<2>(edg)){
				double cur = min(flw, get<2>(edg) - get<1>(edg));
				double temp = dfs(get<0>(edg), cur, snk);
				if(temp > 0){
					get<1>(edg) += temp;
					get<1>(adj[get<0>(edg)][get<3>(edg)]) -= temp;
					return temp;
				}
			}
		}
		return 0;
	}
	pair<double, vector<int>> getFlow(int src, int snk){
		if(src == snk) return {-1, {}};
		double sum = 0;
		while(bfs(src, snk)){
			fill(ptr.begin(), ptr.end(), 0);
			while(double flw = dfs(src, LLONG_MAX, snk))
				sum += flw;
		}
		bfs(src, snk);
		vector<int> seq;
		for(int i = 1; i < (int)lvl.size(); i++)
			if(lvl[i] != -1)
				for(auto &j : adj[i])
					if(get<4>(j) > 0 && lvl[get<0>(j)] == -1)
						seq.push_back(get<4>(j));
		return {sum, seq};
	}
};

int n, m;

int main(){
	IO("milk6.in", "milk6.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dinic flw;
	flw.init(n);
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		flw.addEdge(a, b, 1001 * c + 1 + 1 / pow(2, m + 1 - i), i + 1);
	}
	pair<double, vector<int>> ans = flw.getFlow(1, n);
	sort(ans.second.begin(), ans.second.end());
	cout << (long long)ans.first / 1001 << ' ' << (long long)ans.first % 1001 << '\n';
	for(int i : ans.second) cout << i << '\n';
	return 0;
}