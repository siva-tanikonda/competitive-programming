#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

template<class T> struct sparse_table{
	vector<vector<T>> jmp;
	void init(vector<T> &arr){
		int n = (int)arr.size(), dpt = 32 - __builtin_clz(n);
		jmp.assign(dpt, arr);
		for(int i = 0; i < dpt - 1; i++)
			for(int j = 0; j < n; j++)
				jmp[i + 1][j] = max(jmp[i][j], jmp[i][min(n - 1, j + (1 << i))]);
	}
	T query(int a, int b){
		int dep = 31 - __builtin_clz(b - a + 1);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep) + 1]);
	}
};

int n, m, a[401], dp[400][401], pre[401];

int main(){
	IO("snakes.in", "snakes.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> arr;
	for(int i = 0; i <= n; i++) arr.push_back(a[i]);
	sparse_table<int> rmq;
	rmq.init(arr);
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i];
		dp[0][i] = rmq.query(1, i) * i - pre[i];
	}
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++){
			dp[i][j] = dp[i - 1][j];
			for(int k = 0; k < j; k++){
				int dif = rmq.query(k + 1, j) * (j - k) - (pre[j] - pre[k]);
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + dif);
			}
		}
	cout << dp[m][n] << "\n";
	return 0;
}
