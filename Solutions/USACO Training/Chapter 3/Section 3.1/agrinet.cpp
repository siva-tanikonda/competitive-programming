/*
ID: siva.ja1
TASK: agrinet
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const double pi = 3.14159265358979;

struct disjoint_set{
	vector<int> par, sz;
	disjoint_set(int n) : par(n, -1), sz(n, 1) {}
	int find(int vtx) { return (par[vtx] != -1) ? par[vtx] = find(par[vtx]) : vtx; }
	void unite(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		if(sz[b] > sz[a]) swap(a, b);
		par[b] = a;
		sz[a] += sz[b];
	}
};	

int n, adj[100][100];

int main(){
	IO("agrinet.in", "agrinet.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) cin >> adj[i][j];
	disjoint_set ds(n);
	int sum = 0;
	while(true){
		tuple<int, int, int> mn = {INT_MAX, -1, -1};
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				if(adj[i][j] && ds.find(i) != ds.find(j)) mn = min(mn, {adj[i][j], i, j});
		if(get<1>(mn) == -1) break;
		sum += get<0>(mn);
		ds.unite(get<1>(mn), get<2>(mn));
	}
	cout << sum << "\n";
	return 0;
}