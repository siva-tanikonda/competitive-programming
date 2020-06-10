#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, arr[10001], dp[10001];

int main(){
	IO("teamwork.in", "teamwork.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	for(int i = 1; i <= n; i++){
		int mx = 0;
		for(int j = i - 1; j >= i - m && j >= 0; j--)
			mx = max(mx, arr[j + 1]), dp[i] = max(dp[i], mx * (i - j) + dp[j]);
	}
	cout << dp[n] << "\n";
	return 0;
}