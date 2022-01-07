/*
ID: siva.ja1
TASK: combo
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

int n, arr[2][3];

bool valid(int x, vector<int> num){
	bool val = true;
	for(int i = 0; i < 3; i++)
		val &= min(abs(arr[x][i] - num[i]), n - abs(arr[x][i] - num[i])) <= 2;
	return val;
}

int main(){
	IO("combo.in", "combo.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 3; j++) cin >> arr[i][j];
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				cnt += valid(1, {i, j, k}) || valid(0, {i, j, k});
	cout << cnt << "\n";
	return 0;
}