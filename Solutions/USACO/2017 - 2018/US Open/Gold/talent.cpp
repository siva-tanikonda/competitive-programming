#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, w[251], t[251], dp[1000001];

int main(){
	IO("talent.in", "talent.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> w[i] >> t[i];
	for(int i = 1; i <= 1e6; i++) dp[i] = -1;
	for(int i = 1; i <= n; i++)
		for(int j = 1e6; j >= w[i]; j--)
			if(dp[j - w[i]] != -1) dp[j] = max(dp[j], dp[j - w[i]] + t[i]);
	double ans = 0;
	for(int i = m; i <= 1e6; i++)
		if(dp[i] != -1) ans = max(ans, (double)dp[i] / i);
	cout << floor(ans * 1000) << "\n";
	return 0;
}
