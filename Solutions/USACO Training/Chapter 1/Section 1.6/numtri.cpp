/*
ID: siva.ja1
TASK: numtri
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

int r, tri[1000][1000], dp[1000][1000];

int main(){
	IO("numtri.in", "numtri.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r;
	for(int i = 0; i < r; i++)
		for(int j = 0; j <= i; j++) cin >> tri[i][j];
	for(int i = 0; i < r; i++) dp[r - 1][i] = tri[r - 1][i];
	for(int i = r - 1; i > 0; i--)
		for(int j = 0; j <= i; j++){
			if(j - 1 >= 0) dp[i - 1][j - 1] = max(dp[i - 1][j - 1], dp[i][j] + tri[i - 1][j - 1]);
			if(j <= r - 1) dp[i - 1][j] = max(dp[i - 1][j], dp[i][j] + tri[i - 1][j]);
		}
	cout << dp[0][0] << "\n";
	return 0;
}