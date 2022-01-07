/*
ID: siva.ja1
TASK: stall4
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

struct dinic{
	vector<tuple<int, int, long long, long long>> edg;
	vector<vector<int>> adj;
	vector<int> lvl, ptr;
	queue<int> que;
	int m = 0;
	void init(int n){
		adj.resize(n + 1), lvl.resize(n + 1);
		ptr.resize(n + 1);
	}
	void addEdge(int a, int b, int c){
		edg.push_back({a, b, c, 0});
		edg.push_back({b, a, 0, 0});
		adj[a].push_back(m++);
		adj[b].push_back(m++);
	}
	bool bfs(int snk){
		while(!que.empty()){
			int vtx = que.front();
			que.pop();
			for(int i : adj[vtx]){
				if(get<2>(edg[i]) - get<3>(edg[i]) < 1) continue;
				if(lvl[get<1>(edg[i])] != -1) continue;
				lvl[get<1>(edg[i])] = lvl[vtx] + 1;
				que.push(get<1>(edg[i]));
			}
		}
		return lvl[snk] != -1;
	}
	int dfs(int snk, int vtx, long long psh){
		if(!psh) return 0;
		if(vtx == snk) return psh;
		for(int &i = ptr[vtx]; i < (int)adj[vtx].size(); i++){
			int id = adj[vtx][i], u = get<1>(edg[id]);
			if(lvl[vtx] + 1 != lvl[u] || get<2>(edg[id]) - get<3>(edg[id]) < 1)
				continue;
			long long tr = dfs(snk, u, min(psh, get<2>(edg[id]) - get<3>(edg[id])));
			if(!tr) continue;
			get<3>(edg[id]) += tr;
			get<3>(edg[id ^ 1]) -= tr;
			return tr;
		}
		return 0;
	}
	long long getFlow(int src, int snk){
		long long ret = 0;
		while(true){
			fill(lvl.begin(), lvl.end(), -1);
			lvl[src] = 0;
			que.push(src);
			if(!bfs(snk)) break;
			fill(ptr.begin(), ptr.end(), 0);
			while(long long psh = dfs(snk, src, LLONG_MAX))
				ret += psh;
		}
		return ret;
	}
};

int n, m;
bool cow[201][201];

int main(){
	IO("stall4.in", "stall4.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dinic flw;
	flw.init(n + m + 1);
	for(int i = 1; i <= n; i++){
		int cnt;
		cin >> cnt;
		for(int j = 0; j < cnt; j++){
			int val;
			cin >> val;
			flw.addEdge(i, n + val, 1);
		}
	}
	for(int i = 1; i <= n; i++) flw.addEdge(0, i, 1);
	for(int i = 1; i <= m; i++) flw.addEdge(n + i, n + m + 1, 1);
	cout << flw.getFlow(0, n + m + 1) << "\n";
	return 0;
}