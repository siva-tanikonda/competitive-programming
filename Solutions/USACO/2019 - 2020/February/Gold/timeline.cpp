#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, c, s[100001], in[100001];
vector<pair<int, int>> adj[100001];

int main(){
	IO("timeline.in", "timeline.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> c;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 0; i < c; i++){
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({y, z});
		in[y]++;
	}
	queue<int> que;
	for(int i = 1; i <= n; i++)
		if(!in[i]) que.push(i);
	vector<int> top;
	while(!que.empty()){
		int vtx = que.front();
		que.pop();
		top.push_back(vtx);
		for(auto &i : adj[vtx])
			if(--in[i.first] == 0) que.push(i.first);
	}
	for(int i = 0; i < n; i++)
		for(auto &j : adj[top[i]])
			s[j.first] = max(s[j.first], s[top[i]] + j.second);
	for(int i = 1; i <= n; i++) cout << s[i] << "\n";
	return 0;
}
