#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

template<class T> struct sparse_table{
	vector<vector<T>> jmp;
	void init(vector<T> &arr){
		int n = (int)arr.size(), on = 1, dpt = 1;
		while(on < (int)arr.size()) on *= 2, dpt++;
		jmp.assign(dpt, arr);
		for(int i = 0; i < dpt - 1; i++)
			for(int j = 0; j < n; j++)
				jmp[i + 1][j] = min(jmp[i][j], jmp[i][min(n - 1, j + (1 << i))]);
	}
	T query(int a, int b){
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct lowest_common_ancestor{
	sparse_table<pair<int, int>> rmq;
	vector<int> hgt, fir;
	vector<pair<int, int>> eul;
	void init(vector<vector<int>> &adj){
		hgt.resize((int)adj.size());
		fir.resize((int)adj.size());
		eul.reserve(2 * (int)adj.size());
		dfs(adj, 1, 1);
		rmq.init(eul);
	}
	void dfs(vector<vector<int>> &adj, int vtx, int pre, int h = 0){
		hgt[vtx] = h;
		fir[vtx] = (int)eul.size();
		eul.push_back({h, vtx});
		for(auto &i : adj[vtx])
			if(i != pre){
				dfs(adj, i, vtx, h + 1);
				eul.push_back({h, vtx});
			}
	}
	int query(int a, int b){
		a = fir[a], b = fir[b];
		if(a > b) swap(a, b);
		return rmq.query(a, b + 1).second;
	}
};

int n, m;
vector<int> col;
vector<tuple<int, int, int>> q;
vector<vector<int>> adj;

vector<int> par;
void getParent(int vtx, int pre){
	par[vtx] = pre;
	for(auto &i : adj[vtx])
		if(i != pre) getParent(i, vtx);
}

vector<vector<int>> que;
map<pair<int, int>, int> ans;
map<int, int> rec;
void solveQueries(int vtx, int pre){
	rec[col[vtx]]++;
	for(auto &i : que[vtx])
		ans[make_pair(vtx, i)] = rec[i];
	for(auto &i : adj[vtx])
		if(i != pre) solveQueries(i, vtx);
	rec[col[vtx]]--;
}

int main(){
	IO("milkvisits.in", "milkvisits.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	adj = vector<vector<int>>(n + 1, vector<int>());
	que = vector<vector<int>>(n + 1, vector<int>());
	par = vector<int>(n + 1);
	col = vector<int>(n + 1);
	for(int i = 1; i <= n; i++) cin >> col[i];
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	getParent(1, 0);
	lowest_common_ancestor lca;
	lca.init(adj);
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(a > b) swap(a, b);
		int tip = lca.query(a, b);
		que[par[tip]].push_back(c);
		if(tip == a) que[b].push_back(c);
		else que[a].push_back(c), que[b].push_back(c);
		q.push_back(make_tuple(a, b, c));
	}
	solveQueries(1, 0);
	for(auto &i : q){
		int a, b, c;
		tie(a, b, c) = i;
		int tip = lca.query(a, b);
		if(a == tip){
			int rem = ans[make_pair(b, c)] - ans[make_pair(par[a], c)]; 
			cout << (rem >= 1);
		}else{
			int rem1 = ans[make_pair(a, c)] - ans[make_pair(par[tip], c)];
			int rem2 = ans[make_pair(b, c)] - ans[make_pair(par[tip], c)];
			cout << (rem1 >= 1 || rem2 >= 1);
		}
	}
	cout << "\n";
	return 0;
}