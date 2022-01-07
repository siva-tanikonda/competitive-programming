#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, q, a[5001];
long long dp[5001][5001];

int main(){
	IO("threesum.in", "threesum.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		gp_hash_table<int, int> ump({}, {}, {}, {}, {1 << 13});
		for(int j = i + 1; j <= n; j++){
			int dif = -(a[i] + a[j]);
			auto it = ump.find(dif);
			if(it != ump.end()) dp[i][j] = it -> second;
			ump[a[j]]++;
		}
	}
	for(int i = n; i >= 1; i--)
		for(int j = i + 1; j <= n; j++)
			dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
	for(int i = 0; i < q; i++){
		int x, y;
		cin >> x >> y;
		cout << dp[x][y] << "\n";
	}
	return 0;
}
