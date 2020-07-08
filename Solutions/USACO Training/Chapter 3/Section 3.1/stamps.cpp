/*
ID: siva.ja1
TASK: stamps
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, a[51], dp[2000001];

int main(){
	IO("stamps.in", "stamps.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= 2000000; i++) dp[i] = -1;
	for(int i = 1; i <= m; i++)
		for(int j = a[i]; j <= 2000000; j++)
			if(dp[j - a[i]] != -1 && (dp[j] == -1 || dp[j] > dp[j - a[i]] + 1))
				dp[j] = dp[j - a[i]] + 1;
	for(int i = 1; i <= 2000000; i++)
		if(dp[i] == -1 || dp[i] > n){
			cout << i - 1 << "\n";
			return 0;
		}
	cout << "2000000\n";
	return 0;
}
