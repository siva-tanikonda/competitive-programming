#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int t, a[3];
bool dp[5000001];

int main(){
	IO("feast.in", "feast.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t >> a[1] >> a[2];
	dp[0] = true;
	for(int j = 1; j < 3; j++)
		for(int i = 1; i <= t; i++) dp[i] |= (i >= a[j] && dp[i - a[j]]);
	int mx = 0;
	set<int> op;
	for(int i = 0; i <= t; i++)
		if(dp[i]) mx = i, op.insert(i);
	for(int i = 1; i <= t; i++){
		if(!dp[i]) continue;
		auto it = op.upper_bound(t - i / 2);
		if(it == op.begin()) continue;
		it--;
		mx = max(mx, i / 2 + *it);
	}
	cout << mx << "\n";
	return 0;
}