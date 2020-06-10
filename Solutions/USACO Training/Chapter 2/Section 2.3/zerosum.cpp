/*
ID: siva.ja1
TASK: zerosum
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

int n;

void solve(int i, int sum, string add, string str, vector<string> &res){
	if(i <= n){
		solve(i + 1, sum, add + to_string(i), str + " " + to_string(i), res);
		solve(i + 1, sum + stoi(add), to_string(i), str + "+" + to_string(i), res);
		solve(i + 1, sum + stoi(add), "-" + to_string(i), str + "-" + to_string(i), res);
	}else{
		sum += stoi(add);
		if(sum == 0) res.push_back(str);
	}
}

int main(){
	IO("zerosum.in", "zerosum.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<string> res;
	solve(2, 0, "1", "1", res);
	for(auto &i : res) cout << i << "\n";
	return 0;
}