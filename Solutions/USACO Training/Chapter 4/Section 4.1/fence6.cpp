/*
ID: siva.ja1
TASK: fence6
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, dst[102];
map<vector<int>, vector<pair<vector<int>, int>>> tdj;
map<vector<int>, int> con;
vector<pair<int, int>> adj[102];
bool vis[102];

int main(){
	IO("fence6.in", "fence6.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		int id, l, n1, n2;
		cin >> id >> l >> n1 >> n2;
		vector<int> a1 = {id}, a2 = {id};
		for(int j = 0; j < n1; j++){
			int val;
			cin >> val;
			a1.push_back(val);
		}
		for(int j = 0; j < n2; j++){
			int val;
			cin >> val;
			a2.push_back(val);
		}
		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end());
		tdj[a1].push_back({a2, l});
		tdj[a2].push_back({a1, l});
	}
	int cur = 0;
	for(auto &i : tdj) con[i.first] = ++cur;
	for(auto &i : tdj)
		for(auto &j : i.second)
			adj[con[i.first]].push_back({con[j.first], j.second});
	int ans = INT_MAX;
	for(int i = 1; i <= cur; i++){
		fill(dst + 1, dst + cur + 1, 1e9);
		fill(vis + 1, vis + cur + 1, false);
		priority_queue<tuple<int, int, int>> que;
		dst[i] = 0;
		que.push({0, i, 0});
		while(!que.empty()){
			int a, b, c;
			tie(c, a, b) = que.top();
			que.pop();
			if(vis[a]) continue;
			vis[a] = true;
			for(auto &j : adj[a])
				if(j.first != b){
					if(vis[j.first])
						ans = min(ans, dst[a] + dst[j.first] + j.second);
					else if(dst[j.first] > dst[a] + j.second){
						dst[j.first] = dst[a] + j.second;
						que.push({-dst[j.first], j.first, a});
					}
				}
		}
	}
	cout << ans << "\n";
	return 0;
}