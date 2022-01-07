#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, in[100001];
vector<int> adj[100001], add[50000];

vector<int> toposort(int x){
	for(int i = 1; i <= n; i++)
		adj[i].clear(), in[i] = 0;
	for(int i = 0; i < x; i++)
		for(int j = 0; j < (int)add[i].size() - 1; j++){
			adj[add[i][j]].push_back(add[i][j + 1]);
			in[add[i][j + 1]]++;
		}
	priority_queue<int, vector<int>, greater<int>> que;
	for(int i = 1; i <= n; i++)
		if(in[i] == 0) que.push(i);
	int cnt = 0;
	vector<int> res;
	while(!que.empty()){
		int vtx = que.top();
		que.pop();
		res.push_back(vtx);
		for(auto &i : adj[vtx]) 
			if(--in[i] == 0) que.push(i);
		cnt++;
	}
	if(cnt != n) return {};
	else return res;
}

int main(){
	IO("milkorder.in", "milkorder.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int k, val;
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> val;
			add[i].push_back(val);
		}
	}
	int l = 0, r = m;
	vector<int> ans;
	while(l < r){
		int mid = l + (r - l + 1) / 2;
		vector<int> arr = toposort(mid);
		if(arr.empty()) r = mid - 1;
		else l = mid, ans = arr;
	}
	for(int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << ((i == n - 1) ? '\n' : ' ');
	return 0;
}
