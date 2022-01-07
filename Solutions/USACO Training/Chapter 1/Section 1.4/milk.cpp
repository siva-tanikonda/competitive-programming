/*
ID: siva.ja1
TASK: milk
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

int n, m;
pair<int, int> arr[5000];

int main(){
	IO("milk.in", "milk.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < m; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + m);
	int cost = 0;
	for(int i = 0; i < m; i++){
		cost += arr[i].first * min(arr[i].second, n);
		n -= min(arr[i].second, n);
	}
	cout << cost << "\n";
	return 0;
}