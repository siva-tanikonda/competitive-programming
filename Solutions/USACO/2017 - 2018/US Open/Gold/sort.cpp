#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;
using namespace __gnu_pbds;

struct fenwick_tree{
	vector<int> arr;
	void init(int n) { arr = vector<int>(n + 1, 0); }
	void update(int i, int add) {
		for(; i < (int)arr.size(); i += (i & -i)) arr[i] += add;
	}
	int query(int i){
		int sum = 0;
		for(; i > 0; i -= (i & -i)) sum += arr[i];
		return sum;
	}
};

int n;
pair<int, int> a[100001];

int main(){
	IO("sort.in", "sort.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].first, a[i].second = i;
	sort(a, a + n + 1);
	fenwick_tree dif;
	dif.init(n + 1);
	int ans = 1;
	for(int i = 1; i < n; i++){
		dif.update(a[i].second, 1);
		ans = max(ans, i - dif.query(i));
	}
	cout << ans << "\n";
	return 0;
}
