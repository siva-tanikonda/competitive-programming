/*
ID: siva.ja1
TASK: skidesign
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

int n, arr[1000];

int main(){
	IO("skidesign.in", "skidesign.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	int mn = INT_MAX;
	for(int i = 0; i <= 100; i++)
		for(int j = max(0, i - 17); j <= i; j++){
			int sum = 0;
			for(int k = 0; k < n; k++)
				if(arr[k] > i) sum += (arr[k] - i) * (arr[k] - i);
				else if(arr[k] < j) sum += (j - arr[k]) * (j - arr[k]);
			mn = min(mn, sum);
		}
	cout << mn << "\n";
	return 0;
}