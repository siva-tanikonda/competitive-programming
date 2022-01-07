#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace __gnu_pbds;
using namespace std;

struct fenwick_tree{
	vector<int> arr;
	fenwick_tree(int n) : arr(n) { }
	void update(int pos, int add){
		for(; pos < (int)arr.size(); pos |= pos + 1)
			arr[pos] += add;
	}
	int query(int pos){
		int res = 0;
		for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
			res += arr[pos];
		return res;
	}
};

int n, ans[100001], pos[100001][2];
pair<int, int> p[100000];
vector<int> eul(1), adj[100001];

int dfs(int vtx){
	pos[vtx][0] = pos[vtx][1] = (int)eul.size();
	eul.push_back(vtx);
	for(int i : adj[vtx])
		pos[vtx][1] = max(pos[vtx][1], dfs(i));
	return pos[vtx][1];
}

int main(){
	IO("promote.in", "promote.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> p[i].first, p[i].second = i + 1;
	for(int i = 2; i <= n; i++){
		int par;
		cin >> par;
		adj[par].push_back(i);
	}
	dfs(1);
	sort(p, p + n + 1, greater<pair<int, int>>());
	fenwick_tree fen((int)eul.size());
	for(int i = 0; i < n; i++){
		int vtx = p[i].second;
		ans[p[i].second] = fen.query(pos[vtx][1]) - fen.query(pos[vtx][0] - 1);
		fen.update(pos[vtx][0], 1);
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
	return 0;
}