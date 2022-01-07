#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

struct fenwick_tree{
	vector<int> arr;
	void init(int n) { arr = vector<int>(n); }
	void update(int idx, int val){
		for(; idx < (int)arr.size(); idx |= idx + 1)
			arr[idx] += val;
	}
	int query(int idx){
		int sum = 0;
		for(; idx >= 0; idx &= idx + 1, idx--)
			sum += arr[idx];
		return sum;
	}
};

bool cov[100001];
int n, a[50000], dp[50002][2];
pair<int, int> b[50001];
fenwick_tree fen;

int getUpper(int val, bool grt){
	int l = 1, r = n;
	while(l < r){
		int mid = l + (r - l + 1) / 2;
		if((grt && a[fen.query(mid)] > val) || (!grt && a[fen.query(mid)] < val))
			l = mid;
		else r = mid - 1;
	}
	return l;
}

int main(){
	IO("cardgame.in", "cardgame.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> b[i].first;
		b[i].second = i;
		cov[b[i].first] = true;
	}
	int k = 0;
	for(int i = 2 * n; i > 0; i--)
		if(!cov[i]) a[k++] = i;
	sort(b + 1, b + n + 1, greater<pair<int, int>>());
	fen.init(n + 1);
	for(int i = 1; i <= n; i++){
		if(b[i].first > a[0]) continue;
		int up = getUpper(b[i].first, true);
		if(up < b[i].second) continue;
		fen.update(up + 1, -1);
		fen.update(b[i].second, 1);
	}
	for(int i = 1; i <= n; i++)
		dp[i][0] = fen.query(i);
	sort(b + 1, b + n + 1);
	sort(a, a + n);
	fen.init(n + 1);
	for(int i = 1; i <= n; i++){
		if(b[i].first < a[0]) continue; 
		b[i].second = n - b[i].second + 1;
		int up = getUpper(b[i].first, false);
		if(up < b[i].second) continue;
		fen.update(up + 1, -1);
		fen.update(b[i].second, 1);
	}
	for(int i = n; i > 0; i--)
		dp[i][1] = fen.query(n - i + 1);
	int ans = 0;
	for(int i = 0; i <= n; i++)
		ans = max(ans, dp[i][0] + dp[i + 1][1]);
	cout << ans << '\n';
	return 0;
}