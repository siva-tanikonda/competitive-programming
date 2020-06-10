#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

const int mod = 1e9 + 7;
int n, m, k;
long long dp[1000001];

int main(){
	IO("spainting.in", "spainting.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for(int i = 1; i < k; i++) dp[i] = (m * dp[i - 1] + m) % mod;
	for(int i = k; i <= n; i++)
		dp[i] = (m * dp[i - 1] + mod - ((m - 1) * dp[i - k]) % mod) % mod;
	long long res = 1;
	for(int i = 1; i <= n; i++) res = (res * m) % mod;
	cout << (((res - dp[n]) % mod + mod) % mod + dp[n - 1]) % mod << "\n";
	return 0;
}