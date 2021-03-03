/*
ID: siva.ja1
TASK: fence
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

template<bool D> struct eulerian_path{
	vector<bool> vis;
	vector<pair<int, int>> ans;
	vector<pair<pair<int, int>, int>> ret;
	vector<vector<pair<int, int>>::iterator> its;
	vector<vector<pair<int, int>>> adj;
	void addEdge(int a, int b){
		int m = (int)vis.size();
		vis.push_back(false);
		adj[a].push_back({b, m});
		if(!D) adj[b].push_back({a, m});
	}
	void createSize(int n){
		adj.assign(n + 1, vector<pair<int, int>>());
		its.resize(n + 1); 
	}
	void init(int src){
		for(int i = 1; i < (int)adj.size(); i++){
			sort(adj[i].begin(), adj[i].end());
			its[i] = adj[i].begin();
		}
		vector<pair<pair<int, int>, int>> s = {{{src, -1}, -1}};
		while(!s.empty()){
			int x = s.back().first.first;
			auto &it = its[x], en = adj[x].end();
			while(it != en && vis[it -> second]) it++;
			if(it == en){
				if((int)ret.size() && ret.back().first.second != x) return;
				ret.push_back(s.back()), s.pop_back();
			}else{
				s.push_back({{it -> first, x}, it -> second});
				vis[it -> second] = true;
			}
		}
		if((int)ret.size() != (int)vis.size() + 1) return;
		for(auto &i : ret) ans.push_back({i.first.first, i.second});
		reverse(ans.begin(), ans.end());
	}
};

int m, cnt[501];

int main(){
	IO("fence.in", "fence.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	eulerian_path<false> eul;
	eul.createSize(500);
	cin >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		eul.addEdge(a, b);
		cnt[a]++, cnt[b]++;
	}
	bool cyc = true;
	for(int i = 1; i <= 500; i++)
		if(cnt[i] % 2) cyc = false;
	int mn = INT_MAX;
	if(cyc)
		for(int i = 1; i <= 500; i++){
			if(cnt[i] > 0){
				mn = i;
				break;
			}
		}
	else{
		for(int i = 1; i <= 500; i++)
			if(cnt[i] % 2){
				mn = i;
				break;
			}
	}
	eul.init(mn);
	for(auto &i : eul.ans) cout << i.first << "\n";
	return 0;
}