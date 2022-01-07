/*
ID: siva.ja1
TASK: humble
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m, s[100];
vector<int> ans;

int main(){
	IO("humble.in", "humble.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> s[i];
	vector<int> ops;
	ops.push_back(1);
	int mx = 2;
	for(int i = 0; i < m; i++){
		int abv = INT_MAX;
		for(int j = 0; j < n; j++){
			int mn;
			if(mx % s[j]) mn = mx - (mx % s[j]) + s[j];
			else mn = mx;
			auto it = lower_bound(ops.begin(), ops.end(), mn / s[j]);
			abv = min(abv, s[j] * (*it));
		}
		ops.push_back(abv);
		mx = abv + 1;
	}
	cout << mx - 1 << "\n";
	return 0;
}
