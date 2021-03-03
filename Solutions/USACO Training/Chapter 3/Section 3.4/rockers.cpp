/*
ID: siva.ja1
TASK: rockers
LANG: C++
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

int n, t, m, a[20];

int recurse(int i, int val, int cur, int cnt){
	if(i < n){
		int ans = recurse(i + 1, val, cur, cnt);
		if(cnt == m && cur + a[i] > t) return ans;
		if(a[i] <= t && cur + a[i] > t) ans = max(ans, recurse(i + 1, val + 1, a[i], cnt + 1));
		else if(cur + a[i] <= t) ans = max(ans, recurse(i + 1, val + 1, cur + a[i], cnt));
		return ans;
	}else return val;
}

int main(){
	IO("rockers.in", "rockers.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> t >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << recurse(0, 0, t, 0) << "\n";
	return 0;
}