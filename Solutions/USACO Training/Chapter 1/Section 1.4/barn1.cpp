/*
ID: siva.ja1
TASK: barn1
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

int m, s, c, arr[200];

int main(){
	IO("barn1.in", "barn1.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> s >> c;
	for(int i = 0; i < c; i++) cin >> arr[i];
	sort(arr, arr + c);
	int sum = arr[c - 1] - arr[0] + 1;
	priority_queue<int> st;
	for(int i = 0; i < c - 1; i++) st.push(arr[i + 1] - arr[i] - 1);
	for(int i = 0; i < m - 1 && !st.empty(); i++)
		sum -= st.top(), st.pop();
	cout << sum << "\n";
	return 0;
}