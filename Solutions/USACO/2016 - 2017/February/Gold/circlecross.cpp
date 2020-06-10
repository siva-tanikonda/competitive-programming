#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

template<class T>
struct fenwick_tree{
	vector<T> pre;
	fenwick_tree(int _n) : pre(_n) {}
	fenwick_tree(vector<T> &arr) : pre((int)arr.size()) {
		for(int i = 0; i < (int)arr.size(); i++) update(i, arr[i]);
	}
	void update(int pos, T dif){
		for(; pos < (int)pre.size(); pos |= pos + 1) pre[pos] += dif;
	}
	long long query(int pos){
		T sum = 0;
		for(; pos >= 0; pos = (pos & (pos + 1)) - 1) sum += pre[pos];
		return sum;
	}
};

int n;
pair<int, int> arr[50001];

int main(){
	IO("circlecross.in", "circlecross.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= 2 * n; i++){
		int idx;
		cin >> idx;
		if(arr[idx].first == 0) arr[idx].first = i;
		else arr[idx].second = i;
	}
	sort(arr, arr + n + 1);
	fenwick_tree<int> ft(2 * n + 1);
	int res = 0;
	for(int i = 1; i <= n; i++){
		res += ft.query(arr[i].second) - ft.query(arr[i].first);
		ft.update(arr[i].second, 1);
	}
	cout << res << "\n";
	return 0;
}