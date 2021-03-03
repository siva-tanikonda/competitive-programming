#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

int n, m;
long long a[1001], cpy[2000], pre[2001][2001], dp[8][1001];

void recurse(int rl, int rr, int l, int r, int idx, int rot){
	if(rl > rr) return;
	int mid = rl + (rr - rl) / 2;
	pair<long long, int> mn(1e12, 1001);
	for(int i = l; i <= min(r, mid); i++){
		long long dst = pre[i + rot][mid + rot];
		mn = min(mn, make_pair(dp[idx - 1][i - 1] + dst, i));
	}
	dp[idx][mid] = mn.first;
	recurse(rl, mid - 1, l, mn.second, idx, rot);
	recurse(mid + 1, rr, mn.second, r, idx, rot);
}

int main(){
	IO("cbarn.in", "cbarn.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cpy[i] = cpy[i + n] = a[i];
	}
	for(int i = 1; i <= 2 * n; i++)
		for(int j = i; j <= 2 * n; j++)
			pre[i][j] = pre[i][j - 1] + cpy[j] * (j - i);
	long long ans = LLONG_MAX;
	for(int i = 1; i <= n; i++) dp[0][i] = 1e12;
	for(int k = 1; k <= n; k++){
		rotate(a + 1, a + 2, a + n + 1);
		for(int i = 1; i <= m; i++)
			recurse(i, n, i, n, i, k % n);
		ans = min(ans, dp[m][n]);
	}
	cout << ans << '\n';
	return 0;
}