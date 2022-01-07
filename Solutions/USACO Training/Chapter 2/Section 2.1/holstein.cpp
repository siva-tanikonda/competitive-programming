/*
ID: siva.ja1
TASK: holstein
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

int v, g, a[25], b[15][25];

void recurse(int cur, vector<int> &inc, vector<int> &rec, vector<int> &res){
	if(cur < g){
		inc.push_back(cur + 1);
		for(int i = 0; i < v; i++) rec[i] += b[cur][i];
		recurse(cur + 1, inc, rec, res);
		for(int i = 0; i < v; i++) rec[i] -= b[cur][i];
		inc.pop_back();
		recurse(cur + 1, inc, rec, res);
	}else{
		bool val = true;
		for(int i = 0; i < v; i++)
			if(rec[i] < a[i]) val = false;
		if(!val) return;
		if(res.empty() || inc.size() < res.size() || inc < res) res = inc;
	}
}

int main(){
	IO("holstein.in", "holstein.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v;
	for(int i = 0; i < v; i++) cin >> a[i];
	cin >> g;
	for(int i = 0; i < g; i++)
		for(int j = 0; j < v; j++) cin >> b[i][j];
	vector<int> res, inc, rec(v);
	recurse(0, inc, rec, res);
	cout << res.size();
	for(auto &i : res) cout << " " << i;
	cout << "\n";
	return 0;
}