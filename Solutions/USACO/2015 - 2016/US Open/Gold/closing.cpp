#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

struct union_find{
	vector<int> par;
	union_find(int _n) : par(_n + 1, -1) {}
	bool same_set(int a, int b){ return find(a) == find(b); }
	int find(int x){
		return par[x] < 0 ? x : par[x] = find(par[x]);
	}
	void unite(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		if(par[a] > par[b]) swap(a, b);
		par[a] += par[b], par[b] = a;
	}
};

int n, m, ord[200001];
pair<int, int> edg[200001];
vector<int> adj[200001];
string res[200001];

int main(){
	IO("closing.in", "closing.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < m; i++) cin >> edg[i].first >> edg[i].second;
	for(int i = 0; i < n; i++){
		int vtx;
		cin >> vtx;
		ord[vtx] = i;
	}
	for(int i = 0; i < m; i++)
		if(ord[edg[i].first] < ord[edg[i].second]) adj[edg[i].first].push_back(edg[i].second);
		else adj[edg[i].second].push_back(edg[i].first);
	union_find uf(n);
	set<pair<int, int>, greater<pair<int, int>>> proc;
	for(int i = 1; i <= n; i++) proc.insert({ord[i], i});
	int sts = 0;
	for(auto &i : proc){
		sts++;
		for(auto &j : adj[i.second])
			if(uf.find(i.second) != uf.find(j))
				sts--, uf.unite(i.second, j);
		res[i.first] = (sts == 1) ? "YES\n" : "NO\n";
	}
	for(int i = 0; i < n; i++) cout << res[i];
	return 0;
}