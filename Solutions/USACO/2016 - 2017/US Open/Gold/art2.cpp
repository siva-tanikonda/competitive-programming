#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, col[100002], xmx[100002], xmn[100002], in[100002];

int main(){
	IO("art2.in", "art2.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	fill(xmn, xmn + n + 2, INT_MAX);
	fill(xmx, xmx + n + 2, INT_MIN);
	col[0] = col[n + 1] = 0;
	for(int i = 0; i <= n + 1; i++){
		if(i >= 1 && i <= n) cin >> col[i];
		xmn[col[i]] = min(xmn[col[i]], i);
		xmx[col[i]] = max(xmx[col[i]], i);
	}
	vector<int> que;
	int ans = 0;
	for(int i = 0; i <= n + 1; i++){
		int ch = col[i];
		if(i == xmn[ch]){
			que.push_back(ch);
			ans = max(ans, (int)que.size());
		}
		if(que.back() != ch){
			cout << "-1\n";
			return 0;
		}
		if(i == xmx[ch]) que.pop_back();
	}
	cout << ans - 1 << "\n";
	return 0;
}
