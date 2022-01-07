/*
ID: siva.ja1
TASK: prefix
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

vector<string> prm;
string str;

int main(){
	IO("prefix.in", "prefix.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string cur;
	cin >> cur;
	while(cur != "."){
		prm.push_back(cur);
		cin >> cur;
	}
	while(cin >> cur) str += cur;
	vector<bool> dp((int)str.length() + 1, false);
	dp[0] = true;
	int mx = 0;
	for(int i = 0; i < (int)dp.size(); i++){
		if(!dp[i]) continue;
		for(auto &j : prm){
			bool val = true;
			for(int k = 0; k < (int)j.length(); k++)
				if(i + k >= (int)str.length() || j[k] != str[i + k]) val = false;
			if(val) dp[i + (int)j.length()] = true;
		}
		mx = i;
	}
	cout << mx << "\n";
	return 0;
}