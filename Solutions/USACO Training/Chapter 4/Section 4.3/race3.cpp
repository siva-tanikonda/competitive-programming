/*
ID: siva.ja1
TASK: race3
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

vector<int> adj[50];
bool vis[50], pos[50];

void dfs(int vtx, int no){
	vis[vtx] = true;
	for(int i : adj[vtx])
		if(!vis[i] && i != no) dfs(i, no);
}

int main(){
	IO("race3.in", "race3.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	for(; n < 50; n++){
		int val;
		while(cin >> val && val >= 0)
			adj[n].push_back(val);
		if(val == -1) break;
	}
	vector<int> ans;
	for(int i = 1; i < n - 1; i++){
		fill(vis, vis + n, false);
		dfs(0, i);
		if(!vis[n - 1])
			pos[i] = true, ans.push_back(i);
	}
	cout << ans.size();
	for(int i : ans) cout << " " << i;
	ans.clear();
	for(int i = 0; i < n; i++){
		fill(vis, vis + n, false);
		dfs(0, i);
		vector<int> a, b;
		int ca = 1, cb = 0;
		for(int j = 0; j < n; j++)
			if(vis[j]) ca++, a.push_back(j);
		fill(vis, vis + n, false);
		dfs(i, -1);
		for(int j = 0; j < n; j++)
			if(vis[j]) cb++, b.push_back(j);
		bool work = true;
		for(int j : a)
			for(int k : b)
				if(j == k) work = false;
		if(work && ca > 1 && cb > 1) ans.push_back(i);
	}
	cout << "\n" << ans.size();
	for(int i : ans) cout << " " << i;
	cout << "\n";
	return 0;
}