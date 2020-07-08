#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, par[200001], cnt[200001];
vector<int> adj[200001], rpr[200001];
queue<int> que;

void merge(int a, int b){
	a = par[a], b = par[b];
	if(rpr[a].size() < rpr[b].size()) swap(a, b);
	for(auto &i : rpr[b])
		par[i] = a, rpr[a].push_back(i);
	adj[a].insert(adj[a].end(), adj[b].begin(), adj[b].end());
	adj[b].clear();
	if((int)adj[a].size() > 1) que.push(a);
}

int main(){
	IO("fcolor.in", "fcolor.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for(int i = 1; i <= n; i++){
		par[i] = i;
		rpr[i].push_back(i);
		if((int)adj[i].size() > 1) que.push(i);
	}
	while(!que.empty()){
		int vtx = que.front();
		if(adj[vtx].size() <= 1){
			que.pop();
			continue;
		}
		int a = adj[vtx].back();
		adj[vtx].pop_back();
		if(par[a] == par[adj[vtx].back()]) continue;
		merge(a, adj[vtx].back());
	}
	int sum = 0;
	for(int i = 1; i <= n; i++){
		if(!cnt[par[i]]) cnt[par[i]] = ++sum;
		cout << cnt[par[i]] << "\n";
	}
	return 0;
}
