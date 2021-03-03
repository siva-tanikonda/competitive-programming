/*
ID: siva.ja1
TASK: job
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, m1, m2, dur[60];
int ab[30];

int main(){
	IO("job.in", "job.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m1 >> m2;
	for(int i = 0; i < m1 + m2; i++) cin >> dur[i];
	vector<int> out;
	for(int i = 0; i < n; i++){
		pair<int, int> best = {INT_MAX, -1};
		for(int j = 0; j < m1; j++)
			best = min(best, {ab[j] + dur[j], j});
		ab[best.second] += dur[best.second];
		out.push_back(ab[best.second]);
	}
	pair<int, int> ans;
	for(int i = 0; i < m1; i++)
		ans.first = max(ans.first, ab[i]);
	vector<int> ops;
	for(int i = 0; i < m2; i++)
		for(int j = dur[m1 + i]; j <= 2e4; j += dur[m1 + i])
			ops.push_back(j);
	sort(ops.begin(), ops.end());
	sort(out.begin(), out.end());
	for(int i = 0; i < n; i++)
		ans.second = max(ans.second, out[i] + ops[n - 1 - i]);
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}