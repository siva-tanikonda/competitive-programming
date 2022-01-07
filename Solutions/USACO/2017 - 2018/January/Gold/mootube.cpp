#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

struct union_find{
	vector<int> par;
	void init(int n) { par = vector<int>(n + 1, -1); }
	int find(int x) { return (par[x] < 0) ? x : par[x] = find(par[x]); }
	int size(int x) { return -par[find(x)]; }
	void merge(int a, int b){
		a = find(a), b = find(b);
		if(size(a) > size(b)) swap(a, b);
		par[a] += par[b], par[b] = a;
	}
};

int n, q, ans[100000];
map<int, pair<vector<pair<int, int>>, vector<pair<int, int>>>> edg;

int main(){
	IO("mootube.in", "mootube.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for(int i = 0; i < n - 1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edg[c].first.push_back(make_pair(a, b));
	}
	for(int i = 0; i < q; i++){
		int k, v;
		cin >> k >> v;
		auto it = edg.lower_bound(k);
		if(it == edg.end()) ans[i] = 0;
		else{
			edg[it -> first].second.push_back(make_pair(v, i));
		}
	}
	union_find rec;
	rec.init(n);
	for(auto i = edg.rbegin(); i != edg.rend(); i++){
		for(auto &j : (i -> second).first) rec.merge(j.first, j.second);
		for(auto &j : (i -> second).second) ans[j.second] = rec.size(j.first) - 1;
	}
	for(int i = 0; i < q; i++) cout << ans[i] << "\n";
	return 0;
}