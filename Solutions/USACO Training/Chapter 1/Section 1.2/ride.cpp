/*
ID: siva.ja1
TASK: ride
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

string a, b;

int main(){
	IO("ride.in", "ride.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	int pr1 = 1, pr2 = 1;
	for(auto &i : a) pr1 *= i - 'A' + 1;
	for(auto &i : b) pr2 *= i - 'A' + 1;
	if(pr1 % 47 == pr2 % 47) cout << "GO\n";
	else cout << "STAY\n";
	return 0;
}