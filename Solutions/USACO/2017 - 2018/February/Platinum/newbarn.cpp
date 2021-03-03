#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace __gnu_pbds;
using namespace std;

int q, sub[100001], dst[32][100001], dep[100001], pre[100001];
set<pair<int, int>, greater<pair<int, int>>> ops[100001];
map<int, int> chs[100001];
vector<int> adj[100001];
bool vis[100001];

int dfs(int vtx, int pre = 0){
	sub[vtx] = 1;
	for(int i : adj[vtx])
		if(i != pre && !vis[i])
			sub[vtx] += dfs(i, vtx);
	return sub[vtx];
}

int centroid(int vtx, int sz, int pre = 0){
	for(int i : adj[vtx])
		if(i != pre && !vis[i] && sub[i] * 2 > sz)
			return centroid(i, sz, vtx);
	return vtx;
}

void distance(int vtx, int dp, int pre = 0){
	for(int i : adj[vtx])
		if(i != pre && !vis[i]){
			dst[dp][i] = dst[dp][vtx] + 1;
			distance(i, dp, vtx);
		}
}

void decompose(int vtx, int dp = 0, int par = 0){
	vtx = centroid(vtx, dfs(vtx));
	distance(vtx, dp), pre[vtx] = par;
	vis[vtx] = true, dep[vtx] = dp;
	for(int i : adj[vtx])
		if(!vis[i]) decompose(i, dp + 1, vtx);
}

void update(int vtx){
	int cur = pre[vtx], par = vtx;
	ops[vtx].insert({0, 0});
	while(cur){
		int dp = dep[cur];
		if(chs[cur][par] < dst[dp][vtx]){
			ops[cur].erase({chs[cur][par], par});
			chs[cur][par] = dst[dp][vtx];
			ops[cur].insert({chs[cur][par], par});
		}
		par = cur, cur = pre[cur];
	}
}

int query(int vtx){
	int cur = pre[vtx], par = vtx;
	int res = ops[vtx].begin() -> first;
	while(cur){
		int dp = dep[cur];
		if(ops[cur].empty())
			par = cur, cur = pre[cur];
		else{
			auto it = ops[cur].begin();
			if(it -> second == par) it++;
			if(it == ops[cur].end())
				par = cur, cur = pre[cur];
			else{
				res = max(res, dst[dp][vtx] + it -> first);
				par = cur, cur = pre[cur];
			}
		}
	}
	return res;
}

int main(){
	IO("newbarn.in", "newbarn.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> q;
	map<int, vector<int>> que;
	int n = 0;
	for(int i = 0; i < q; i++){
		char typ;
		int vtx;
		cin >> typ >> vtx;
		if(typ == 'B'){
			n++;
			if(vtx != -1){
				adj[vtx].push_back(n);
				adj[n].push_back(vtx);
			}
		}else if(typ == 'Q')
			que[n].push_back(vtx);
	}
	for(int i = 1; i <= n; i++)
		if(!vis[i]) decompose(i);
	for(int i = 1; i <= n; i++){
		update(i);
		for(int j : que[i])
			cout << query(j) << '\n';
	}
	return 0;
}