/*
ID: siva.ja1
TASK: hamming
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

int n, b, d;

int main(){
	IO("hamming.in", "hamming.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> b >> d;
	vector<int> res = {};
	for(int i = 0; i <= (1 << (b + 1)) - 1 && n > 0; i++){
		bool val = true;
		for(auto &j : res)
			if(__builtin_popcount(i ^ j) < d) val = false;
		if(val) res.push_back(i), n--;
	}
	int cnt = 0;
	for(auto &i : res){
		if(cnt == 0) cout << i;
		else if(cnt % 10 == 0) cout << "\n" << i;
		else cout << " " << i;
		cnt++;
	}
	cout << "\n";
	return 0;
}