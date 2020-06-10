/*
ID: siva.ja1
TASK: milk2
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

int n, arr[1000001];

int main(){
	IO("milk2.in", "milk2.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int beg = INT_MAX, end = 0;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		arr[a]++;
		arr[b]--;
		end = max(end, b);
		beg = min(beg, a);
	}
	int val = 0, cur = 0, idle = 0, mx = 0, mn = 0;
	for(int i = beg; i < end; i++){
		val += arr[i];
		if(val == 0) cur = 0, idle++;
		else cur++, idle = 0;
		mx = max(mx, cur);
		mn = max(mn, idle);
	}
	cout << mx << " " << mn << "\n";
	return 0;
}