/*
ID: siva.ja1
TASK: gift1
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

int n;
pair<string, int> res[10];

int main(){
	IO("gift1.in", "gift1.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		string name;
		cin >> name;
		res[i] = {name, 0};
	}
	for(int i = 0; i < n; i++){
		string name;
		int bal, rec;
		cin >> name >> bal >> rec;
		for(int j = 0; j < rec; j++){
			string opp;
			cin >> opp;
			for(int k = 0; k < n; k++)
				if(res[k].first == opp) res[k].second += bal / rec;
		}
		for(int j = 0; j < n; j++)
			if(res[j].first == name && rec > 0) res[j].second -= bal - bal % rec;
	}
	for(int i = 0; i < n; i++) cout << res[i].first << " " << res[i].second << "\n";
	return 0;
}